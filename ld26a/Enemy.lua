require 'EntityRect'

Enemy = class('Enemy', EntityRect)

function Enemy:initialize(world, x, y, w, h, v, hp, direction)
    EntityRect.initialize(self, world, 'dynamic', x, y, w, h)

    self.w = w
    self.v = v
    self.init_v = v
    self.direction = direction
    self.hp = hp
    self.slowed = false

    beholder.observe('UNSLOW' .. self.id, function() self.slowed = false print(self.id, self.slowed) end)
end

function Enemy:takeDamage(value)
    self.hp = self.hp - value
    if self.hp <= 0 then
        local x, y = self.body:getPosition()
        beholder.trigger('SPAWN', 'EnemyDead', x, y)
        self.dead = true 
        enemies_killed = enemies_killed + 1 
    end
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
    if ny == physics_meter or ny == -physics_meter then
        if self.w >= 40 then beholder.trigger('SHAKE', 5, 0.5) end
    end
end

function Enemy:collisionProjectile(projectile)
    self:takeDamage(projectile.modifiers.damage)
end

function Enemy:update(dt)
    EntityRect.update(self, dt)

    local v_x, v_y = self.body:getLinearVelocity()
    if self.direction == 'left' then self.body:setLinearVelocity(-self.v, v_y)
    else self.body:setLinearVelocity(self.v, v_y) end

    if not self.slowed then self.v = self.init_v end

    local x, y = self.body:getPosition()
    if y >= 872 then self.body:setPosition(x, -32) end
end

function Enemy:draw()
    EntityRect.draw(self, 'enemy') 
end
