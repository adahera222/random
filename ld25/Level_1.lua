require 'Level'

Level_1 = class('Level_1', Level)

function Level_1:initialize(name, map)
    Level.initialize(self, name, map)
end

function Level_1:update(dt)
    Level.update(self, dt)
end

function Level_1:draw()
    Level.draw(self) 
end

function Level_1:keypressed(key)
    if key == 'return' then
        beholder.trigger('transition', 'intro')
    end
end
