Planet = class('Planet', Entity)

function Planet:init(x, y, settings)
    Entity.init(self, x, y, settings)

    self.outer_ring = 4
    self.mid_ring = 12
    self.inner_ring = 18
    self.pulse_time = 3
    self.pulse_tween_time = 3

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {inner_ring = -18}, 'out-elastic')
        timer:after(self.pulse_time, function()
            timer:tween(self.pulse_tween_time, self, {inner_ring = 18}, 'out-elastic')
        end)
    end)

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {mid_ring = -12}, 'out-elastic')
        timer:after(self.pulse_time, function()
            timer:tween(self.pulse_tween_time, self, {mid_ring = 12}, 'out-elastic')
        end)
    end)

    timer:every(self.pulse_time, function()
        timer:tween(self.pulse_tween_time, self, {outer_ring = -4}, 'out-elastic')
        timer:after(self.pulse_time, function()
            timer:tween(self.pulse_tween_time, self, {outer_ring = 4}, 'out-elastic')
        end)
    end)

    --[[
    self.orbit_radius = 120
    self.orbit = {x = self.x + self.radius - self.orbit_radius, y = self.y, radius = 24} 
    self.orbit_outer_ring = 16
    self.orbit_mid_ring = 11
    self.orbit_inner_ring = 4
    self.orbit_pulse_time = 3.5
    self.orbit_pulse_tween_time = 3.5 

    timer:every(self.orbit_pulse_time, function()
        timer:tween(self.orbit_pulse_tween_time, self, {orbit_inner_ring = -16}, 'out-elastic')
        timer:after(self.orbit_pulse_time, function()
            timer:tween(self.orbit_pulse_tween_time, self, {orbit_inner_ring = 16}, 'out-elastic')
        end)
    end)

    timer:every(self.orbit_pulse_time, function()
        timer:tween(self.orbit_pulse_tween_time, self, {orbit_mid_ring = -11}, 'out-elastic')
        timer:after(self.orbit_pulse_time, function()
            timer:tween(self.orbit_pulse_tween_time, self, {orbit_mid_ring = 11}, 'out-elastic')
        end)
    end)

    timer:every(self.orbit_pulse_time, function()
        timer:tween(self.orbit_pulse_tween_time, self, {orbit_outer_ring = -4}, 'out-elastic')
        timer:after(self.orbit_pulse_time, function()
            timer:tween(self.orbit_pulse_tween_time, self, {orbit_outer_ring = 4}, 'out-elastic')
        end)
    end)
    ]]--
end

function Planet:update(dt)
    --[[
    self.orbit.x = self.x + (self.radius - self.orbit_radius)*math.cos(-0.25*t)
    self.orbit.y = self.y + (self.radius - self.orbit_radius)*math.sin(-0.25*t)
    ]]--
end

function Planet:draw()
    love.graphics.setColor(32, 32, 32)

    love.graphics.setLineWidth(self.line_width)
    love.graphics.circle('line', self.x, self.y, self.radius - self.outer_ring, 360)
    love.graphics.setLineWidth(self.line_width/2)
    love.graphics.circle('line', self.x, self.y, self.radius - self.mid_ring, 360)
    love.graphics.setLineWidth(2)
    love.graphics.circle('line', self.x, self.y, self.radius - self.inner_ring, 360)

    --[[
    love.graphics.setLineWidth(6)
    love.graphics.circle('line', self.orbit.x, self.orbit.y, self.orbit.radius - self.orbit_inner_ring, 360)
    love.graphics.setLineWidth(4)
    love.graphics.circle('line', self.orbit.x, self.orbit.y, self.orbit.radius - self.orbit_mid_ring, 360)
    love.graphics.setLineWidth(2)
    love.graphics.circle('line', self.orbit.x, self.orbit.y, self.orbit.radius - self.orbit_outer_ring, 360)
    ]]--

    love.graphics.setColor(255, 255, 255)
end
