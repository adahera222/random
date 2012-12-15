require 'Player'
require 'Tile'
require 'Camera'
require 'Enemy'

Level = class('Level')

function Level:initialize(name, map)
    self.name = name
    self.player = Player(200, 100)
    self.tiles = {}
    self.entities = {}
    self.width, self.height = self:loadTiles(map)
    self.camera = Camera({x1 = 0, y1 = 0, x2 = self.width/2, y2 = 0})

    self:add(Enemy('animal', 300, 100, 100))
    self:add(Enemy('animal', 400, 100, 100))
    self:add(Enemy('animal', 500, 100, 100))
    self:add(Enemy('animal', 700, 100, 100))
    self:add(Enemy('animal', 800, 100, 100))

    for _, tile in ipairs(self.tiles) do self.camera:add(tile.draw, tile) end
    for _, entity in ipairs(self.entities) do self.camera:add(entity.draw, entity) end
    self.camera:add(self.player.draw, self.player)

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
end

function Level:update(dt)
    for k, v in pairs(self.down_player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, tile in ipairs(self.tiles) do
        self.player:collideWith(tile)
    end

    for _, entity in ipairs(self.entities) do 
        if instanceOf(Enemy, entity) then
            entity:update(dt, self.player) 
        else entity:update(dt) end
        entity:collideWith(self.player)
        for _, tile in ipairs(self.tiles) do
            entity:collideWith(tile)
        end
        self.player:collideWith(entity)
    end
    self.player:update(dt)
    self.camera:follow(dt, self.player)
    self.camera:update(dt)
end

function Level:draw()
    self.camera:draw()
    love.graphics.print(self.name, 10, 10)
end


function Level:keypressed(key)
    for k, v in pairs(self.press_player_keys) do
        if key == k then
            beholder:trigger(v .. self.player.id)
        end
    end
end

function Level:add(entity)
    table.insert(self.entities, entity)
end

function Level:remove(entity)
    for i, e in ipairs(self.entities) do
        if e.id == entity.id then
            table.remove(self.entities, i)   
            return
        end
    end
end

function Level:loadTiles(map)
    local data = love.image.newImageData(map)
    for i = 0, data:getWidth()-1 do
        for j = 0, data:getHeight()-1 do
            local r, g, b, a = data:getPixel(i, j)
            if r == 0 and g == 0 and b == 0 then
                table.insert(self.tiles,
                             Tile('normal_block', i*32+16, j*32+16))
            end
        end
    end
    return data:getWidth()*32, data:getHeight()*32
end
