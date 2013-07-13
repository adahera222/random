ActorVisual = {
    visualInit = function(self, animations, offset_x, offset_y)
        self.animations = {}
        for k, anim in pairs(animations) do
            self.animations[k] = newAnimation(anim.source, anim.w, anim.h, anim.delay, 0)
            if anim.mode then self.animations[k]:setMode(anim.mode) end
        end
        self.offset_x = offset_x
        self.offset_y = offset_y
    end,

    visualUpdate = function(self, dt)
        local vx, vy = self.body:getLinearVelocity()

        if vx ~= 0 then
            if self.direction == 'left' then self.animations.walk_left:update(dt)
            elseif self.direction == 'right' then self.animations.walk_right:update(dt) end
        else
            if self.direction == 'left' then self.animations.idle_left:update(dt)
            elseif self.direction == 'right' then self.animations.idle_right:update(dt) end
        end

        if vy ~= 0 then
            if self.direction == 'up' then self.animations.walk_up:update(dt)
            elseif self.direction == 'down' then self.animations.walk_down:update(dt) end
        else 
            if self.direction == 'up' then self.animations.idle_up:update(dt)
            elseif self.direction == 'down' then self.animations.idle_down:update(dt) end
        end
    end,

    visualDraw = function(self)
        local x, y = self.body:getPosition()
        x, y = x - self.w/2 - self.offset_x, y - self.h/2 - self.offset_y
        local vx, vy = self.body:getLinearVelocity()

        if vx ~= 0 then
            if self.direction == 'left' then self.animations.walk_left:draw(x, y)
            elseif self.direction == 'right' then self.animations.walk_right:draw(x, y) end
        else
            if self.direction == 'left' then self.animations.idle_left:draw(x, y) 
            elseif self.direction == 'right' then self.animations.idle_right:draw(x, y) end
        end

        if vy ~= 0 then
            if self.direction == 'up' then self.animations.walk_up:draw(x, y)
            elseif self.direction == 'down' then self.animations.walk_down:draw(x, y) end
        else
            if self.direction == 'up' then self.animations.idle_up:draw(x, y) 
            elseif self.direction == 'down' then self.animations.idle_down:draw(x, y) end
        end
    end
}
