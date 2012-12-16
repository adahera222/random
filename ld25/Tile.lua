require 'Entity'

Tile = class('Tile', Entity)

function Tile:initialize(tile_type, x, y)
    Entity.initialize(self, gl.entity_id(), x, y, 32, 32, gl[tile_type])
end

function Tile:update(dt)
    Entity.update(self, dt)
end

function Tile:draw()
    Entity.draw(self)
end
