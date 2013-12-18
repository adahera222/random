City = class('City', Entity)

function City:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.alpha = 0
    timer:tween(4, self, {alpha = 255}, 'in-out-cubic')
    timer:every(math.prandom(20, 40), function()
        local x, y = randomInCircle(self.size)
        table.insert(game.resources, Resource(self.ref.x + x, self.ref.y + y, {size = math.prandom(10, self.size/10)}))
    end)
    self.line_width = self.size/14
    timer:every(4, function()
        timer:tween(4, self, {line_width = self.size/40}, 'out-elastic')
        timer:after(2, function()
            timer:tween(4, self, {line_width = self.size/14}, 'in-out-cubic')
        end)
    end)
end

function City:update(dt)
    
end

function City:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
