require 'Movable'

Player = class('Player', Movable)

function Player:initialize(x, y)
    Movable.initialize(self, x, y, 32, 32, 250, Vector(500, 500), 0.90, 2)
    self.image = gl.player_image
end

function Player:update(dt)
    Movable.update(self, dt)
end

function Player:draw()
    Movable.draw(self)
end
