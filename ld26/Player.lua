require 'EntityRect'

Player = class('Player', EntityRect)

function Player:initialize(world)
    EntityRect.initialize(self, world, 'dynamic', 400, 300, 16, 16)

    self.v = 200
    self.jump_v = -200
    self.max_jumps = 1

    self.moving = {left = false, right = false}
    self.jump_impulse = false
    self.jumping = false
    self.falling = false
    self.ground = false

    self.direction = 'right'
    self.jumps_left = self.max_jumps
end

function Player:collisionSolid(solid, nx, ny)
    if ny == 32 then self.ground = true end
end

function Player:update(dt)
    EntityRect.update(self, dt)

    if love.keyboard.isDown('left') or love.keyboard.isDown('a') then
        self.moving.left = true
    end
    if love.keyboard.isDown('right') or love.keyboard.isDown('d') then
        self.moving.right = true
    end
    if love.keyboard.isDown('up') or love.keyboard.isDown('w') then
        self.jumping = true
    end

    local v_x, v_y = self.body:getLinearVelocity()
    if self.moving.right then
        self.body:setLinearVelocity(self.v, v_y)
        self.direction = 'right'
    end
    if self.moving.left then
        self.body:setLinearVelocity(-self.v, v_y)
        self.direction = 'left'
    end
    if not self.moving.right and not self.moving.left then
        self.body:setLinearVelocity(0, v_y)
    end

    local v_x, v_y = self.body:getLinearVelocity()
    if self.jump_impulse then
        if self.jumps_left > 0 then
            self.body:setLinearVelocity(v_x, self.jump_v)
            self.ground = false
            self.jumps_left = self.jumps_left - 1
        end
    end

    local v_x, v_y = self.body:getLinearVelocity()
    if v_y > 0 then self.falling = true end
    if not self.jumping and not self.falling then
        self.body:setLinearVelocity(v_x, 0)
    end

    if self.ground then self.jumps_left = self.max_jumps end

    self.moving.left = false
    self.moving.right = false
    self.jump_impulse = false
    self.jumping = false
    self.falling = false
end

function Player:draw()
    EntityRect.draw(self)
end

function Player:keypressed(key)
    if key == 'up' or key == 'w' then self.jump_impulse = true end
end


