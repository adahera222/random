City = class('City', Entity)

function City:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.alpha = 0
    self.selected = false
    self.hovering = false
    self.color = {32, 32, 32}
    timer:tween(4, self, {alpha = 255}, 'in-out-cubic')
    timer:every(math.prandom(15, 35), function()
        local x, y = randomInCircle(self.size)
        table.insert(game.resources, Resource(self.ref.x + x, self.ref.y + y, {size = math.prandom(10, self.size/10)}))
    end)
    timer:after(math.prandom(15, 35), function()
        local x, y = randomInCircle(self.size)
        table.insert(game.people, People(self.ref.x + x, self.ref.y + y, {size = math.prandom(10, self.size/10)}))
    end)
    self.line_width = self.size/14
    timer:every(4, function()
        timer:tween(4, self, {line_width = self.size/20}, 'out-elastic')
        timer:after(2, function()
            timer:tween(4, self, {line_width = self.size/14}, 'in-out-cubic')
        end)
    end)
    self.tid_1 = nil
    self.tid_2 = nil
    self.cities = {}
end

function City:update(dt)
    if mouseCollidingCity(self) then 
        if not self.hovering then
            self.hovering = true
            if self.tid_2 then timer:cancel(self.tid_2) end
            self.tid_1 = timer:tween(1, self, {color = {200, 200, 200}}, 'in-out-cubic')
        end
    else 
        if self.hovering then
            if not mouse.active then
                self.hovering = false
                if self.tid_1 then timer:cancel(self.tid_1) end
                self.tid_2 = timer:tween(1, self, {color = {32, 32, 32}}, 'in-out-cubic')
            end
        end
    end
end

function City:addCity(city)
    for _, c in ipairs(self.cities) do
        if c.id == city.id then return end
    end
    if city.id == self.id then return end
    table.insert(self.cities, city)
    self:changeSize(self.size + city.size/4)
end

function City:changeSize(new_size, time)
    timer:tween(time or 1, self, {size = new_size}, 'out-elastic')
end

function City:draw()
    love.graphics.setColor(self.color[1], self.color[2], self.color[3], self.alpha)
    love.graphics.setLineWidth(self.line_width)
    love.graphics.circle('line', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
