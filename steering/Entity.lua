require 'Vector'
require 'middleclass'

Entity = class('Entity')

function Entity:initialize(w, h, p, v, mass, max_v, max_f)
    self.position = p or Vector(0, 0) 
    self.velocity = v or Vector(0, 0)
    self.desired_velocity = Vector(0, 0)
    self.mass = mass
    self.acceleration = Vector(0, 0)
    self.steering = Vector(0, 0)
    self.steering_force = Vector(0, 0)
    self.max_velocity = max_v or 0
    self.max_force = max_f or 0
    self.width = w 
    self.height = h
end

-- target: Vector
function Entity:update(dt, target)
    self[current_behavior](self, target, arrivalSlowingRadius)

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

function Entity:flee(target, fleeRadius)
    self.desired_velocity = (self.position - target)
    local distance = self.desired_velocity:len()

    if distance < fleeRadius then
        slowing = true
        self.desired_velocity = 
        self.desired_velocity:normalized()*self.max_velocity*(1-(distance/fleeRadius))

    else 
        slowing = false
        self.desired_velocity = Vector(0, 0)
    end

    self.steering = self.desired_velocity - self.velocity
end

function Entity:arrival(target, slowingRadius)
    self.desired_velocity = (target - self.position)
    local distance = self.desired_velocity:len()

    if distance < slowingRadius then
        slowing = true
        self.desired_velocity = 
        self.desired_velocity:normalized()*self.max_velocity*(distance/slowingRadius)
    else 
        slowing = false
        self.desired_velocity = 
        self.desired_velocity:normalized()*self.max_velocity 
    end

    self.steering = self.desired_velocity - self.velocity
end

function Entity:draw()

    -- Draw entity
    love.graphics.push()
    love.graphics.translate(self.position.x, self.position.y)
    love.graphics.rotate(self.velocity:angle())
    love.graphics.translate(-self.position.x, -self.position.y)
    love.graphics.setLineWidth(1.5)
    love.graphics.setColor(12, 25, 50)
    love.graphics.rectangle('line', 
    self.position.x - self.width/2, self.position.y - self.height/2, 
    self.width, self.height)
    love.graphics.setColor(50, 100, 200)
    love.graphics.rectangle('fill', 
    self.position.x - self.width/2, self.position.y - self.height/2, 
    self.width, self.height)
    love.graphics.pop()

    love.graphics.setLineWidth(1.2)

    -- Draw velocity vector
    love.graphics.setColor(0, 255, 0)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.velocity.x, self.position.y + self.velocity.y)

    -- Draw desired velocity vector
    love.graphics.setColor(0, 0, 0)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.desired_velocity.x, self.position.y + self.desired_velocity.y)

    -- Draw steering vector
    love.graphics.setColor(255, 0, 255)
    love.graphics.line(self.position.x, self.position.y,
    self.position.x + self.acceleration.x, self.position.y + self.acceleration.y)

    love.graphics.setLineWidth(1)
    love.graphics.setColor(0, 0, 0)
end
