require 'Entity'

Movable = class('Movable', Entity)

function Movable:initialize(x, y, w, h, max_v, a, damping)
    Entity.initialize(self, gl.entity_id(), x, y, w, h)

    self.v = Vector()
    self.max_v = max_v
    self.max_fall = 200
    self.a = a
    self.dmp = damping

    self.moving = {left = false, right = false}

    beholder:observe('move left' .. self.id,
                     function() self.moving.left = true end)
    beholder:observe('move right' .. self.id,
                     function() self.moving.right = true end)
    beholder:observe('displace movable' .. self.id,
                     function(direction, p) self:displace(direction, p) end)
end

function Movable:update(dt)
    Entity.update(self, dt)
    self:move(dt)
    self:gravity(dt)
    self.p.x = self.p.x + self.v.x*dt
    self.p.y = self.p.y + self.v.y*dt
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

    if not self.moving.left and not self.moving.right then
        self.v.x = self.v.x * self.dmp
    end

    self.moving.left = false
    self.moving.right = false
end

function Movable:gravity(dt)
    self.v.y = math.min(self.v.y + gl.gravity*dt, self.max_fall)
end

function Movable:draw()
    Entity.draw(self)  
end

function Movable:displace(direction, penetration)
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
