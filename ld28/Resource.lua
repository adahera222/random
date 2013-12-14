Resource = class('Resource', Entity)

function Resource:init(x, y, settings)
    Entity.init(self, x, y, settings)

    self.outer_ring = self.size
    self.mid_ring = self.size/1.5

    self.pulse_time = 2
    self.pulse_tween_time = 2

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {outer_ring = self.size + self.size/8}, 'out-elastic')
        timer:after(self.pulse_time/2, function()
            timer:tween(self.pulse_tween_time, self, {outer_ring = self.size}, 'in-out-cubic')
        end)
    end)

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {mid_ring = self.size/1.5 + self.size/10}, 'out-elastic')
        timer:after(self.pulse_time/2, function()
            timer:tween(self.pulse_tween_time, self, {mid_ring = self.size/1.5}, 'in-out-cubic')
        end)
    end)
    
    self.faders = {}
    timer:every(self.pulse_time - self.pulse_time/2, function()
        table.insert(self.faders, ResourceFader(self.x, self.y, {size = self.size + 4}))
    end)
end

function Resource:update(dt)
    for i = #self.faders, 1, -1 do
        if self.faders[i].dead then table.remove(self.faders, i) end
    end
end

function Resource:polygonize(size)
    if size then
        return {self.x - 0.8*size, self.y, self.x, self.y - size, 
                self.x + 0.8*size, self.y, self.x, self.y + size}
    else 
        return {self.x - 0.8*self.size, self.y, self.x, self.y - self.size, 
                self.x + 0.8*self.size, self.y, self.x, self.y + self.size}
    end
end

function Resource:draw()
    for _, fader in ipairs(self.faders) do fader:draw() end

    love.graphics.setColor(32, 32, 32)
    love.graphics.setLineWidth(self.size/9)
    love.graphics.polygon('line', self:polygonize(self.outer_ring))
    love.graphics.setLineWidth(self.size/12)
    love.graphics.polygon('line', self:polygonize(self.mid_ring))
    love.graphics.setColor(255, 255, 255)
end
