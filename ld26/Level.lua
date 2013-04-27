require 'Player'
require 'map'

Level = class('Level')

function Level:initialize()
    love.physics.setMeter(32)
    self.world = love.physics.newWorld(0, 20*32)
    self.world:setCallbacks(collisionOnEnter, collisionOnExit)
    self.player = Player(self.world)
    self.solids = {}
    self:loadMap()
end

function Level:loadMap()
    for _, solid in ipairs(map) do
        table.insert(self.solids, EntityRect(self.world, 'static', solid.x, solid.y, solid.w, solid.h))
    end
end

function collisionOnEnter(fa, fb, c)
    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()

    if not (fa:isSensor() or fb:isSensor()) then
        if collIf('Player', 'EntityRect', a, b) then
            a, b = collEnsure('Player', a, 'EntityRect', b)
            a:collisionSolid('enter', nx, ny)
        end
    end
end

function collisionOnExit(fa, fb, c)
    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()
    
    if not (fa:isSensor() or fb:isSensor()) then
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


function Level:update(dt)
    self.world:update(dt)

    self.player:update(dt)    
    for _, solid in ipairs(self.solids) do solid:update(dt) end
end

function Level:draw()
    self.player:draw()
    for _, solid in ipairs(self.solids) do solid:draw() end
end

function Level:keypressed(key)
    self.player:keypressed(key)
end




