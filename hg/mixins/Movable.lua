Movable = {
    movableInit = function(self, max_v)
        self.direction = 'down'
        self.max_v = max_v
        self.moving = {left = false, right = false, up = false, down = false}

        self:collectorAddMessage(beholder.observe('MOVE LEFT' .. self.id, function() self.moving.left = true end))
        self:collectorAddMessage(beholder.observe('MOVE RIGHT' .. self.id, function() self.moving.right = true end))
        self:collectorAddMessage(beholder.observe('MOVE UP' .. self.id, function() self.moving.up = true end))
        self:collectorAddMessage(beholder.observe('MOVE DOWN' .. self.id, function() self.moving.down = true end))
    end,

    movableUpdate = function(self, dt)
        local x, y = self.body:getPosition()
        local vx, vy = self.body:getLinearVelocity()

        if self.moving.left then
            self.direction = 'left'
            self.body:setLinearVelocity(-self.max_v, vy)
            vx = -self.max_v
        end

        if self.moving.right then
            self.direction = 'right'
            self.body:setLinearVelocity(self.max_v, vy)
            vx = self.max_v
        end

        if self.moving.up then
            self.direction = 'up'
            if self.moving.left then
                self.body:setLinearVelocity(math.cos(math.pi/4)*vx, -math.sin(math.pi/4)*self.max_v)
            elseif self.moving.right then
                self.body:setLinearVelocity(-math.cos(3*math.pi/4)*vx, -math.sin(3*math.pi/4)*self.max_v)
            else
                self.body:setLinearVelocity(vx, self.max_v)
            end
            vy = -self.max_v
        end

        if self.moving.down then
            self.direction = 'down'
            if self.moving.left then
                self.body:setLinearVelocity(-math.cos(3*math.pi/4)*vx, math.sin(3*math.pi/4)*self.max_v)
            elseif self.moving.right then
                self.body:setLinearVelocity(math.cos(math.pi/4)*vx, math.sin(math.pi/4)*self.max_v)
            else
                self.body:setLinearVelocity(vx, self.max_v)
            end
            vy = self.max_v
        end

        if not self.moving.left and not self.moving.right then
            self.body:setLinearVelocity(0, vy)
            vx = 0
        end

        if not self.moving.up and not self.moving.down then
            self.body:setLinearVelocity(vx, 0)
            vy = 0
        end

        self.moving.left = false
        self.moving.right = false
        self.moving.up = false
        self.moving.down = false
    end
}
