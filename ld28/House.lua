House = class('House', Entity)

function House:init(x, y, settings)
    Entity.init(self, x, y, settings) 
    self.alpha = 0
    timer:tween(2, self, {alpha = 255}, 'in-out-cubic')
end

function House:update(dt)

end

function House:draw()
    love.graphics.setLineWidth(1)
    love.graphics.setColor(132, 132, 132, self.alpha)
    pushRotate(self.x, self.y, self.angle)
    love.graphics.rectangle('line', self.x, self.y, self.w, self.h)
    love.graphics.pop()
    love.graphics.setColor(255, 255, 255, 255)
end
