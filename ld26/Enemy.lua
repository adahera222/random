require 'EntityRect'

Enemy = class('Enemy', EntityRect)

function Enemy:initialize(world, x, y, w, h)
    EntityRect.initialize(self, world, 'dynamic', x, y, w, h)

    self.v = 100
    self.init_v = 100
    local directions = {'left', 'right'}
    self.direction = directions[math.random(1, 2)]

    self.hp = 100
end

function Enemy:takeDamage(value)
    self.hp = self.hp - value
    if self.hp <= 0 then self.dead = true; enemies_killed = enemies_killed + 1 end
    local x, y = self.body:getPosition()
    beholder.trigger('DAMAGE POP', value, x, y)
end

function Enemy:setSlow(value)
    if not self.slowed then
        self.slowed = true
        self.v = self.init_v*value
        local x, y = self.body:getPosition()
        beholder.trigger('TEXT POP', 'SLOWED', x, y, self)
    end
end

function Enemy:collisionSolid(nx, ny)
    if nx == physics_meter then self.direction = 'right' end
    if nx == -physics_meter then self.direction = 'left' end
end

function Enemy:collisionProjectile(projectile)
    self:takeDamage(projectile.modifiers.damage)
end

function Enemy:update(dt)
    EntityRect.update(self, dt)

    local v_x, v_y = self.body:getLinearVelocity()
    if self.direction == 'left' then self.body:setLinearVelocity(-self.v, v_y)
    else self.body:setLinearVelocity(self.v, v_y) end

    self.v = self.init_v

    local x, y = self.body:getPosition()
    if y >= 212+448-16 then self.dead = true; enemy_counter = enemy_counter - 1 end
end

function Enemy:draw()
    EntityRect.draw(self) 
end
