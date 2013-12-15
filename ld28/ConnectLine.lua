ConnectLine = class('ConnectLine', Entity)

function ConnectLine:init(x, y, settings)
    Entity.init(self, x, y, settings)
    self.alpha = 255
    self.line_width = 0
    timer:tween(2, self, {line_width = 8}, 'out-elastic')
    timer:after(1, function() 
        timer:tween(2, self, {line_width = 3}, 'linear')
    end)
end

function ConnectLine:update(dt)
    
end

function ConnectLine:draw()
    if not self.src or not self.dst then return end
    love.graphics.setColor(32, 32, 32, self.alpha)
    local anglesd = Vector(self.src.x - self.dst.x, self.src.y - self.dst.y):angle()
    local angleds = Vector(self.dst.x - self.src.x, self.dst.y - self.src.y):angle()
    local sizes, sized = 1.5*self.src.size, 1.5*self.dst.size
    local x1, y1 = self.src.x - sizes*math.cos(anglesd), self.src.y - sizes*math.sin(anglesd)
    local x2, y2 = self.dst.x - sized*math.cos(angleds), self.dst.y - sized*math.sin(angleds)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.line(x1, y1, x2, y2)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.circle('line', x1, y1, 2, 360)
    love.graphics.circle('line', x2, y2, 2, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
