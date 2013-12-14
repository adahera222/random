ResourceFader = class('ResourceFader', Entity)

function ResourceFader:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.line_width = 2
    self.alpha = 0
    timer:tween(0.25, self, {alpha = 255})
    timer:after(0.5, function() 
        timer:tween(2, self, {alpha = 0}) 
        timer:tween(2, self, {size = self.size + self.size/3})
        timer:tween(1, self, {line_width = self.size/9})
    end)
    timer:after(4, function() self.dead = true end)
end

function ResourceFader:update(dt)
    
end

function ResourceFader:polygonize(size)
    if size then
        return {self.x - 0.8*size, self.y, self.x, self.y - size, 
                self.x + 0.8*size, self.y, self.x, self.y + size}
    else 
        return {self.x - 0.8*self.size, self.y, self.x, self.y - self.size, 
                self.x + 0.8*self.size, self.y, self.x, self.y + self.size}
    end
end

function ResourceFader:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.polygon('line', self:polygonize(self.size))
    love.graphics.setColor(255, 255, 255, 255)
end
