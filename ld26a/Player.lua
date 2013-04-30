require 'EntityRect'
require 'Attack'
require 'attacks'

Player = class('Player', EntityRect)

function Player:initialize(world)
    EntityRect.initialize(self, world, 'dynamic', 212+300, 212+32, 16, 16)

    self.v = 250
    self.jump_v = -300
    self.max_jumps = 1

    self.moving = {left = false, right = false}
    self.colliding = {left = false, right = false}
    self.jump_impulse = false
    self.jumping = false
    self.falling = false
    self.ground = false

    self.direction = 'right'
    self.jumps_left = self.max_jumps

    self.attack = initial_attack
end

function Player:collisionEnemy()
    if not game_over then
        game_over = true
    end
end

function Player:collisionSolid(type, nx, ny)
    if type == 'enter' then
        if ny == physics_meter then self.ground = true end
        if nx == -physics_meter then self.colliding.left = true end
        if nx == physics_meter then self.colliding.right = true end
    
    else
        self.colliding.left = false
        self.colliding.right = false
    end
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
        self.jump_impulse = true
    end

    if love.keyboard.isDown('j') or love.keyboard.isDown('z') then
        local angle
        if self.direction == 'left' then angle = math.pi
        elseif self.direction == 'right' then angle = 0 end
        local x, y = self.body:getPosition()
        self.attack:attack(x, y, angle, 'hold')
    end

    local v_x, v_y = self.body:getLinearVelocity()
    if self.moving.right then
        if not self.colliding.right then
            self.body:setLinearVelocity(self.v, v_y)
            self.direction = 'right'
        end
    end
    if self.moving.left then
        if not self.colliding.left then
            self.body:setLinearVelocity(-self.v, v_y)
            self.direction = 'left'
        end
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

    local x, y = self.body:getPosition()
    if y >= 872 then self.body:setPosition(x, -32) end
end

function Player:draw()
    EntityRect.draw(self, 'player')
end

function Player:keypressed(key)
    if key == 'up' or key == 'w' then self.jump_impulse = true end
    if key == 'j' or key == 'z' then
        local angle
        if self.direction == 'left' then angle = math.pi
        elseif self.direction == 'right' then angle = 0 end
        local x, y = self.body:getPosition()
        self.attack:attack(x, y, angle, 'hold')
    end
end
