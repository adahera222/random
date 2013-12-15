Drain = class('Drain', Entity)

function Drain:init(x, y, settings)
    Entity.init(self, x, y, settings)
    self.alpha = 0
    timer:tween(2, self, {alpha = 128}, 'in-out-cubic')
end

function Drain:update(dt)
    
end

function Drain:draw()
    love.graphics.setColor(self.color[1], self.color[2], self.color[3], self.alpha)
    love.graphics.circle('fill', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
