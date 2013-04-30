require 'EntityRect'

Projectile = class('Projectile', EntityRect)

function Projectile:initialize(world, x, y, angle, modifiers)
    EntityRect.initialize(self, world, 'dynamic', x, y, 4, 4)
    self.body:setGravityScale(0)

    self.modifiers = copy(modifiers)

    self.angle = angle
    self.v = modifiers.speed
end

function Projectile:collisionSolid(nx, ny)
    local dir = nil
    if nx < 0 and ny == 0 then dir = 'left'
    elseif nx > 0 and ny == 0 then dir = 'right'
    elseif ny < 0 and nx == 0 then dir = 'up'
    elseif ny > 0 and nx == 0 then dir = 'down' end

    if self.modifiers.reflect then
        self.modifiers.reflect = self.modifiers.reflect - 1
        if dir == 'left' or dir == 'right' then self.angle = math.pi - self.angle
        elseif dir == 'up' or dir == 'down' then self.angle = -self.angle end
        if self.modifiers.reflect < 0 then self.modifiers.reflect = nil end
    end

    if self.modifiers.area then
        if areas[self.modifiers.area].on_hit then
            local x, y = self.body:getPosition()
            beholder.trigger('CREATE AREA', x, y, self, areas[self.modifiers.area])
        end
    end

    if not self.modifiers.reflect then self.dead = true end 
end

function Projectile:collisionEnemy(enemy)
    if self.modifiers.pierce then
        self.modifiers.pierce = self.modifiers.pierce - 1
        if self.modifiers.pierce < 0 then self.modifiers.pierce = nil end
    end

    if self.modifiers.area then
        if areas[self.modifiers.area].on_hit then
            local x, y = self.body:getPosition()
            beholder.trigger('CREATE AREA', x, y, false, areas[self.modifiers.area])
        end
    end

    if not self.modifiers.pierce then self.dead = true end
end


function Projectile:update(dt)
    EntityRect.update(self, dt)    

    local x, y = self.body:getPosition()
    self.body:setPosition(x + math.cos(self.angle)*self.v*dt, y + math.sin(self.angle)*self.v*dt)
end

function Projectile:draw()
    EntityRect.draw(self)
end
