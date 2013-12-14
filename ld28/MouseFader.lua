MouseFader = class('MouseFader', Entity)

function MouseFader:init(x, y, settings)
    Entity.init(self, x, y, settings)

    self.alpha = 255
    self.size = 4
    timer:tween(1, self, {alpha = 0}, 'in-out-cubic')
    timer:tween(1, self, {size = math.prandom(15, 20)}, 'in-out-cubic')
    timer:after(4, function() self.dead = true end)
end

function MouseFader:update(dt)
    
end

function MouseFader:draw()
    love.graphics.setColor(self.color[1], self.color[2], self.color[3], self.alpha)
    love.graphics.setLineWidth(2)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
