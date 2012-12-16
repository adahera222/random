require 'Entity'

RotatingTile = class('RotatingTile', Entity)

function RotatingTile:initialize(tile_type, x, y, r, sx, sy, dr, rgb)
    Entity.initialize(self, gl.entity_id(), x, y, 32*sx, 32*sy, gl[tile_type])
    self.r = r
    self.dr = dr
    self.sx = sx
    self.sy = sy
    self.rgb = rgb
end

function RotatingTile:update(dt)
    self.r = self.r + self.dr*dt
end

function RotatingTile:draw()
    love.graphics.setColor(self.rgb.r, self.rgb.g, self.rgb.b)
    love.graphics.push()
    love.graphics.translate(self.p.x + self.w/2, self.p.y + self.h/2)
    love.graphics.rotate(self.r)
    love.graphics.translate(-self.p.x - self.w/2, -self.p.y - self.h/2)
    love.graphics.draw(self.image, self.p.x, self.p.y, 0, self.sx, self.sy)
    love.graphics.pop()
    love.graphics.setColor(255, 255, 255)
end
