ConnectLine = class('ConnectLine', Entity)

function ConnectLine:init(x, y, settings)
    Entity.init(self, x, y, settings)
    self.alpha = 255
    self.line_width = 0
    timer:tween(2, self, {line_width = 8}, 'out-elastic')
    timer:after(1, function() 
        timer:tween(2, self, {line_width = 3}, 'linear')
    end)
    self.dying = false
end

function ConnectLine:update(dt)

end

function ConnectLine:die()
    self.dying = true
    timer:tween(2, self, {alpha = 0}, 'in-out-cubic')
    timer:after(2, function() self.dead = true end)
end

function ConnectLine:draw()
    love.graphics.setLineWidth(self.line_width)
    if self.city then love.graphics.setLineWidth(3*self.line_width) end
    love.graphics.setColor(32, 32, 32, self.alpha)
    local d = Vector.distance(Vector(self.src.x, self.src.y), Vector(self.dst.x, self.dst.y))
    if d < 1.025*self.src.size + 1.025*self.dst.size then return end
    local anglesd = Vector(self.src.x - self.dst.x, self.src.y - self.dst.y):angle()
    local angleds = Vector(self.dst.x - self.src.x, self.dst.y - self.src.y):angle()
    local sizes, sized = 1.025*self.src.size, 1.025*self.dst.size
    local x1, y1 = self.src.x - sizes*math.cos(anglesd), self.src.y - sizes*math.sin(anglesd)
    local x2, y2 = self.dst.x - sized*math.cos(angleds), self.dst.y - sized*math.sin(angleds)
    love.graphics.line(x1, y1, x2, y2)
    love.graphics.circle('line', x1, y1, 2, 360)
    love.graphics.circle('line', x2, y2, 2, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
