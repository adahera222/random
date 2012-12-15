require 'Player'
require 'Tile'

Level = class('Level')

function Level:initialize(name, map)
    self.name = name
    self.player = Player(200, 100)
    self.tiles = {}
    self.entities = {}
    self:loadTiles(map)

    self.player_keys = {
        a = 'move left',
        d = 'move right',
        left = 'move left',
        right = 'move right'
    }
end

function Level:update(dt)
    for k, v in pairs(self.player_keys) do
        if love.keyboard.isDown(k) then
            beholder:trigger(v .. self.player.id)
        end
    end

    for _, tile in ipairs(self.tiles) do
        self.player:collideWith(tile)
    end

    for _, entity in ipairs(self.entities) do 
        entity:update(dt) 
        self.player:collideWith(entity)
    end
    self.player:update(dt)
end

function Level:draw()
    for _, tile in ipairs(self.tiles) do tile:draw() end
    for _, entity in ipairs(self.entities) do entity:draw() end
    self.player:draw()

    love.graphics.print(self.name, 10, 10)
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
end
