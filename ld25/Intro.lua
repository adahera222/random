require 'middleclass'

Intro = class('Intro')

function Intro:initialize(name)
    self.name = name
end

function Intro:update(dt)

end

function Intro:draw() 
    love.graphics.print(self.name, 10, 10)
end

function Intro:keypressed(key)
    if key == 'return' then
        beholder.trigger('transition', 'level_1')
    end
end

function Intro:mousepressed(x, y, button)
    
end
