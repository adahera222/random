PhysicsRectangle = {
    physicsRectangleInit = function(self, world, x, y, body_type, w, h, other)
        self.w = w
        self.h = h
        self.body = love.physics.newBody(world, x, y, body_type)
        self.shape = love.physics.newRectangleShape(w, h)

        if other then
            self.fixture = love.physics.newFixture(self.body, self.shape)
            self.fixture:setCategory(unpack(collision_masks[other].categories))
            self.fixture:setMask(unpack(collision_masks[other].masks))
            self.fixture:setUserData(self)
        else
            self.fixture = love.physics.newFixture(self.body, self.shape)
            self.fixture:setCategory(unpack(collision_masks[self.class.name].categories))
            self.fixture:setMask(unpack(collision_masks[self.class.name].masks))
            self.fixture:setUserData(self)
        end

        self.sensor = love.physics.newFixture(self.body, self.shape)
        self.sensor:setSensor(true)
        self.sensor:setUserData(self)
    end,

    addFixture = function(self, x, y, w, h, other)
        self.nshape = love.physics.newRectangleShape(x, y, w, h)
        self.nfixture = love.physics.newFixture(self.body, self.nshape)
        if other then
            self.nfixture:setCategory(unpack(collision_masks[other].categories))
            self.nfixture:setMask(unpack(collision_masks[other].masks))
        else
            self.nfixture:setCategory(unpack(collision_masks[self.class.name].categories))
            self.nfixture:setMask(unpack(collision_masks[self.class.name].masks))
        end
        self.nfixture:setUserData(self)
        self.nsensor = love.physics.newFixture(self.body, self.nshape)
        self.nsensor:setSensor(true)
        self.nsensor:setUserData(self)
    end,

    physicsRectangleDraw = function(self)
        love.graphics.setColor(64, 128, 244)
        love.graphics.polygon('line', self.body:getWorldPoints(self.shape:getPoints()))
        love.graphics.setColor(255, 255, 255)

        if self.nshape then
            love.graphics.setColor(64, 128, 244)
            love.graphics.polygon('line', self.body:getWorldPoints(self.nshape:getPoints()))
            love.graphics.setColor(255, 255, 255)
        end
    end
}
