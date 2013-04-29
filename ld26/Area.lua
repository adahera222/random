require 'EntityCircle'

Area = class('Area', EntityCircle)

function Area:initialize(world, x, y, parent, logic)
    EntityCircle.initialize(self, world, 'dynamic', x, y, logic.r_i)
    self.body:setGravityScale(0)

    self.parent = parent
    self.logic = logic
    self.current_r = logic.r_i
    self.can_attack = true
    self.enemies_hit = {}

    if self.logic.on_hit then
        tween(self.logic.duration, self, {current_r = self.logic.r_f}, self.logic.tween)
        chrono:after(self.logic.duration, function() 
            self.dead = true 
            chrono:after(0.1, function()
                for _, e in ipairs(self.enemies_hit) do 
                    beholder.trigger('UNSLOW' .. e.enemy.id)
                end
            end)
        end)
    end

    self.query_enemies_list = {}
    beholder.observe('ENEMIES LIST REPLY' .. self.id, function(list) self.query_enemies_list = list end)
end

function Area:collisionSolid(nx, ny)

end

function Area:collisionEnemy(enemy)
    enemy.slowed = false
end

function Area:enemyOnCooldown(enemy, cooldown)
    for _, e in ipairs(self.enemies_hit) do
        if e.enemy.id == enemy.id then
            if (love.timer.getTime() - e.time) > cooldown then
                e.time = love.timer.getTime()
                return false
            else return true end
        end
    end
end

function Area:addEnemy(enemy)
    table.insert(self.enemies_hit, {enemy = enemy, time = -10000000})
end

function contains_enemy(t, v)
    for _, e in ipairs(t) do if v == e.enemy then return true end end
    return false
end

function Area:query()
    beholder.trigger('ENEMIES LIST REQUEST', self.id)
    for _, enemy in ipairs(self.query_enemies_list) do
        if not contains_enemy(self.enemies_hit, enemy) then self:addEnemy(enemy) end

        local x, y = self.body:getPosition()
        local ex, ey = enemy.body:getPosition()
        local dx, dy = math.abs(x - ex), math.abs(y - ey)
        local d = math.sqrt(dx*dx + dy*dy)
        if d < self.shape:getRadius() then
            if self.logic.slow then
                enemy:setSlow(self.logic.slow)
            end

            if self.logic.damage then
                if not self:enemyOnCooldown(enemy, self.logic.cooldown) then
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
