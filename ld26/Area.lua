require 'EntityCircle'

Area = class('Area', EntityCircle)

function Area:initialize(world, x, y, parent, logic)
    EntityCircle.initialize(self, world, 'dynamic', x, y, logic.r_i)
    self.body:setGravityScale(0)

    self.parent = parent
    self.logic = logic
    self.current_r = logic.r_i
    self.can_attack = true

    if self.logic.on_hit then
        tween(self.logic.duration, self, {current_r = self.logic.r_f}, self.logic.tween)
        chrono:after(self.logic.duration, function() self.dead = true end)
    end

    self.query_enemies_list = {}
    beholder.observe('ENEMIES LIST REPLY' .. self.id, function(list) self.query_enemies_list = list end)
end

function Area:collisionSolid(nx, ny)

end

function Area:collisionEnemy(enemy)
    enemy.slowed = false
end

function Area:query()
    beholder.trigger('ENEMIES LIST REQUEST', self.id)
    for _, enemy in ipairs(self.query_enemies_list) do
        local x, y = self.body:getPosition()
        local ex, ey = enemy.body:getPosition()
        local dx, dy = math.abs(x - ex), math.abs(y - ey)
        local d = math.sqrt(dx*dx + dy*dy)
        if d < self.shape:getRadius() then
            if self.logic.slow then
                enemy:setSlow(self.logic.slow)
            end

            if self.logic.damage then
                if self.can_attack then
                    self.can_attack = false
                    chrono:after(self.logic.cooldown, function() self.can_attack = true end)
                    enemy:takeDamage(self.logic.damage)
                end
            end
        end
    end
end

function Area:update(dt)
    EntityCircle.update(self, dt)
    self.shape:setRadius(self.current_r)
    self:query()

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
