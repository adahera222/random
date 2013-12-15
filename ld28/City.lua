City = class('City', Entity)

function City:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.alpha = 0
    timer:tween(4, self, {alpha = 255}, 'in-out-cubic')
end

function City:update(dt)
    
end

function City:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.size/14)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
