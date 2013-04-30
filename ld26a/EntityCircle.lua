require 'collisions'

EntityCircle = class('EntityCircle')

function EntityCircle:initialize(world, body_type, x, y, r)
    self.id = getID()
    self.dead = false
    self.body = love.physics.newBody(world, x, y, body_type)
    self.shape = love.physics.newCircleShape(r)
    self.fixture = love.physics.newFixture(self.body, self.shape)
    self.fixture:setCategory(unpack(collision_masks[self.class.name].categories))
    self.fixture:setMask(unpack(collision_masks[self.class.name].masks))
    self.fixture:setUserData(self)

    self.body:setFixedRotation(true)

    self.sensor = love.physics.newFixture(self.body, self.shape)
    self.sensor:setSensor(true)
    self.sensor:setUserData(self)
end

function EntityCircle:update(dt)
    
end

function EntityCircle:draw()
    local x, y = self.body:getPosition()
    love.graphics.circle('line', x, y, self.shape:getRadius())
end



