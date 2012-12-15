require 'Entity'

Tile = class('Tile', Entity)

function Tile:initialize(tile_type, x, y)
    Entity.initialize(self, gl.entity_id(), x, y, 32, 32)

    -- add other types of images as needed
    if tile_type == 'normal_block' then
        self.image = gl.normal_block
    end
end

function Tile:update(dt)
    Entity.update(self, dt)
end

function Tile:draw()
    Entity.draw(self)
    love.graphics.rectangle('line', self.a_aabb.x1, self.a_aabb.y1, self.w, self.h)
end
