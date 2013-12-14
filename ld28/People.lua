People = class('People', Entity)

function People:init(x, y, settings)
    Entity.init(self, x, y, settings) 
    self.inner_ring = self.size/2
end

function People:update(dt)
    
end

function People:draw()
    love.graphics.setColor(32, 32, 32)

    love.graphics.setLineWidth(self.size/5)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setLineWidth(self.size/10)
    love.graphics.circle('line', self.x, self.y, self.size - self.inner_ring, 360)

    love.graphics.setColor(255, 255, 255)
end
