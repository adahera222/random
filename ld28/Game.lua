Game = class('Game')

function Game:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 2345, line_width = 8})

    self.intro_text_alpha = 0
    timer:after(4, function()
        timer:tween(2, self, {intro_text_alpha = 255}, 'in-out-cubic')
        timer:after(6, function()
            timer:tween(2, self, {intro_text_alpha = 0}, 'in-out-cubic')
        end)
    end)

    self.people = {}
    self.resources = {}
    self.connect_lines = {}
    table.insert(self.resources, Resource(game_width/2, game_height/2, {size = 80}))

    self:spawnResources(math.random(20, 40))
    self:spawnPeople(math.random(40, 60))
end

function Game:update(dt)
    camera:zoomTo(camerat.zoom)
    local x, y = camera:pos()
    if mouse.x < 200 then 
        camerat.moving.left = true
        camerat.a.x = -(200-mouse.x)*camerat.actual_zoom 
    end
    if mouse.x > game_width-200 then 
        camerat.moving.right = true
        camerat.a.x = (mouse.x-(game_width-200))*camerat.actual_zoom 
    end
    if mouse.y < 150 then 
        camerat.moving.up = true
        camerat.a.y = -(150-mouse.y)*camerat.actual_zoom 
    end
    if mouse.y > game_height-150 then 
        camerat.moving.down = true
        camerat.a.y = (mouse.y-(game_height-150))*camerat.actual_zoom 
    end
    camerat.v.x = math.min(camerat.v.x + camerat.a.x*dt, 200)
    camerat.v.y = math.min(camerat.v.y + camerat.a.y*dt, 200)
    camera:move(camerat.v.x*camerat.v_multiplier, camerat.v.y*camerat.v_multiplier)
    if not camerat.moving.left and not camerat.moving.right then camerat.v.x = camerat.v.x*camerat.damping end
    if not camerat.moving.up and not camerat.moving.down then camerat.v.y = camerat.v.y*camerat.damping end
        

    self.planet:update(dt)
    local mouse_color = false
    for _, person in ipairs(self.people) do 
        person:update(dt) 
        if mouseCollidingPerson(person) then mouse_color = true end
    end
    for _, resource in ipairs(self.resources) do 
        resource:update(dt) 
        if mouseCollidingResource(resource) then mouse_color = true end
    end
    if mouse_color then mouse.color = {64, 96, 232}
    else
        mouse.color = {32, 32, 32}
        if not mouse.pressed then mouse.active = false end
    end

    camerat.moving.left = false
    camerat.moving.right = false
    camerat.moving.up = false
    camerat.moving.down = false
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
        table.insert(self.people, People(game_width/2 + x, game_height/2 + y, {size = math.prandom(10, 20), pulse = math.prandom(1.6, 2.4)}))
    end
end

function Game:draw()
    love.graphics.setFont(main_font_big)
    love.graphics.setColor(32, 32, 32, self.intro_text_alpha)
    local w = main_font_big:getWidth("(MOUSE WHEEL TO ZOOM IN/OUT)")
    love.graphics.print("(MOUSE WHEEL TO ZOOM IN/OUT)", game_width/2 - w/2, game_height/2 + game_height/8 + main_font_big:getHeight()/2)
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.setFont(main_font_huge)

    self.planet:draw()
    for _, person in ipairs(self.people) do person:draw() end
    for _, resource in ipairs(self.resources) do resource:draw() end
end

function Game:mousepressed(x, y, button)
    if button ~= 'l' and button ~= 'r' and button ~= 'wd' and button ~= 'wu' then return end

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
    mouse.active = false
end
