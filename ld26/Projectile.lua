require 'EntityRect'

Projectile = class('Projectile', EntityRect)

function Projectile:initialize(world, x, y, angle, modifiers)
    EntityRect.initialize(self, world, 'dynamic', x, y, 4, 4)
    self.body:setGravityScale(0)

    self.modifiers = copy(modifiers)

    self.angle = angle
    self.v = 400
end

function Projectile:collisionSolid(nx, ny)
    local dir = nil
    if nx < 0 and ny == 0 then dir = 'left'
    elseif nx > 0 and ny == 0 then dir = 'right'
    elseif ny < 0 and nx == 0 then dir = 'up'
    elseif ny > 0 and nx == 0 then dir = 'down' end

    if self.modifiers.reflecting then
        self.modifiers.reflecting = self.modifiers.reflecting - 1
        if dir == 'left' or dir == 'right' then self.angle = math.pi - self.angle
        elseif dir == 'up' or dir == 'down' then self.angle = -self.angle end
        if self.modifiers.reflecting <= 0 then self.modifiers.reflecting = nil end
    end

    if not self.modifiers.reflecting then self.dead = true end 
end

function Projectile:update(dt)
    EntityRect.update(self, dt)    

    local x, y = self.body:getPosition()
    self.body:setPosition(x + math.cos(self.angle)*self.v*dt, y + math.sin(self.angle)*self.v*dt)
end

function Projectile:draw()
    EntityRect.draw(self)
end



