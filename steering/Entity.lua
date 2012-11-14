require 'Vector'

Entity = {}
Entity.__index = Entity

function Entity.new(w, h, p, v, mass, max_v, max_f)
    return setmetatable({
        position = p or Vector(0, 0), 
        velocity = v or Vector(0, 0),
        desired_velocity = Vector(0, 0),
        mass = mass,
        acceleration = Vector(0, 0),
        steering = Vector(0, 0),
        steering_force = Vector(0, 0),
        max_velocity = max_v or 0,
        max_force = max_f or 0,
        width = w, height = h
    }, Entity)
end

-- target: Vector
function Entity:update(dt, target)
    self:arrival(target, 200)

    -- Base
    self.steering_force = self.steering:min(self.max_force)
    self.acceleration = self.steering_force/self.mass
    self.velocity = (self.velocity + self.acceleration*dt):min(self.max_velocity)
    self.position = self.position + self.velocity*dt
end

function Entity:seek(target)
    self.desired_velocity = (target - self.position):normalized()*self.max_velocity
    self.steering = self.desired_velocity - self.velocity
end

function Entity:flee(target)
    self.desired_velocity = (self.position - target):normalized()*self.max_velocity
    self.steering = self.desired_velocity - self.velocity
end

function Entity:arrival(target, slowingRadius)
    self.desired_velocity = (target - self.position)
    local distance = self.desired_velocity:len()

    if distance < slowingRadius then
        self.desired_velocity = self.desired_velocity:normalized()*self.max_velocity*(distance/slowingRadius)
    else self.desired_velocity = self.desired_velocity:normalized()*self.max_velocity end

    self.steering = self.desired_velocity - self.velocity
end

function Entity:draw()

    -- Draw entity
    love.graphics.setColor(255, 0, 0)
    love.graphics.rectangle('fill', 
    self.position.x - self.width/2, self.position.y - self.height/2, 
    self.width, self.height)

    -- Draw velocity vector
    love.graphics.setColor(0, 255, 0)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.velocity.x, self.position.y + self.velocity.y)

    -- Draw desired velocity vector
    love.graphics.setColor(0, 0, 0)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.desired_velocity.x, self.position.y + self.desired_velocity.y)

    -- Draw steering vector
    love.graphics.setColor(0, 0, 255)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.acceleration.x, self.position.y + self.acceleration.y)

    love.graphics.setColor(0, 0, 0)
end

setmetatable(Entity, {__call = function(_, ...) return Entity.new(...) end})
