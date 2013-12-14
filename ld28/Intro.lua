Intro = class('Intro')

function Intro:init()
    self.first_state = true
    self.planet_state = false
    self.resource_state = false
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
end

function Intro:update(dt)
    self.planet:update(dt)
    self.resource:update(dt)
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

    self.planet:draw()
    self.resource:draw()
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
        end
    end
end

function Intro:mousereleased(x, y, button)
    
end
