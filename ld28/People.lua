People = class('People', Entity)

function People:init(x, y, settings)
    Entity.init(self, x, y, settings) 

    self.outer_ring = 0
    self.mid_ring = self.size/4
    self.inner_ring = self.size/2
    self.pulse_time = settings.pulse or 2
    self.pulse_tween_time = settings.pulse or 2

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {outer_ring = self.size/8}, 'out-elastic')
        timer:after(self.pulse_time/2, function()
            timer:tween(self.pulse_tween_time, self, {outer_ring = -self.size/8}, 'in-out-cubic')
        end)
    end)

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {mid_ring = self.size/4 + self.size/10}, 'out-elastic')
        timer:after(self.pulse_time/2, function()
            timer:tween(self.pulse_tween_time, self, {mid_ring = self.size/4 - self.size/10}, 'in-out-cubic')
        end)
    end)

    self.consuming = settings.consuming
    self.faders = {}
    if self.consuming then
        self.consume_rate = self.pulse_time - self.pulse_time/2 or 1.5
        timer:every(self.consume_rate, function() 
            table.insert(self.faders, PeopleFader(self.x, self.y, {size = self.size}))
        end)
    end
end

function People:update(dt)
    for i = #self.faders, 1, -1 do
        if self.faders[i].dead then table.remove(self.faders, i) end
    end
end

function People:setConsume(consume_rate)
    self.consuming = true
    if self.consuming then
        self.consume_rate = consume_rate or self.pulse_time - self.pulse_time/2
        timer:every(self.consume_rate, function() 
            table.insert(self.faders, PeopleFader(self.x, self.y, {size = self.size}))
        end)
    end
end

function People:draw()
    for _, fader in ipairs(self.faders) do fader:draw() end

    love.graphics.setColor(32, 32, 32)
    love.graphics.setLineWidth(self.size/5)
    love.graphics.circle('line', self.x, self.y, self.size - self.outer_ring, 360)
    love.graphics.setLineWidth(self.size/9)
    love.graphics.circle('line', self.x, self.y, self.size - self.mid_ring, 360)
    love.graphics.setColor(255, 255, 255)
end
