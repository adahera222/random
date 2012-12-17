require 'Level'
require 'Projectile'
require 'RotatingTile'

Level_2 = class('Level_2', Level)

function Level_2:initialize(name, map)
    Level.initialize(self, name, map)
    self.player = Player(392, self.height - 512, 'gun_2')
    self.camera = Camera({x1 = -self.width, y1 = -self.height, x2 = self.width, y2 = self.height})
    self.camera:add(1, self.player.draw, self.player)

    self.rotating_tiles = {}
    self:addBackground(2000)

    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    self:spawnArea(48, 2192, 144, 1, 3, 1)
    self:spawnArea(720, 1936, 624, 1, 2, -1)
    self:spawnArea(720, 2224, 624, 1, 3, -1)
    self:spawnArea(48, 1520, 208, 1, 3, 1)
    self:spawnArea(720, 1424, 624, 1, 1, -1)
    self:spawnArea(48, 1008, 144, 1, 2, 1)
    self:spawnArea(48, 720, 144, 1, 2, 1)
    self:spawnArea(48, 208, 304, 1, 4, 1)
    self:spawnArea(720, 112, 464, 1, 4, -1)
    self:spawnArea(720, 208, 464, 1, 4, -1)

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

function Level_2:update(dt)
    if #self.entities == 0 then self.everyone_dead = true; self.change = true end
    if self.everyone_dead then 
        self.dead_t = self.dead_t + dt
        if self.dead_t >= self.dead_delay then
            if self.change then
                beholder.trigger('transition', 'room_3')
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

function Level_2:draw()
    local t = 2*(math.sin(10*love.timer.getTime()))
    love.graphics.setBackgroundColor(0, 0, 0)
    self.camera:draw()

    if not self.everyone_dead then
        love.graphics.draw(gl.behind, gl.width/2 - 129, gl.height- 48 + t)
    else
        love.graphics.draw(gl.goodjob, gl.width/2 - 64, gl.height-48+t)
    end
end

function Level_2:spawnArea(x, y, dx, min, max, dir)
    local n = math.random(min, max)
    for i = 1, n do
        local xx = 0
        if dir == 1 then
            xx = math.random(12, dx-x+12)
        else xx = math.random(12, x-dx+12) end
        self:add(Enemy('child', x+dir*xx, y-4, 200, self)) 
    end
end

function Level_2:keypressed(key)
    for k, v in pairs(self.press_player_keys) do
        if key == k then
            beholder:trigger(v .. self.player.id)
        end
    end
end

function Level_2:mousepressed(x, y, button)
    self.player:mousepressed(x, y, button)
end

function Level_2:addBackground(n)
    for i = 1, n do
        local x, y = math.random(-self.width, 2*self.width), math.random(-self.height/2, self.height/2)
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
