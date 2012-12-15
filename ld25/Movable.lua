require 'Entity'

Movable = class('Movable', Entity)

function Movable:initialize(x, y, w, h, max_v, a, damping, max_fall, jump_a, max_jumps)
    Entity.initialize(self, gl.entity_id(), x, y, w, h)

    self.v = Vector()
    self.max_v = max_v
    self.max_fall = max_fall
    self.a = a
    self.jump_a = jump_a
    self.dmp = damping
    self.jump = false
    self.jump_ti = 0
    self.max_jumps = max_jumps
    self.jumps_left = max_jumps
    self.moving = {left = false, right = false}
    self.jump_control = false
    self.prev_dir = nil 
    self.on_ground = false

    beholder:observe('move left' .. self.id,
                     function() self.moving.left = true end)
    beholder:observe('move right' .. self.id,
                     function() self.moving.right = true end)
    beholder:observe('jump' .. self.id,
                     function() 
                         if self.jumps_left > 0 then self.jump = true end 
                     end)
    beholder:observe('displace movable' .. self.id,
                     function(direction, p) self:displace(direction, p) end)
end

function Movable:update(dt)
    Entity.update(self, dt)
    self:move(dt)
    if self.jumps_left > 0 then
        if self.jump then self:jumpImpulse(dt) end
    end
    self:gravity(dt)
    self.p.x = self.p.x + self.v.x*dt
    self.p.y = self.p.y + self.v.y*dt

    self.on_ground = self:onGround()
end

function Movable:move(dt)
    if self.moving.left then
        self.v.x = math.max(self.v.x - self.a.x*dt, -self.max_v)
        self.direction = 'left'
    end

    if self.moving.right then
        self.v.x = math.min(self.v.x + self.a.x*dt, self.max_v)
        self.direction = 'right'
    end

    if self.jump_control then
        self.v.y = self.jump_a
        if self.jump_ti >= 1 then
            self.jump_control = false
            self.jump_ti = 0
        end
    end

    if not self.moving.left and not self.moving.right then
        self.v.x = self.v.x * self.dmp
    end

    self.moving.left = false
    self.moving.right = false
end

function Movable:gravity(dt)
    self.v.y = math.min(self.v.y + gl.gravity*dt, self.max_fall)
end

function Movable:jumpImpulse(dt)
    self.on_ground = false
    self.prev_dir = nil

    self.jump = false
    self.jumps_left = self.jumps_left - 1 
    self.jump_ti = self.jump_ti + 1
    self.jump_control = true
end

function Movable:onGround()
    if self.prev_dir == 'up' then return true else return false end
end

function Movable:draw()
    Entity.draw(self)  
end

function Movable:displace(direction, penetration)
    if not self.jump_control then
        if self.on_ground then
            self.jumps_left = self.max_jumps
        end
        self.prev_dir = direction
    end

    if direction == 'left' then
        self.p.x = self.p.x - penetration
        self.v.x = 0
    elseif direction == 'right' then
        self.p.x = self.p.x + penetration
        self.v.x = 0
    elseif direction == 'up' then
        self.p.y = self.p.y - penetration
        self.v.y = 0
    else
        self.p.y = self.p.y + penetration
        self.v.y = 0
    end
end
