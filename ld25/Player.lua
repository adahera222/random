require 'Movable'

Player = class('Player', Movable)

function Player:initialize(x, y)
    Movable.initialize(self, x, y, 32, 32, 300, Vector(300, 300), 0.85)
    self.image = gl.player_image
end

function Player:update(dt)
    Movable.update(self, dt)
end

function Player:draw()
    Movable.draw(self)
end
