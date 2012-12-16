require 'Vector'
require 'utils'

-- Sorta based on:
-- http://nova-fusion.org/2011/04/19/cameras-in-love2d-part-1-the-basics/ 

Camera = class('Camera')

function Camera:initialize(bounds_aabb)
    self.p = Vector()
    self.r = 0
    self.v = Vector()
    self.bounds = bounds_aabb
    self.layers = {}
end

function Camera:add(ps, draw_function, entity)
    for _, layer in ipairs(self.layers) do
        if layer.ps == ps then
            table.insert(layer.fs, {f = draw_function, e = entity})
            return
        end
    end

    self:addLayer(ps)
    self:add(ps, draw_function, entity)
end

function Camera:remove(ps, e)
    for _, layer in ipairs(self.layers) do
        if layer.ps == ps then
            for i, f in ipairs(layer.fs) do
                if f.e.id == e.id then
                    table.remove(layer.fs, i)
                    return
                end
            end
        end
    end
end

function Camera:set(ps)
    love.graphics.push()
    love.graphics.rotate(-self.r)
    love.graphics.translate(-self.p.x*ps, -self.p.y*ps)
end

function Camera:unset()
    love.graphics.pop()
end

function Camera:update(dt)
    self:move(dt)
end

function Camera:move(dt)
    self:setPosition(self.p.x + self.v.x*dt, self.p.y + self.v.y*dt)
end

function Camera:rotate(dr)
    self.r = self.r + dr
end

function Camera:setX(x)
    self.p.x = math.clamp(x, self.bounds.x1, self.bounds.x2)
end

function Camera:setY(y)
    self.p.y = math.clamp(y, self.bounds.y1, self.bounds.y2)
end

function Camera:addLayer(ps)
    table.insert(self.layers, {ps = ps, fs = {}})
    table.sort(self.layers, function(a, b) return a.ps < b.ps end)
end

function Camera:setPosition(x, y)
    if x then self:setX(x) end
    if y then self:setY(y) end
end

function Camera:setBounds(x1, y1, x2, y2)
    self.bounds.x1 = x1
    self.bounds.x2 = x2
    self.bounds.y1 = y1
    self.bounds.y2 = y2
end

function Camera:follow(dt, entity)
    -- dx, dy entity's distance from center of the screen
    local dx = entity.p.x - (self.p.x + gl.width/2)
    local dy = entity.p.y - (self.p.y + gl.height/2)
    self.v = Vector(dx, dy)
end

function Camera:draw()
    for _, layer in ipairs(self.layers) do
        self:set(layer.ps)
        for _, f in ipairs(layer.fs) do 
            if instanceOf(RotatingTile, f.e) then
                love.graphics.setBlendMode('additive')
                f.f(f.e)
                love.graphics.setBlendMode('alpha')

            else f.f(f.e) end 
        end
        self:unset()
    end
end
