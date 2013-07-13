PhysicsRectangle = {
    physicsRectangleInit = function(self, world, x, y, body_type, w, h, not_collidable)
        self.w = w
        self.h = h
        self.body = love.physics.newBody(world, x, y, body_type)
        self.shape = love.physics.newRectangleShape(w, h)

        if not_collidable then
            self.fixture = love.physics.newFixture(self.body, self.shape)
            self.fixture:setCategory(unpack(collision_masks['NotCollidable'].categories))
            self.fixture:setMask(unpack(collision_masks['NotCollidable'].masks))
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

    physicsRectangleDraw = function(self)
        love.graphics.setColor(192, 128, 64)
        love.graphics.polygon('line', self.body:getWorldPoints(self.shape:getPoints()))
        love.graphics.setColor(255, 255, 255)
    end
}
