require 'Movable'

Enemy = class('Enemy', Movable)

function Enemy:initialize(enemy_type, x, y, flee_radius)
    if enemy_type == 'child' then
        Movable.initialize(self, x, y, 16, 16, 500, Vector(200, 200), 0.90, 400, -200, 1)
        self.image = gl.child
    else
        Movable.initialize(self, x, y, 32, 32, 200, Vector(400, 400), 0.90, 400, -50, 1)
        self.image = gl.person_normal
    end

    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    self.speaking = false
    self.jump_delay = 5
    self.jump_t = 0
    self.can_jump = false
    self.yay = gl.yay

    -- Flee
    self.desired_velocity = Vector()
    self.steering = Vector()
    self.steering_force = Vector()
    self.flee_radius = flee_radius
    self.fleeing = false
end

function Enemy:update(dt, player)
    Movable.update(self, dt)
    self:behavior(dt, player.p)
    self:flee(player.p)

    self.steering_force.x = math.min(self.steering.x, 500)
    self.a.x = self.steering_force.x
    self.v.x = math.min(self.v.x + self.a.x*dt, self.max_v)
    self.p.x = self.p.x + self.v.x*dt
end

function Enemy:speak()
    if self.speaking then
        love.graphics.draw(self.yay, self.p.x - self.w/4, self.p.y - 2*self.h)
    end
end

function Enemy:behavior(dt, target)
    if self.on_ground then self.speaking = false end

    if self.can_jump then
        beholder:trigger('jump' .. self.id)
        self.can_jump = false
        self.speaking = true
    end

    if self.jump_t >= self.jump_delay then
        self.can_jump = true
        self.jump_t = 0
        if self.fleeing then
            local distance = math.abs(self.p.x - target.x)
            self.jump_delay = math.random(distance, 3*distance)/100
        else self.jump_delay = math.random(100, 500)/100 end
    end

    self.jump_t = self.jump_t + dt
end

function Enemy:flee(target)
    self.desired_velocity.x = self.p.x - target.x
    local distance = math.abs(self.desired_velocity.x)

    if distance < self.flee_radius then
        self.fleeing = true
        self.desired_velocity = 
        self.desired_velocity:normalized()*self.max_v*(1-(distance/self.flee_radius))
    else
        self.fleeing = false
        self.desired_velocity.x = 0
    end
   
    self.steering.x = self.desired_velocity.x - self.v.x
end

function Enemy:draw()
    Movable.draw(self)
    self:speak()
    love.graphics.setColor(255, 0, 0)
    love.graphics.circle('line', self.p.x, self.p.y, self.flee_radius)
    love.graphics.setColor(255, 255, 255)
end
