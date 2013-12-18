PeopleParticle = class('PeopleParticle', Entity)

function PeopleParticle:init(x, y, settings)
    Entity.init(self, x, y, settings)
    
    self.alpha = 0
    local r = math.prandom(0.5, 1.5)
    timer:tween(r, self, {alpha = 255}, 'in-out-cubic')
    local n = math.prandom(1, 4)
    timer:tween(n, self, {size = 0}, 'in-out-cubic')
    timer:after(r, function()
        timer:tween(n, self, {alpha = 0}, 'in-out-cubic')
    end)
    timer:after(2*n, function() self.dead = true end)
    self.angle = math.prandom(0, 2*math.pi)
    local ar = math.prandom(10, 50)
    self.a = Vector(ar*math.cos(self.angle), ar*math.sin(self.angle))
    self.v = Vector(0, 0)
end

function PeopleParticle:update(dt)
    self.v = self.v + self.a*dt
    self.x, self.y = self.x + self.v.x*dt, self.y + self.v.y*dt
end

function PeopleParticle:draw()
    love.graphics.setColor(32, 32, 32, self.alpha)
    love.graphics.circle('fill', self.x, self.y, self.size, 360)
    love.graphics.setColor(255, 255, 255, 255)
end
