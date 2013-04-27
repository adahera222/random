require 'map'
require 'Player'
require 'Projectile'
require 'Enemy'
require 'Area'
require 'Text'

Level = class('Level')

function Level:initialize()
    love.physics.setMeter(physics_meter)
    self.world = love.physics.newWorld(0, 40*physics_meter)
    self.world:setCallbacks(collisionOnEnter, collisionOnExit)
    self.player = Player(self.world)
    self.solids = {}
    self.projectiles = {}
    self.enemies = {}
    self.areas = {}
    self.texts = {}
    self.to_be_created = {}
    self:loadMap()

    beholder.observe('CREATE PROJECTILE', function(x, y, angle, modifiers)
        if modifiers.area then
            if not areas[modifiers.area].on_hit then
                table.insert(self.to_be_created, {'projectile_area', self.world, x, y, angle, modifiers})
                return
            end
        end
        table.insert(self.to_be_created, {'projectile', self.world, x, y, angle, modifiers})
    end)

    beholder.observe('CREATE ENEMY', function(x, y, w, h)
        table.insert(self.to_be_created, {'enemy', self.world, x, y, w, h})
    end)

    beholder.observe('CREATE AREA', function(x, y, parent, area_logic)
        table.insert(self.to_be_created, {'area', self.world, x, y, parent, area_logic})
    end)

    beholder.observe('ENEMIES LIST REQUEST', function(id)
        beholder.trigger('ENEMIES LIST REPLY' .. id, self.enemies)
    end)

    beholder.observe('DAMAGE POP', function(text, x, y)
        table.insert(self.texts, Text(text, x, y, math.random(50, 150), math.random(-3*math.pi/4, -math.pi/4)))
    end)

    beholder.observe('TEXT POP', function(text, x, y, parent)
        table.insert(self.texts, Text(text, x, y, 25, math.pi/2, parent))
    end)

    chrono:every(5, function() beholder.trigger('CREATE ENEMY', 212+300, -16, 16, 16) end)
end

function Level:createPostWorldStep()
    local to_be_removed = {}

    for i, t in ipairs(self.to_be_created) do
        if t[1] == 'projectile' then
            table.insert(self.projectiles, Projectile(t[2], t[3], t[4], t[5], t[6]))
        elseif t[1] == 'enemy' then
            table.insert(self.enemies, Enemy(t[2], t[3], t[4], t[5], t[6]))
        elseif t[1] == 'area' then
            table.insert(self.areas, Area(t[2], t[3], t[4], t[5], t[6]))
        elseif t[1] == 'projectile_area' then
            local p = Projectile(t[2], t[3], t[4], t[5], t[6])
            table.insert(self.projectiles, p)
            table.insert(self.areas, Area(t[2], t[3], t[4], p, areas[t[6].area]))
        end
        table.insert(to_be_removed, i)
    end

    for i = #to_be_removed, 1, -1 do table.remove(self.to_be_created, to_be_removed[i]) end
end


function Level:loadMap()
    for _, solid in ipairs(map) do
        table.insert(self.solids, EntityRect(self.world, 'static', solid.x, solid.y, solid.w, solid.h))
    end
end

function collisionOnEnter(fa, fb, c)
    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()

    if fa:isSensor() and fb:isSensor() then
        if collIf('Enemy', 'Projectile', a, b) then
            a, b = collEnsure('Enemy', a, 'Projectile', b)
            a:collisionProjectile(b)
            b:collisionEnemy()
        end

        if collIf('Player', 'Enemy', a, b) then
            a, b = collEnsure('Player', a, 'Enemy', b)
            a:collisionEnemy()
        end

    elseif not (fa:isSensor() or fb:isSensor()) then
        if collIf('Player', 'EntityRect', a, b) then
            a, b = collEnsure('Player', a, 'EntityRect', b)
            a:collisionSolid('enter', nx, ny)
        end

        if collIf('Projectile', 'EntityRect', a, b) then
            a, b = collEnsure('Projectile', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end

        if collIf('Enemy', 'EntityRect', a, b) then
            a, b = collEnsure('Enemy', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end

        if collIf('Area', 'EntityRect', a, b) then
            a, b = collEnsure('Area', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end
    end
end

function collisionOnExit(fa, fb, c)
    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()
    
    if fa:isSensor() and fb:isSensor() then
        if collIf('Area', 'Enemy', a, b) then
            a, b = collEnsure('Area', a, 'Enemy', b)
            a:collisionEnemy(b)
        end
    
    elseif not (fa:isSensor() or fb:isSensor()) then
        if collIf('Player', 'EntityRect', a, b) then
            a, b = collEnsure('Player', a, 'EntityRect', b)
            a:collisionSolid('exit', nx, ny)
        end
    end
end

function collEnsure(class_name1, a, class_name2, b)
    if a.class.name == class_name2 and b.class.name == class_name1 then return b, a
    else return a, b end
end

function collIf(class_name1, class_name2, a, b)
    if (a.class.name == class_name1 and b.class.name == class_name2) or
       (a.class.name == class_name2 and b.class.name == class_name1) then
       return true
    else return false end
end

function Level:cleanUp()
    for i = #self.projectiles, 1, -1 do
        if self.projectiles[i].dead then
            self.projectiles[i].body:destroy()
            table.remove(self.projectiles, i)
        end
    end

    for i = #self.enemies, 1, -1 do
        if self.enemies[i].dead then
            self.enemies[i].body:destroy()
            table.remove(self.enemies, i)
        end
    end

    for i = #self.areas, 1, -1 do
        if self.areas[i].dead then
            self.areas[i].body:destroy()
            table.remove(self.areas, i)
        end
    end
end

function Level:update(dt)
    self.world:update(dt)

    self.player:update(dt)    
    for _, solid in ipairs(self.solids) do solid:update(dt) end
    for _, proj in ipairs(self.projectiles) do proj:update(dt) end
    for _, enemy in ipairs(self.enemies) do enemy:update(dt) end
    for _, area in ipairs(self.areas) do area:update(dt) end
    for _, text in ipairs(self.texts) do text:update(dt) end

    self:cleanUp()
    self:createPostWorldStep()
end

function Level:draw()
    self.player:draw()
    for _, solid in ipairs(self.solids) do solid:draw() end
    for _, proj in ipairs(self.projectiles) do proj:draw() end
    for _, enemy in ipairs(self.enemies) do enemy:draw() end
    for _, area in ipairs(self.areas) do area:draw() end
    for _, text in ipairs(self.texts) do text:draw() end
    love.graphics.setColor(255, 0, 0)
    love.graphics.line(212+300-16, 212+448-8, 212+300+16, 212+448-8)
    love.graphics.setColor(255, 255, 255)
end

function Level:keypressed(key)
    self.player:keypressed(key)
end
