require 'Player'
require 'Tile'
require 'Camera'
require 'Enemy'
require 'Projectile'

Level = class('Level')

function Level:initialize(name, map)
    self.name = name
    self.tiles = {}
    self.tiles_aux = {}
    self.entities = {}
    self.pixel_color_image_map = {
        {r = 0, g = 0, b = 255, tile = 'd_blue_block'},
        {r = 255, g = 0, b = 0, tile = 'd_brown_block'}
    }
    self.width, self.height = self:loadTiles(map)
end

function Level:getInArea(type, point, size)
    local abs = math.abs
    local objs = {}    
    for _, obj in ipairs(self[type]) do
        local dx = abs(point.x - obj.p.x)
        local dy = abs(point.y - obj.p.y)
        if dx <= size and dy <= size then
            table.insert(objs, obj)
        end
    end
    return objs
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
            for _, m in ipairs(self.pixel_color_image_map) do
                if r == m.r and g == m.g and b == m.b then
                    local x = i*32+16
                    local y = j*32+16
                    if x < 3000 then table.insert(self.tiles, Tile(m.tile, x, y))
                    else table.insert(self.tiles_aux, Tile(m.tile, x, y)) end
                end
            end
        end
    end
    return data:getWidth()*32, data:getHeight()*32
end
