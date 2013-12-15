ActiveLine = class('ActiveLine', Entity)

function ActiveLine:init(x, y, settings)
    Entity.init(self, x, y, settings)
    self.active = false
end

function ActiveLine:update(dt)
    self.active = mouse.active
end

function ActiveLine:draw()
    if not self.active then return end
    love.graphics.setColor(64, 92, 232)
    love.graphics.setLineWidth(2)
    love.graphics.circle('line', self.x, self.y, 2, 360)
    local wx, wy = camera:worldCoords(mouse.x, mouse.y)
    love.graphics.line(self.x, self.y, wx, wy)
    love.graphics.setColor(255, 255, 255)
end
