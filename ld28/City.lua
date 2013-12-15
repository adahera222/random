City = class('City', Entity)

function City:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.alpha = 0
    timer:tween(4, self, {alpha = 255}, 'in-out-cubic')
    timer:every(math.prandom(25, 45), function()
        local x, y = randomInCircle(self.size)
        table.insert(game.resources, Resource(self.ref.x + x, self.ref.y + y, {size = math.prandom(10, self.size/10)}))
    end)
end

function City:update(dt)
    
end

function City:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.setLineWidth(self.size/14)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end