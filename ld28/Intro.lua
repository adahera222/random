Intro = class('Intro')

function Intro:init()
    self.first_state = true
    self.planet_state = false
    self.resource_state = false
    self.people_state = false
    self.link_state = false

    self.first_alpha = 0
    timer:tween(2, self, {first_alpha = 255}, 'in-out-cubic')
    self.planet = Planet(game_width + game_width/2, game_height/2, {radius = 360, line_width = 8})
end

function Intro:update(dt)
    self.planet:update(dt)
end

function Intro:draw()
    love.graphics.setColor(32, 32, 32, self.first_alpha)
    local w = main_font_huge:getWidth("CLICK")
    love.graphics.print("CLICK", game_width/2 - w/2, game_height/2 - main_font_huge:getHeight()/2)
    love.graphics.setColor(255, 255, 255, 255)
    self.planet:draw()
end

function Intro:mousepressed(x, y, button)
    
end

function Intro:mousereleased(x, y, button)
    
end
