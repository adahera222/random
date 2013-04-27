EntityRect = class('EntityRect')

function EntityRect:initialize(self, world, body_type, x, y, w, h)
    self.body = love.physics.newBody(world, x, y, body_type)
    self.shape = love.graphics.newRectangleShape(w, h)

    self.fixture = love.physics.newFixture(self.body, self.shape)
end

function EntityRect:update(dt)
    
end

function EntityRect:draw()
    local x, y = self.body:getPosition()
    love.graphics.rectangle('line', x, y, w, h) 
end


