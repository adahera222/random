require 'lib/middleclass'
local bump = require 'lib/bump'

-- Collision system: handles collision between game objects that have a
-- collidable attribute.
SCollision = class('SCollision')

-- Messages sent -> CMovememnt
-- 'DISPLACE':
--  id:             GameObject's uid/type:                      string
--  dx:             displacement vector, component x:           number
--  dy:             displacement vector, component y:           number

-- Accesses -> CMovement



-- grid_size: you know, the GRID SIZE: number
function SCollision:initialize(grid_size)
    bump.initialize(grid_size)
end

function SCollision:update(dt) bump.collide() end

-- Adds a game object to the game object collision list (using bump).
-- go: game object to be added: GameObject
function SCollision:add(go) bump.add(go) end



-- Bump callbacks:
function bump.collision(item1, item2, dx, dy)    
    beholder.trigger('DISPLACE_' .. item1.id_type, dx, dy)
    beholder.trigger('DISPLACE_' .. item2.id_type, -dx, -dy)
end

function bump.getBBox(item)
    local mov = item:getGOC('CMovement')
    return mov.p.x - mov.w/2, mov.p.y - mov.h/2, mov.w, mov.h
end

function bump.shouldCollide(item1, item2)
    if item1.attributes.collidable and item2.attributes.collidable then
        return true
    else return false end
end
