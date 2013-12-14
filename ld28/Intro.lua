Intro = class('Intro')

function Intro:init()
    self.first_state = true
    self.planet_state = false
    self.resource_state = false
    self.people_state = false
    self.connect_state = false
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
    self.connect_resource = Resource(4*game_width + game_width/2 - game_width/4, game_height/2, {size = 40})
    self.connect_person = People(4*game_width + game_width/2 + game_width/4, game_height/2, {size = 40})
end

function Intro:update(dt)
    self.planet:update(dt)
    self.resource:update(dt)
    self.person_1:update(dt)
    self.person_2:update(dt)
    self.person_3:update(dt)
    self.person_4:update(dt)
    self.person_5:update(dt)
    self.connect_resource:update(dt)
    self.connect_person:update(dt)
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
    love.graphics.setFont(main_font_huge)
    love.graphics.setColor(255, 255, 255, 255)

    self.planet:draw()
    self.resource:draw()
    self.person_1:draw()
    self.person_2:draw()
    self.person_3:draw()
    self.person_4:draw()
    self.person_5:draw()
    self.connect_resource:draw()
    self.connect_person:draw()
end

function Intro:mousepressed(x, y, button)
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
                timer:after(3, function()
                    timer:tween(2, self, {connect2_alpha = 255}, 'in-out-cubic')
                end)
            end)
        end
    end
end

function Intro:mousereleased(x, y, button)
    
end