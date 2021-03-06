Game = class('Game')

function Game:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 2000, line_width = 8})

    self.intro_text_alpha = 0
    self.people_left_alpha = 0
    self.game_drain_alpha = 0
    timer:after(4, function()
        timer:tween(2, self, {intro_text_alpha = 255}, 'in-out-cubic')
        timer:tween(2, self, {people_left_alpha = 255}, 'in-out-cubic')
        timer:after(20, function()
            timer:tween(2, self, {intro_text_alpha = 0}, 'in-out-cubic')
        end)
    end)

    self.active_line = ActiveLine(0, 0)
    self.people = {}
    self.resources = {}
    self.connect_lines = {}
    self.drains = {}
    self.cities = {}
    table.insert(self.resources, Resource(game_width/2, game_height/2, {size = 120}))

    self:spawnResources(math.random(24, 32))
    self:spawnPeople(math.random(30, 35))

    self.end_game = false
    self.alive_min = 14
    timer:every(20, function() self.alive_min = self.alive_min + 1 end)
    self.timer_lost_tid = timer:tween(300, self, {game_drain_alpha = 232}, 'linear')
    timer:after(300, function() timerLost() end)
    timer:tween(300, pitches, {heart_pitch = 1.3}, 'linear')
    timer:tween(300, pitches, {base_pitch = 2}, 'linear')
end

function Game:update(dt)
    camera:zoomTo(camerat.zoom)
    local x, y = camera:pos()
    if love.mouse.isDown('r') then
        local mouse_d = Vector(mouse.x - game_width/2, mouse.y - game_height/2)
        camerat.a = mouse_d
    else camerat.a = Vector(0, 0) end
    camerat.v = camerat.v + camerat.a*dt
    camera:move(camerat.v.x*camerat.v_multiplier, camerat.v.y*camerat.v_multiplier)
    camerat.v = camerat.v*camerat.damping

    if self.people then
        if not self.end_game then
            if #self.people - self.alive_min < 0 then self.end_game = true; lostGame() end
            if #self.people >= 40 then self.end_game = true; wonGame() end
        end
    end
    
    self.planet:update(dt)
    self.active_line:update(dt)
    local mouse_color = false
    for _, person in ipairs(self.people) do 
        person:update(dt) 
        if mouseCollidingPerson(person) then mouse_color = true end
    end
    for _, resource in ipairs(self.resources) do 
        resource:update(dt) 
        if mouseCollidingResource(resource) then mouse_color = true end
    end
    for _, connect_line in ipairs(self.connect_lines) do 
        connect_line:update(dt) 
    end
    for _, drain in ipairs(self.drains) do drain:update(dt) end
    for _, city in ipairs(self.cities) do city:update(dt) end
    if mouse_color then mouse.color = {64, 96, 232}
    else
        mouse.color = {32, 32, 32}
        if not mouse.pressed then mouse.active = false end
    end
    for i = #self.people, 1, -1 do 
        if self.people[i].dead then table.remove(self.people, i) end
    end
    for i = #self.resources, 1, -1 do
        if self.resources[i].dead then table.remove(self.resources, i) end
    end
    for i = #self.connect_lines, 1, -1 do
        if self.connect_lines[i].src.dead or self.connect_lines[i].dst.dead then 
            if not self.connect_lines[i].dying then self.connect_lines[i]:die() end
        end
        if self.connect_lines[i].dead then table.remove(self.connect_lines, i) end
    end
end

function Game:spawnResources(n)
    local added_flag = true 
    for i = 1, n do
        added_flag = true
        local x, y = 0, 0
        while added_flag do
            x, y = randomInCircle(self.planet.radius - 200)
            added_flag = false
            for _, person in ipairs(self.people) do
                if xyCollidingPerson(game_width/2 + x, game_height/2 + y, person) then
                    added_flag = true
                    break
                end
            end
            for _, resource in ipairs(self.resources) do
                if xyCollidingResource(game_width/2 + x, game_height/2 + y, resource) then
                    added_flag = true
                    break
                end
            end
        end
        table.insert(self.resources, Resource(game_width/2 + x, game_height/2 + y, {size = math.prandom(20, 60)}))
    end
end

function Game:spawnPeople(n)
    local added_flag = true
    for i = 1, n do
        added_flag = true
        local x, y = 0, 0
        while added_flag do
            x, y = randomInCircle(self.planet.radius - 200)
            added_flag = false
            for _, person in ipairs(self.people) do
                if xyCollidingPerson(game_width/2 + x, game_height/2 + y, person) then
                    added_flag = true
                    break
                end
            end
            for _, resource in ipairs(self.resources) do
                if xyCollidingResource(game_width/2 + x, game_height/2 + y, resource) then
                    added_flag = true
                    break
                end
            end
        end
        table.insert(self.people, People(game_width/2 + x, game_height/2 + y, {size = math.prandom(15, 50), pulse = math.prandom(1.6, 2.4)}))
    end
end

function Game:draw()
    for _, drain in ipairs(self.drains) do drain:draw() end
    love.graphics.setFont(main_font_big)
    love.graphics.setColor(32, 32, 32, self.intro_text_alpha)
    local w = main_font_big:getWidth("(MOUSE WHEEL TO ZOOM IN/OUT)")
    love.graphics.print("(MOUSE WHEEL TO ZOOM IN/OUT)", game_width/2 - w/2, game_height/2 + game_height/8 + main_font_big:getHeight()/2)
    local w = main_font_big:getWidth("(HOLD RMB TO MOVE THE CAMERA)")
    love.graphics.print("(HOLD RMB TO MOVE THE CAMERA)", game_width/2 - w/2, game_height/2 + game_height/8 + 1.5*main_font_big:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    self.planet:draw()
    self.active_line:draw()
    for _, person in ipairs(self.people) do person:draw() end
    for _, resource in ipairs(self.resources) do resource:draw() end
    for _, connect_line in ipairs(self.connect_lines) do connect_line:draw() end
    for _, city in ipairs(self.cities) do city:draw() end
    love.graphics.setColor(32, 32, 32, self.game_drain_alpha)
    love.graphics.circle('fill', self.planet.x, self.planet.y, self.planet.radius, 360)
end

function Game:mousepressed(x, y, button)
    if button ~= 'l' and button ~= 'wd' and button ~= 'wu' then return end

    if button == 'l' then
        for _, person in ipairs(self.people) do
            if mouseCollidingPerson(person) then
                mouse.active = true
                local wx, wy = camera:worldCoords(x, y)
                self.active_line.x = wx
                self.active_line.y = wy
            end
        end
        for _, resource in ipairs(self.resources) do
            if mouseCollidingResource(resource) then
                mouse.active = true
                local wx, wy = camera:worldCoords(x, y)
                self.active_line.x = wx
                self.active_line.y = wy
            end
        end
        for _, city in ipairs(self.cities) do
            if mouseCollidingCity(city) then
                mouse.active = true
                local wx, wy = camera:worldCoords(x, y)
                self.active_line.x = wx
                self.active_line.y = wy
            end
        end
    end

    if camerat.can_zoom then 
        if button == 'wu' then 
            if camerat.actual_zoom <= 1.4 then
                camerat.actual_zoom = camerat.actual_zoom + 0.1
                timer:tween(0.35, camerat, {zoom = camerat.zoom + 0.1}, 'in-out-cubic') 
            end
        end
        if button == 'wd' then 
            if camerat.actual_zoom >= 0.2 then 
                camerat.actual_zoom = camerat.actual_zoom - 0.1
                timer:tween(0.35, camerat, {zoom = camerat.zoom - 0.1}, 'in-out-cubic') 
            end
        end
    end
end

function Game:mousereleased(x, y, button)
    if button == 'l' then
        mouse.active = false
        for _, person in ipairs(self.people) do
            for _, resource in ipairs(self.resources) do
                if mouseCollidingPerson(person) and xyCollidingResource(self.active_line.x, self.active_line.y, resource) then
                    if #person.resources >= 6 then return end
                    table.insert(self.connect_lines, ConnectLine(0, 0, {src = resource, dst = person}))
                    resource:addConsumer(person)
                    person:addResource(resource)
                end
            end
        end
        for _, resource in ipairs(self.resources) do
            for _, person in ipairs(self.people) do
                if mouseCollidingResource(resource) and xyCollidingPerson(self.active_line.x, self.active_line.y, person) then
                    if #person.resources >= 6 then return end
                    table.insert(self.connect_lines, ConnectLine(0, 0, {dst = resource, src = person}))
                    resource:addConsumer(person)
                    person:addResource(resource)
                end
            end
        end
        for _, city in ipairs(self.cities) do
            for _, other_city in ipairs(self.cities) do
                if mouseCollidingCity(city) and xyCollidingCity(self.active_line.x, self.active_line.y, other_city) then
                    table.insert(self.connect_lines, ConnectLine(0, 0, {src = city, dst = other_city, city = true}))
                    city:addCity(other_city)
                    other_city:addCity(city)
                end
            end
        end
    end
end
