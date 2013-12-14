PeopleFader = class('PeopleFader', Entity)

function PeopleFader:init(x, y, settings)
    Entity.init(self, x, y, settings)

    self.alpha = 0
    self.line_width = self.size/5
    timer:tween(1, self, {alpha = 255})
    timer:after(1, function()
        timer:tween(2, self, {alpha = 0}, 'in-out-cubic')
    end)
    timer:tween(3, self, {line_width = 2}, 'in-out-cubic')
    timer:tween(3, self, {size = 0}, 'in-out-cubic')
    timer:after(4, function() self.dead = true end)
end

function PeopleFader:update(dt)
    
end

function PeopleFader:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, self.alpha)
end
