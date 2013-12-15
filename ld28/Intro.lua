Intro = class('Intro')

function Intro:init()
    self.first_state = true
    self.planet_state = false
    self.resource_state = false
    self.people_state = false
    self.connect_state = false
    self.create_state = false
    self.death_state = false
    self.drain_state = false
    self.can_click_next = false

    self.first_alpha = 0
    timer:after(2, function()
        timer:tween(2, self, {first_alpha = 255}, 'in-out-cubic')
        timer:after(1.5, function() self.can_click_next = true end)
    end)

    self.planet_alpha = 0
    self.planet = Planet(game_width + game_width/2, game_height/2, {radius = 360, line_width = 8})

    self.resource_alpha = 0
    self.resource = Resource(2*game_width + game_width/2, game_height/2, {size = 60})

    self.people_alpha = 0
    self.person_1 = People(3*game_width + game_width/2, game_height/2, {size = 60, pulse = 3.2})
    self.person_2 = People(3*game_width + game_width/2 - 110, game_height/2, {size = 30, pulse = 2.6})
    self.person_3 = People(3*game_width + game_width/2 + 100, game_height/2, {size = 20, pulse = 2.2})
    self.person_4 = People(3*game_width + game_width/2 - 170, game_height/2, {size = 15, pulse = 2})
    self.person_5 = People(3*game_width + game_width/2 + 150, game_height/2, {size = 15, pulse = 1.8})

    self.connect_alpha = 0
    self.connect2_alpha = 0
    self.connect_person = People(4*game_width + game_width/2 - game_width/4, game_height/2, {size = 40, pulse = 2.5})
    self.connect_resource = Resource(4*game_width + game_width/2 + game_width/4, game_height/2, {size = 40})
    self.connect_line = nil
    self.active_line = ActiveLine(0, 0)

    self.create_alpha = 0
    self.create_person = People(5*game_width + game_width/2, game_height/2 + game_height/8, {size = 80, pulse = 1.5, consuming = true, consume_rate = 1})
end

function Intro:update(dt)
    self.planet:update(dt)
    self.resource:update(dt)
    self.person_1:update(dt)
    self.person_2:update(dt)
    self.person_3:update(dt)
    self.person_4:update(dt)
    self.person_5:update(dt)
    self.active_line:update(dt)
    if self.connect_line then self.connect_line:update(dt) end
    self.connect_resource:update(dt)
    self.connect_person:update(dt)
    self.create_person:update(dt)

    if mouseCollidingPerson(self.connect_person) or mouseCollidingResource(self.connect_resource) then mouse.color = {64, 96, 232} 
    else
        mouse.color = {32, 32, 32}
        if not mouse.pressed then mouse.active = false end
    end
end

function Intro:draw()
    love.graphics.setColor(32, 32, 32, self.first_alpha)
    local w = main_font_huge:getWidth("CLICK")
    love.graphics.print("CLICK", game_width/2 - w/2, game_height/2 - main_font_huge:getHeight()/2)
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setColor(32, 32, 32, self.planet_alpha)
    local w = main_font_huge:getWidth("THIS IS A PLANET")
    love.graphics.print("THIS IS A PLANET", game_width/2 - w/2 + game_width, game_height/2 - main_font_huge:getHeight()/2)
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setColor(32, 32, 32, self.resource_alpha)
    local w = main_font_huge:getWidth("THIS IS A RESOURCE")
    love.graphics.print("THIS IS A RESOURCE", game_width/2 - w/2 + 2*game_width, game_height/2 + main_font_huge:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setColor(32, 32, 32, self.people_alpha)
    local w = main_font_huge:getWidth("THESE ARE PEOPLE")
    love.graphics.print("THESE ARE PEOPLE", game_width/2 - w/2 + 3*game_width, game_height/2 + main_font_huge:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setColor(32, 32, 32, self.connect_alpha)
    local w = main_font_huge:getWidth("PEOPLE NEED RESOURCES TO SURVIVE")
    love.graphics.print("PEOPLE NEED RESOURCES TO SURVIVE", game_width/2 - w/2 + 4*game_width, game_height/2 - 2*main_font_huge:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setColor(32, 32, 32, self.connect2_alpha)
    love.graphics.setFont(main_font_big)
    local w = main_font_big:getWidth("(CLICK AND DRAG TO CONNECT)")
    love.graphics.print("(CLICK AND DRAG TO CONNECT)", game_width/2 - w/2 + 4*game_width, game_height/2 + main_font_huge:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    love.graphics.setFont(main_font_huge)
    love.graphics.setColor(32, 32, 32, self.create_alpha)
    local w = main_font_huge:getWidth("WITH ENOUGH RESOURCES")
    love.graphics.print("WITH ENOUGH RESOURCES", game_width/2 - w/2 + 5*game_width, game_height/2 - 2.5*main_font_huge:getHeight())
    local w = main_font_huge:getWidth("NEW PEOPLE ARE CREATED")
    love.graphics.print("NEW PEOPLE ARE CREATED", game_width/2 - w/2 + 5*game_width, game_height/2 - 1.5*main_font_huge:getHeight())
    love.graphics.setColor(255, 255, 255, 255)

    self.planet:draw()
    self.resource:draw()
    self.person_1:draw()
    self.person_2:draw()
    self.person_3:draw()
    self.person_4:draw()
    self.person_5:draw()
    self.active_line:draw()
    if self.connect_line then self.connect_line:draw() end
    self.connect_resource:draw()
    self.connect_person:draw()
    self.create_person:draw()
end

function Intro:mousepressed(x, y, button)
    if button ~= "l" and button ~= "r" then return end

    if mouseCollidingPerson(self.connect_person) or mouseCollidingResource(self.connect_resource) then 
        mouse.active = true
        local wx, wy = camera:worldCoords(x, y)
        self.active_line.x = wx
        self.active_line.y = wy
    end

    if self.can_click_next then
        timer:tween(2, camera, {x = camera.x + game_width}, 'in-out-cubic')
        self.can_click_next = false

        if self.first_state then
            self.first_state = false
            self.planet_state = true
            timer:after(2, function()
                timer:tween(2, self, {planet_alpha = 255}, 'in-out-cubic')
                timer:after(1.5, function() self.can_click_next = true end)
            end)
        elseif self.planet_state then
            self.planet_state = false
            self.resource_state = true
            timer:after(2, function()
                timer:tween(2, self, {resource_alpha = 255}, 'in-out-cubic')
                timer:after(1.5, function() self.can_click_next = true end)
            end)
        elseif self.resource_state then
            self.resource_state = false
            self.people_state = true
            timer:after(2, function()
                timer:tween(2, self, {people_alpha = 255}, 'in-out-cubic')
                timer:after(1.5, function() self.can_click_next = true end)
            end)
        elseif self.people_state then
            self.people_state = false
            self.connect_state = true
            timer:after(2, function()
                timer:tween(2, self, {connect_alpha = 255}, 'in-out-cubic')
                timer:after(2, function()
                    timer:tween(2, self, {connect2_alpha = 255}, 'in-out-cubic')
                end)
            end)
        elseif self.connect_state then
            self.connect_state = false
            self.create_state = true
            timer:after(2, function()
                timer:tween(2, self, {create_alpha = 255}, 'in-out-cubic')
                timer:after(2, function()
                    self.create_person:changeSize(self.create_person.size/2) 
                    self.create_person:changePulse(2*self.create_person.pulse_time)
                end)
                timer:after(4, function() self.can_click_next = true end)
            end)
        end
    end
end

function Intro:mousereleased(x, y, button)
    mouse.active = false
    if mouseCollidingPerson(self.connect_person) then
        self.connect_line = ConnectLine(0, 0, {src = self.connect_resource, dst = self.connect_person})
        self.connect_person:setConsume()
        self.connect_resource:addConsumer(self.connect_person)
        self.can_click_next = true
    elseif mouseCollidingResource(self.connect_resource) then
        self.connect_line = ConnectLine(0, 0, {dst = self.connect_resource, src = self.connect_person})
        self.connect_person:setConsume()
        self.connect_resource:addConsumer(self.connect_person)
        self.can_click_next = true
    end
end
