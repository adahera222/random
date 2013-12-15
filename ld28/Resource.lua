Resource = class('Resource', Entity)

function Resource:init(x, y, settings)
    Entity.init(self, x, y, settings)

    self.outer_ring = self.size
    self.mid_ring = self.size/1.5
    self.outer_ring_tid = nil
    self.mid_ring_tid = nil
    self.pulse_time = settings.pulse or 2
    self.pulse_tween_time = settings.pulse or 2
    self:changePulse(self.pulse_time, self.pulse_tween_time)

    self.init_size = self.size
    self.drain_rate = self.pulse_time - self.pulse_time/2 or 1.5
    self.faders = {}
    self.drain_rate_tid = timer:every(self.drain_rate, function()
        table.insert(self.faders, ResourceFader(self.x, self.y, {size = self.size + 4}))
    end)

    self.alpha = 0
    timer:tween(2, self, {alpha = 255}, 'in-out-cubic')
    self:polygonize()
    self.consumers = {}
    self.nsc = 1
    self.n_size_changes_t = {{216, 216, 216, 12}, {200, 200, 200, 11}, {184, 184, 184, 10}, {168, 168, 168, 9}, {152, 152, 152, 8},
                             {136, 136, 136, 7}, {120, 120, 120, 6}, {104, 104, 104, 5}, {88, 88, 88, 4}, {72, 72, 72, 3}}
end

function Resource:update(dt)
    for i = #self.faders, 1, -1 do
        if self.faders[i].dead then table.remove(self.faders, i) end
    end
end

function Resource:polygonize(size)
    if size then self.points = {self.x - 0.8*size, self.y, self.x, self.y - size, self.x + 0.8*size, self.y, self.x, self.y + size}
    else self.points = {self.x - 0.8*self.size, self.y, self.x, self.y - self.size, self.x + 0.8*self.size, self.y, self.x, self.y + self.size} end
    return self.points
end

function Resource:die()
    timer:cancel(self.drain_rate_tid)
    if self.outer_ring_tid then timer:cancel(self.outer_ring_tid) end
    if self.mid_ring_tid then timer:cancel(self.mid_ring_tid) end
    timer:tween(2, self, {alpha = 0}, 'in-out-cubic')
    timer:after(5, function()
        self.people = nil
        self.dead = true
    end)
end

function Resource:changeSize(new_size, time)
    if new_size < 10 then self:die() end
    timer:tween(time or 1, self, {size = new_size}, 'out-elastic')
    timer:tween(self.pulse_tween_time, self, {outer_ring = new_size + new_size/8}, 'out-elastic')
    timer:tween(self.pulse_tween_time, self, {mid_ring = new_size/1.5 + new_size/10}, 'out-elastic')
    if game then
        table.insert(game.drains, Drain(self.x, self.y, {size = self.n_size_changes_t[self.nsc][4]*new_size, 
                                                         color = {self.n_size_changes_t[self.nsc][1], self.n_size_changes_t[self.nsc][2], self.n_size_changes_t[self.nsc][3]}}))
    end
    if self.nsc < 9 then self.nsc = self.nsc + 1 end
    if self.consumers then
        if #self.consumers >= 4 then
            local n = 1
            for _, consumer in ipairs(self.consumers) do
                if consumer.resources then
                    if #consumer.resources == 1 and consumer.resources[1].id == self.id then
                        n = n + 1
                    end
                end
            end
            if n >= 4 then table.insert(game.cities, City(self.x, self.y, {size = 5*self.init_size, ref = Vector(self.x, self.y)})) end
        end
    end
end

function Resource:changePulse(new_pulse, new_pulse_tween)
    if self.outer_ring_tid then timer:cancel(self.outer_ring_tid) end
    if self.mid_ring_tid then timer:cancel(self.mid_ring_tid) end

    self.outer_ring_tid = timer:every(new_pulse, function()
        timer:tween(new_pulse_tween, self, {outer_ring = self.size + self.size/8}, 'out-elastic')
        timer:after(new_pulse/2, function()
            timer:tween(new_pulse_tween, self, {outer_ring = self.size}, 'in-out-cubic')
        end)
    end)

    self.mid_ring_tid = timer:every(new_pulse, function()
        timer:tween(new_pulse_tween, self, {mid_ring = self.size/1.5 + self.size/10}, 'out-elastic')
        timer:after(new_pulse/2, function()
            timer:tween(new_pulse_tween, self, {mid_ring = self.size/1.5}, 'in-out-cubic')
        end)
    end)
end

function Resource:addConsumer(consumer)
    if self.drain_rate_tid then timer:cancel(self.drain_rate_tid) end
    self.drain_rate_tid = timer:every(self.drain_rate - 0.05, function()
        table.insert(self.faders, ResourceFader(self.x, self.y, {size = self.size + 4}))
    end)
    for _, c in ipairs(self.consumers) do
        if c.id == consumer.id then return end
    end
    table.insert(self.consumers, consumer)
    self:changeSize(self.size - consumer.size/math.prandom(2, 3.5))
    self:changePulse(self.pulse_time - 0.1)
end

function Resource:draw()
    for _, fader in ipairs(self.faders) do fader:draw() end

    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.size/9)
    love.graphics.polygon('line', self:polygonize(self.outer_ring))
    love.graphics.setLineWidth(self.size/12)
    love.graphics.polygon('line', self:polygonize(self.mid_ring))
    love.graphics.setColor(255, 255, 255)
end
