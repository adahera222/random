People = class('People', Entity)

function People:init(x, y, settings)
    Entity.init(self, x, y, settings) 

    self.target_size = settings.size
    self.size = 12
    self.alpha = 0
    timer:tween(2, self, {size = self.target_size}, 'out-elastic')
    timer:tween(2, self, {alpha = 255}, 'in-out-cubic')
    self.outer_ring = 0
    self.mid_ring = self.size/4
    self.inner_ring = self.size/2
    self.pulse_time = settings.pulse or 2
    self.pulse_tween_time = settings.pulse or 2
    self.outer_ring_tid = nil
    self.mid_ring_tid = nil
    self:changePulse(self.pulse_time, self.pulse_tween_time) 

    self.consuming = settings.consuming
    self.faders = {}
    if self.consuming then
        self.consume_rate = settings.consume_rate or self.pulse_time - self.pulse_time/2 or 1.5
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

function People:randomWalk(angle, distance)
    
end

function People:die()
    timer:tween(4, self, {size = 2}, 'in-out-cubic')
    timer:tween(2, self, {alpha = 0}, 'in-out-cubic')
    timer:after(5, function() self.dead = true end)
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

function People:changeSize(new_size, time)
    timer:tween(time or 1, self, {size = new_size}, 'out-elastic')
    timer:tween(self.pulse_tween_time, self, {outer_ring = new_size/6}, 'out-elastic')
    timer:tween(self.pulse_tween_time, self, {mid_ring = new_size/4 + new_size/8}, 'out-elastic')
end

function People:changePulse(new_pulse, new_pulse_tween)
    if self.outer_ring_tid then timer:cancel(self.outer_ring_tid) end
    if self.mid_ring_tid then timer:cancel(self.mid_ring_tid) end

    self.outer_ring_tid = timer:every(new_pulse, function()
        timer:tween(new_pulse_tween or new_pulse, self, {outer_ring = self.size/8}, 'out-elastic')
        timer:after(new_pulse/2, function()
            timer:tween(new_pulse_tween or new_pulse, self, {outer_ring = -self.size/8}, 'in-out-cubic')
        end)
    end)

    self.mid_ring_tid = timer:every(new_pulse, function()
        timer:tween(new_pulse_tween or new_pulse, self, {mid_ring = self.size/4 + self.size/10}, 'out-elastic')
        timer:after(new_pulse/2, function()
            timer:tween(new_pulse_tween or new_pulse, self, {mid_ring = self.size/4 - self.size/10}, 'in-out-cubic')
        end)
    end)
end

function People:draw()
    for _, fader in ipairs(self.faders) do fader:draw() end

    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.size/5)
    love.graphics.circle('line', self.x, self.y, self.size - self.outer_ring, 360)
    love.graphics.setLineWidth(self.size/9)
    love.graphics.circle('line', self.x, self.y, self.size - self.mid_ring, 360)
    love.graphics.setColor(255, 255, 255)
end
