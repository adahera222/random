require 'Level'
require 'Enemy'

Room = class('Room', Level)

function Room:initialize(name, map, to_level, gun)
    Level.initialize(self, name, map)
    self.to_level = to_level

    if name == 'room_1' then self.player = Player(200, 100, gun)
    elseif name == 'room_2' then self.player = Player(600, 400, gun)
    elseif name == 'room_3' then self.player = Player(550, 600, gun)
    elseif name == 'room_4' then self.player = Player(448, 400, gun)
    elseif name == 'room_5' then self.player = Player(216, 900, gun) end

    self.camera = Camera({x1 = -self.width, y1 = -self.height, x2 = self.width, y2 = self.height})

    if name == 'room_3' then
        self:add(Enemy('person', 1100, 320, 100, self))
        self:add(Enemy('person', 1065, 320, 100, self))
        self:add(Enemy('person', 1000, 320, 100, self))

        self:add(Enemy('person', 1085, 490, 100, self))
        self:add(Enemy('person', 1035, 490, 100, self))
    end

    if name == 'room_4' then
        self:add(Enemy('person', 1100, 320, 100, self))
        self:add(Enemy('person', 1065, 320, 100, self))
        self:add(Enemy('person', 1000, 320, 100, self))

        self:add(Enemy('person', 1085, 490, 100, self))
        self:add(Enemy('person', 1035, 490, 100, self))
        self:add(Enemy('girl', 324, 170, 100, self))
    end

    if name == 'room_5' then
        self:add(Enemy('person', 1100, 320, 100, self))
        self:add(Enemy('person', 1065, 320, 100, self))
        self:add(Enemy('person', 1000, 320, 100, self))

        self:add(Enemy('person', 1085, 490, 100, self))
        self:add(Enemy('person', 1035, 490, 100, self))
        self:add(Enemy('girl', 324, 170, 100, self))

        self:spawnArea(3120, 336, 3440, 0, 3, 1)
        self:spawnArea(3120, 496, 3440, 0, 2, 1)
        self:spawnArea(3120, 656, 3440, 0, 2, 1)
        self:spawnArea(3120, 816, 3440, 0, 3, 1)
        self:spawnArea(3120, 976, 3440, 0, 2, 1)
        self:spawnArea(4048, 336, 3760, 0, 2, -1)
        self:spawnArea(4048, 496, 3760, 0, 3, -1)
        self:spawnArea(4048, 656, 3760, 0, 2, -1)
        self:spawnArea(4048, 816, 3760, 0, 2, -1)
        self:spawnArea(4048, 976, 3760, 0, 3, -1)
    end

    for _, tile in ipairs(self.tiles) do self.camera:add(1, tile.draw, tile) end
    for _, tile in ipairs(self.tiles_aux) do self.camera:add(1, tile.draw, tile) end
    for _, entity in ipairs(self.entities) do self.camera:add(1, entity.draw, entity) end

    if name == 'room_2' then self.mom = Enemy('mom', 1600, 50, 100, self)
    elseif name == 'room_3' or name == 'room_4' or name == 'room_5' then self.mom = Enemy('mom', 1600, 600, 100, self) end

    if name == 'room_2' or name == 'room_3' or name == 'room_4' or name == 'room_5' then self.camera:add(1, self.mom.draw, self.mom) end
    self.camera:add(1, self.player.draw, self.player)

    self.down_player_keys = {
        a = 'move left',
        d = 'move right',
        left = 'move left',
        right = 'move right',
    }

    self.press_player_keys = {
        w = 'jump',
        up = 'jump'
    }

    self.under_play = false
    self.talked_to_mom = false
    self.times_mom = 0
    self.mom_talk_delay = 5
    self.mom_talk_t = 0
    self.mom_talk_count = false
    self.mom_can_speak_to = true 
    self.talked_to_friends = false
    self.talked_to_girlfriend = false

    beholder:observe('create projectile', 
        function(r)
            if self.name == 'room_5' then
                local e = Projectile(self.player.p.x, self.player.p.y, r, 750)
                self:add(e)
                self.camera:add(1, e.draw, e)
            end
        end)

    self.everyone_dead = false
end

function Room:spawnArea(x, y, dx, min, max, dir)
    local n = math.random(min, max)
    for i = 1, n do
        local xx = 0
        if dir == 1 then
            xx = math.random(12, dx-x+12)
        else xx = math.random(12, x-dx+12) end
        self:add(Enemy('child', x+dir*xx, y-4, 500, self)) 
    end
end

function Room:update(dt)
    if self.name == 'room_5' then
        if #self.entities == 0 then self.everyone_dead = true end
    end

    for k, v in pairs(self.down_player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, tile in ipairs(self.tiles) do
        if self.player.p.x <= 3000 then
            self.player:collideWith(tile)
        end
        if self.name == 'room_2' or self.name == 'room_3' or self.name == 'room_4' or self.name == 'room_5' then
            if self.mom then self.mom:collideWith(tile) end
        end
        local entities = self:getInArea('entities', tile.p, 64)
        for _, entity in ipairs(entities) do
            if entity.p.x <= 3000 then
                entity:collideWith(tile)
            end
        end
    end

    for _, tile in ipairs(self.tiles_aux) do
        if self.player.p.x > 3000 then
            self.player:collideWith(tile)
        end

        local entities = self:getInArea('entities', tile.p, 64)
        for _, entity in ipairs(entities) do
            if entity.p.x > 3000 then
                entity:collideWith(tile)
            end
        end
    end

    for _, entity in ipairs(self.entities) do
        if instanceOf(Enemy, entity) then
            entity:update(dt, self.player)
            local projectiles = self:getInArea('entities', entity.p, 64)
            
            for _, proj in ipairs(projectiles) do
                if instanceOf(Projectile, proj) then
                    entity:collideWith(proj)
                end
            end
        else entity:update(dt) end

        if not entity.alive then 
            if instanceOf(Enemy, entity) then
                if not gl.hurts[2]:isStopped() then
                    gl.hurts[2]:rewind()
                end
                love.audio.play(gl.hurts[2])
            end
            self:remove(entity)
            self.camera:remove(1, entity)
        end
    end
    
    if self.name == 'room_2' or self.name == 'room_3' or self.name == 'room_4' or self.name == 'room_5' then 
        if self.mom then
            self.mom:update(dt, self.player) 
            local projs = self:getInArea('entities', self.mom.p, 64)
            for _, proj in ipairs(projs) do
                if instanceOf(Projectile, proj) then
                    self.mom:collideWith(proj)
                end
            end

            if not self.mom.alive then
                if not gl.hurts[2]:isStopped() then
                    gl.hurts[2]:rewind()
                end
                love.audio.play(gl.hurts[2])
                self.camera:remove(1, self.mom)
                self.mom = nil
            end
        end
    end

    self.player:update(dt, self.camera)
    self.camera:follow(dt, self.player)
    self.camera:update(dt)

    if self.name == 'room_1' or self.name == 'room_2' then
        if self.player.p.x >= 40 and self.player.p.x <= 48+128 then
            self.under_play = true
        else self.under_play = false end
    end

    if self.name == 'room_3' or self.name == 'room_4' then
        if self.player.p.x >= 40 and self.player.p.x <= 48+128 and self.player.p.y >= 700 and self.player.p.y <= 1000 then
            self.under_play = true
        else self.under_play = false end
    end

    if self.name == 'room_2' then
        if self.mom_talk_count then
            self.mom_talk_t = self.mom_talk_t + dt
            if self.mom_talk_t >= self.mom_talk_delay then
                self.mom_talk_count = false
                self.mom_can_speak_to = true 
                self.mom_talk_t = 0
            end
        end
    end
end

function Room:draw()
    local t = 6*(1-math.cos(love.timer.getTime()))
    local t2 = 2*(math.sin(10*love.timer.getTime()))

    if self.name == 'room_1' or self.name == 'room_2' or self.name == 'room_3' then
        love.graphics.draw(gl.play, 48 - self.camera.p.x, self.height - 32*6 + 16 + t - self.camera.p.y)
    end
    self.camera:draw()

    if self.under_play then
        if self.name == 'room_1' then
            love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)

        elseif self.name == 'room_2' then
            if self.talked_to_mom then
                love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)
            else love.graphics.draw(gl.mommy, gl.width/2 - 180, gl.height - 48 + t2) end
        
        elseif self.name == 'room_3' then
            if self.talked_to_friends then
                love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)
            else love.graphics.draw(gl.friends, gl.width/2 - 335/2, gl.height - 48 + t2) end
        end
    end

    if self.name == 'room_2' then
        if self.mom.speaking_mom and not self.talked_to_mom then
            love.graphics.draw(gl.talktomom, gl.width/2 - 80, gl.height - 48 + t2)
        end
    end

    if self.name == 'room_3' then
        if self.entities[3].speaking_mom and not self.talked_to_friends then
            love.graphics.draw(gl.talktofriends, gl.width/2 - 98, gl.height - 48 + t2)
        end
    end

    if self.name == 'room_4' then
        if self.entities[6].speaking_mom and not self.talked_to_girlfriend then
            love.graphics.draw(gl.talktogirlfriend, gl.width/2 - 116, gl.height-48+t2)
        end
    end

    if self.name == 'room_5' then
        if not self.everyone_dead then
            love.graphics.draw(gl.killeveryone, gl.width/2 - 90, gl.height-48+t2)
        else
            love.graphics.draw(gl.killyourself, gl.width/2 - 100, gl.height-48+t2)
        end
    end
end

function Room:keypressed(key)
    if self.name == 'room_1' then
        if key == 'return' or key == ' ' then
            if self.under_play then
                beholder.trigger('transition', self.to_level)
            end
        end

    elseif self.name == 'room_2' then
        if self.talked_to_mom then
            if key == 'return' or key == ' ' then
                if self.under_play then
                    beholder.trigger('transition', self.to_level)
                end
            end
        end

        if self.mom_can_speak_to then
            if not self.talked_to_mom then
                if self.mom.speaking_mom then
                    if key == 'return' or key == ' ' then
                        self.times_mom = self.times_mom + 1
                        self.mom_talk_count = true
                        self.mom_can_speak_to = false
                        beholder.trigger('player speak mom' .. self.player.id, self.times_mom)
                        if self.times_mom >= 3 then self.talked_to_mom = true end
                    end
                end
            end
        end

    elseif self.name == 'room_3' then
        if self.talked_to_friends then
            if key == 'return' or key == ' ' then
                if self.under_play then
                    beholder.trigger('transition', self.to_level)
                end
            end
        end

        if not self.talked_to_friends then
            if self.entities[3].speaking_mom then
                if key == 'return' or key == ' ' then
                    self.talked_to_friends = true
                    beholder.trigger('player speak friends' .. self.player.id)
                end
            end
        end

    elseif self.name == 'room_4' then
        if not self.talked_to_girlfriend then
            if self.entities[6].speaking_mom then
                if key == 'return' or key == ' ' then
                    self.talked_to_girlfriend = true
                    beholder.trigger('player speak girlfriend' .. self.player.id)
                end
            end
        end
    
    elseif self.name == 'room_5' then
        if self.everyone_dead then
            if key == 'return' or key == ' ' then
                love.event.push('quit')
            end
        end
    end

    for k, v in pairs(self.press_player_keys) do
        if key == k then
            beholder:trigger(v .. self.player.id)
        end
    end
end

function Room:mousepressed(x, y, button)
    if self.name == 'room_5' then
        self.player:mousepressed(x, y, button)
    end
end
