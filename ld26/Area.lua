require 'EntityCircle'

Area = class('Area', EntityCircle)

function Area:initialize(world, x, y, parent, logic)
    EntityCircle.initialize(self, world, 'dynamic', x, y, logic.r_i)
    self.body:setGravityScale(0)

    self.parent = parent
    self.logic = logic
    self.current_r = logic.r_i

    if self.logic.on_hit then
        tween(self.logic.duration, self, {current_r = self.logic.r_f}, self.logic.tween)
        chrono:after(self.logic.duration, function() self.dead = true end)
    end
end

function Area:collisionSolid(nx, ny)

end

function Area:update(dt)
    EntityCircle.update(self, dt)
    self.shape:setRadius(self.current_r)

    if self.parent then
        if not self.parent.dead then
            self.body:setPosition(self.parent.body:getPosition())
        else 
            if not self.logic.on_hit then
                chrono:after(self.logic.duration, function() self.dead = true end)
            end
        end
    end
end

function Area:draw()
    EntityCircle.draw(self)
end



