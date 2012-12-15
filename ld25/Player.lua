require 'Movable'

Player = class('Player', Movable)

function Player:initialize(x, y)
    Movable.initialize(self, x, y, 32, 32, 250, Vector(500, 500), 0.90, 600, -200, 2)
    self.image = gl.player_normal
end

function Player:update(dt)
    Movable.update(self, dt)
end

function Player:draw()
    Movable.draw(self)
end

function Player:mousepressed(x, y, button)
    if button == 'l' then
        beholder:trigger('create projectile', x, y) 
    end
    
end
