require 'Player'
require 'Tile'
require 'Camera'
require 'Enemy'
require 'Projectile'

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

    beholder:observe('create projectile', 
        function(x, y)
            local delta = Vector(x - self.player.p.x + self.camera.p.x,
                                 y - self.player.p.y + self.camera.p.y)
            local r = math.atan2(delta.y, delta.x)
            print(radToDeg(r))
            local e = Projectile(self.player.p.x, self.player.p.y, r, 200)
            self:add(e)
            self.camera:add(e.draw, e)
        end)
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

function Level:update(dt)
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
            self:remove(entity)
            self.camera:remove(entity)
        end
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

function Level:mousepressed(x, y, button)
    self.player:mousepressed(x, y, button)
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
