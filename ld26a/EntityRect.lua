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

function EntityRect:draw(type)
    love.graphics.setColor(0, 0, 0)
    local x1, y1, x2, y2, x3, y3, x4, y4 = self.body:getWorldPoints(self.shape:getPoints())
    if type == 'player' then 
        love.graphics.setLineWidth(2)
        love.graphics.setColor(255, 192, 255) 
    end
    love.graphics.rectangle('line', x1, y1, x3-x1, y3-y1)
    love.graphics.setLineWidth(1)
    -- love.graphics.rectangle('fill', x1+3, y1+3, x3-x1-6, y3-y1-6)
end


