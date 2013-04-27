require 'EntityRect'

Enemy = class('Enemy', EntityRect)

function Enemy:initialize(world, x, y, w, h)
    EntityRect.initialize(self, world, 'dynamic', x, y, w, h)

    self.v = 100
    local directions = {'left', 'right'}
    self.direction = directions[math.random(1, 2)]

    self.hp = 100
end

function Enemy:collisionSolid(nx, ny)
    if nx == physics_meter then self.direction = 'right' end
    if nx == -physics_meter then self.direction = 'left' end
end

function Enemy:collisionProjectile(projectile)
    self.hp = self.hp - projectile.modifiers.damage
    if self.hp <= 0 then self.dead = true end
end


function Enemy:update(dt)
    EntityRect.update(self, dt)

    local v_x, v_y = self.body:getLinearVelocity()
    if self.direction == 'left' then self.body:setLinearVelocity(-self.v, v_y)
    else self.body:setLinearVelocity(self.v, v_y) end
end

function Enemy:draw()
    EntityRect.draw(self) 
end
