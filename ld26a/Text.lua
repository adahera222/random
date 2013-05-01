Text = class('Text')

function Text:initialize(text, x, y, v, angle, parent)
    self.text = text
    self.parent = parent
    self.x = x - 16
    if self.text == 'SLOWED' then self.y = y + 8
    else self.y = y - 64 end
    self.v = v
    self.angle = angle
    self.alpha = 224

    tween(1, self, {v = 0}, 'inOutCubic')
    tween(1, self, {alpha = 0}, 'inOutCubic')
    if self.text ~= 'SLOWED' then
        self.scale = 2
        tween(0.5, self, {scale = 1}, 'outQuad')
    end
end

function Text:update(dt)
    if self.text ~= 'SLOWED' then
        self.x = self.x + self.v*math.cos(self.angle)*dt
        self.y = self.y + self.v*math.sin(self.angle)*dt
    else
        if self.parent then
            if not self.parent.dead then
                local x, y = self.parent.body:getPosition()
                self.x = x - 36
                self.y = self.y + self.v*math.sin(self.angle)*dt
            end
        end
    end
end

function Text:draw()
    love.graphics.setFont(font12)
    local r, g, b, a = love.graphics.getColor()
    love.graphics.setColor(0, 0, 0, self.alpha)
    if self.text ~= 'SLOWED' then
        love.graphics.print(self.text, self.x, self.y, 0, self.scale, self.scale)    
    else love.graphics.print(self.text, self.x, self.y) end
    love.graphics.setColor(r, g, b, a)
end
