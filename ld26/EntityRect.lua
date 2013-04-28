require 'collisions'

EntityRect = class('EntityRect')

function EntityRect:initialize(world, body_type, x, y, w, h)
    self.id = getID()
    self.dead = false
    self.body = love.physics.newBody(world, x, y, body_type)
    self.shape = love.physics.newRectangleShape(w, h)
    self.fixture = love.physics.newFixture(self.body, self.shape)
    self.fixture:setCategory(unpack(collision_masks[self.class.name].categories))
    self.fixture:setMask(unpack(collision_masks[self.class.name].masks))
    self.fixture:setUserData(self)

    self.body:setFixedRotation(true)

    self.sensor = love.physics.newFixture(self.body, self.shape)
    self.sensor:setSensor(true)
    self.sensor:setUserData(self)
end

function EntityRect:update(dt)
    
end

function EntityRect:draw()
    love.graphics.setColor(0, 0, 0)
    love.graphics.polygon('line', self.body:getWorldPoints(self.shape:getPoints())) 
end


