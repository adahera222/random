require 'Level'

Room = class('Room', Level)

function Room:initialize(name, map)
    Level.initialize(self, name, map)
    self.player = Player(200, 100, 'pistol')
    self.camera = Camera({x1 = -self.width, y1 = -self.height, x2 = self.width, y2 = self.height})
    self.camera:add(1, self.player.draw, self.player)

    for _, tile in ipairs(self.tiles) do self.camera:add(1, tile.draw, tile) end
    for _, entity in ipairs(self.entities) do self.camera:add(1, entity.draw, entity) end

    self.down_player_keys = {
        a = 'move left',
        d = 'move right',
        left = 'move left',
        right = 'move right',
    }

    self.under_play = false
end

function Room:update(dt)
    for k, v in pairs(self.down_player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, tile in ipairs(self.tiles) do
        self.player:collideWith(tile)
        local entities = self:getInArea('entities', tile.p, 64)
        for _, entity in ipairs(entities) do
            entity:collideWith(tile)
        end
    end

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
        love.graphics.draw(gl.spaceenter, gl.width/2 - 190, gl.height - 48 + t2)
    end
end

function Room:keypressed(key)
    if key == 'return' or key == ' ' then
        if self.under_play then
            beholder.trigger('transition', 'level_1')
        end
    end
end

function Room:mousepressed(x, y, button)

end
