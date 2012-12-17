require 'Level'
require 'Projectile'
require 'RotatingTile'

Level_3 = class('Level_3', Level)

function Level_3:initialize(name, map)
    Level.initialize(self, name, map)
    self.player = Player(200, 100, 'gun_3')
    self.camera = Camera({x1 = -self.width, y1 = -1.2*self.height, x2 = 1.2*self.width, y2 = self.height})
    self.camera:add(1, self.player.draw, self.player)

    self.rotating_tiles = {}
    self:addBackground(1000)

    self:add(Enemy('boss', 600, 100, 200, self))

    for _, tile in ipairs(self.tiles) do self.camera:add(1, tile.draw, tile) end
    for _, entity in ipairs(self.entities) do self.camera:add(1, entity.draw, entity) end

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

    self.first_lmb = false
    self.everyone_dead = false
    self.dead_delay = 1
    self.dead_t = 0
    self.change = false

    beholder:observe('create projectile', 
        function(r)
            local e = Projectile(self.player.p.x, self.player.p.y, r, 750)
            self:add(e)
            self.camera:add(1, e.draw, e)
        end)
end

function Level_3:update(dt)
    if #self.entities == 0 then self.everyone_dead = true; self.change = true end
    if self.player.dead then self.change = true end

    if not self.player.dead then
        if self.everyone_dead then 
            self.dead_t = self.dead_t + dt
            if self.dead_t >= self.dead_delay then
                if self.change then
                    beholder.trigger('transition', 'room_4')
                    self.change = false
                    self.dead_t = 0
                end
            end
        end
    end

    if self.player.dead then
        self.dead_t = self.dead_t + dt
        if self.dead_t >= self.dead_delay then
            if self.change then
                beholder.trigger('transition_self', 'level_3')
                self.change = false
                self.dead_t = 0
            end
        end
    end

    for k, v in pairs(self.down_player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, rt in ipairs(self.rotating_tiles) do
        rt:update(dt)
    end

    for _, tile in ipairs(self.tiles) do
        self.player:collideWith(tile)
        local entities = self:getInArea('entities', tile.p, 64)
        for _, entity in ipairs(entities) do
            entity:collideWith(tile)
        end
    end

    for _, entity in ipairs(self.entities) do 
        if instanceOf(Enemy, entity) then
            entity:update(dt, self.player) 
            entity:collideWith(self.player)
            self.player:collideWith(entity)
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

    self.player:update(dt, self.camera)
    self.camera:follow(dt, self.player)
    self.camera:update(dt)
end

function Level_3:draw()
    local t = 2*(math.sin(10*love.timer.getTime()))
    love.graphics.setBackgroundColor(0, 0, 0)
    self.camera:draw()

    if not self.player.dead then
        if not self.everyone_dead then
            love.graphics.draw(gl.dontlet, gl.width/2 - 180, gl.height- 48 + t)
        else
            love.graphics.draw(gl.happyface, gl.width/2 - 16, gl.height-48+t)
        end
    else
        love.graphics.draw(gl.sadface, gl.width/2 - 16, gl.height-48+t)
    end
end

function Level_3:keypressed(key)
    for k, v in pairs(self.press_player_keys) do
        if key == k then
            beholder:trigger(v .. self.player.id)
        end
    end
end

function Level_3:mousepressed(x, y, button)
    self.player:mousepressed(x, y, button)
end

function Level_3:addBackground(n)
    for i = 1, n do
        local x, y = math.random(-self.width, self.width), math.random(0, 1.25*self.height)
        local sx = math.random(10, 50)/10
        local r, b, g = math.random(64, 202), math.random(64, 202), math.random(64, 202)
        local rd = math.random(0, 2*math.pi)
        local m = math.random(1, 2); if m == 2 then m = -1 end
        local dr = math.random(0, 6*math.pi)/50*m
        local ps = math.random(1, 7)/10
        local rotating_tile = RotatingTile('bg_block', x, y, rd, sx, sx, dr, 
                                           {r = r, g = g, b = b})
        table.insert(self.rotating_tiles, rotating_tile)
        self.camera:add(ps, rotating_tile.draw, rotating_tile)
   end
end
