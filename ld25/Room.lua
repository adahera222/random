require 'Level'
require 'Enemy'

Room = class('Room', Level)

function Room:initialize(name, map, to_level, gun)
    Level.initialize(self, name, map)
    self.to_level = to_level

    if name == 'room_1' then self.player = Player(200, 100, gun)
    elseif name == 'room_2' then self.player = Player(600, 400, gun) end

    self.camera = Camera({x1 = -self.width, y1 = -self.height, x2 = self.width, y2 = self.height})

    for _, tile in ipairs(self.tiles) do self.camera:add(1, tile.draw, tile) end
    for _, entity in ipairs(self.entities) do self.camera:add(1, entity.draw, entity) end

    self.mom = Enemy('person', 1600, 50, 100, self)
    self.camera:add(1, self.mom.draw, self.mom)
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
end

function Room:update(dt)
    for k, v in pairs(self.down_player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, tile in ipairs(self.tiles) do
        self.player:collideWith(tile)
        self.mom:collideWith(tile)
        local entities = self:getInArea('entities', tile.p, 64)
        for _, entity in ipairs(entities) do
            entity:collideWith(tile)
        end
    end

    self.mom:update(dt, self.player)
    self.player:update(dt, self.camera)
    self.camera:follow(dt, self.player)
    self.camera:update(dt)

    if self.player.p.x >= 40 and self.player.p.x <= 48+128 then
        self.under_play = true
    else self.under_play = false end
end

function Room:draw()
    local t = 6*(1-math.cos(love.timer.getTime()))
    local t2 = 2*(math.sin(10*love.timer.getTime()))
    love.graphics.draw(gl.play, 48 - self.camera.p.x, self.height - 32*6 + 16 + t - self.camera.p.y)
    self.camera:draw()
    love.graphics.print(self.name, 10, 10)
    if self.under_play then
        if self.name == 'room_1' then
            love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)

        elseif self.name == 'room_2' then
            if self.talked_to_mom then
                love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)
            else love.graphics.draw(gl.mommy, gl.width/2 - 180, gl.height - 48 + t2) end
        end
    end

    if self.mom.speaking_mom and not self.talked_to_mom then
        love.graphics.draw(gl.talktomom, gl.width/2 - 80, gl.height - 48 + t2)
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

        if not self.talked_to_mom then
            if self.mom.speaking_mom then
                if key == 'return' or key == ' ' then
                    self.times_mom = self.times_mom + 1
                    beholder.trigger('player speak' .. self.player.id, self.times_mom)
                    if self.times_mom >= 3 then self.talked_to_mom = true end
                end
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

end
