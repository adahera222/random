require 'game/world/Collision'
require 'game/world/Render'
require 'game/world/Factory'
require 'game/world/Group'
require 'game/world/Map'
require 'game/world/CameraShake'
require 'game/world/HitFrameStop'
require 'game/world/Query'
require 'game/world/Background'
require 'game/world/Particle'

World = class('World')
World:include(Collision)
World:include(Render)
World:include(Factory)
World:include(Map)
World:include(Query)
World:include(CameraShake)
World:include(HitFrameStop)
World:include(Background)
World:include(Particle)

function World:init(floor)
    self.floor = floor
    self.id = getUID()
    self:collisionInit()
    self:renderInit()
    self:factoryInit()
    self:queryInit()
    self:cameraShakeInit()
    self:hitFrameStopInit()
    self:backgroundInit()
    self:particleInit()
    self.world = self.floor.world
    self.world:setCallbacks(self.collisionOnEnter, self.collisionOnExit)
    self.groups = {}
    self.entities = {}
    self.player = nil
    self:mapInit('test_map')

    self:addGroup('Player')
    self:addGroup('Solid')
    self:addGroup('BreakableSolid')
    self:addGroup('EnemyWall')
    self:addGroup('BreakableParticle')
    self:addGroup('BreakableParticleMW')
    self:addGroup('Effect')
    self:addGroup('FaderParticle')
    self:addGroup('Item')
    self:addGroup('JumpingPad')
    self:addGroup('Ladder')
    self:addGroup('MeleeArea')
    self:addGroup('PhysicsParticle')
    self:addGroup('Blaster')
    self:addGroup('Roller')
    self:addGroup('Pumper')
    self:addGroup('SpikedBall')
    self:addGroup('ChainedSpikedBall')
    self:addGroup('Spikes')
    self:addGroup('TNT')
    self:addGroup('Boulder')
    self:addGroup('PumperProjectile')
    self:addGroup('Hammer')
    self:addGroup('AntigravityRock')
    self:addGroup('Trail')
    self:addGroup('AntigravityRockTrail')
    self:addGroup('SeekerParticle')
    self:addGroup('PumperProjectileTrail')
    self:addGroup('MovingWall')
    self:addGroup('Button')
    self:addGroup('Trigger')
    self:addGroup('MovingEffect')
    self:addGroup('Prop')
    self:addGroup('Rail')
    self:addGroup('MineCart')

    self.before_all_groups = {'MovingWall', 'AntigravityRockTrail', 'AntigravityRock'}

    self:addCollisionEnter('Player', 'Blaster', 'collisionBlaster')
    self:addCollisionEnter('Player', 'Roller', 'collisionRoller')
    self:addCollisionEnter('Player', 'SpikedBall', 'collisionSpikedBall')
    self:addCollisionEnter('Player', 'Spikes', 'collisionSpikes')
    self:addCollisionEnter('Player', 'Ladder', 'collisionLadderEnter')
    self:addCollisionExit('Player', 'Ladder', 'collisionLadderExit')
    self:addCollisionEnter('SpikedBall', 'BreakableSolid', 'collisionBreakableSolid')
    self:addCollisionEnter('Player', 'Solid', 'collisionSolidEnter', true)
    self:addCollisionEnter('Player', 'BreakableSolid', 'collisionSolidEnter', true)
    self:addCollisionEnter('Player', 'TNT', 'collisionSolidEnter', true)
    self:addCollisionExit('Player', 'Solid', 'collisionSolidExit', true)
    self:addCollisionExit('Player', 'BreakableSolid', 'collisionSolidExit', true)
    self:addCollisionExit('Player', 'TNT', 'collisionSolidExit', true)
    self:addCollisionEnter('Player', 'JumpingPad', 'collisionJumpingPad', true)
    self:addCollisionEnter('Blaster', 'Solid', 'collisionSolid', true)
    self:addCollisionEnter('Blaster', 'EnemyWall', 'collisionSolid', true)
    self:addCollisionEnter('Blaster', 'BreakableSolid', 'collisionBreakableSolid', true)
    self:addCollisionEnter('Roller', 'Solid', 'collisionSolid', true)
    self:addCollisionEnter('Roller', 'EnemyWall', 'collisionSolid', true)
    self:addCollisionEnter('Roller', 'BreakableSolid', 'collisionBreakableSolid', true)
    self:addCollisionEnter('BreakableParticle', 'Solid', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticle', 'MovingWall', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticle', 'BreakableSolid', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticle', 'JumpingPad', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticle', 'Button', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticleMW', 'Solid', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticleMW', 'BreakableSolid', 'collisionBreak', true)
    self:addCollisionEnter('BreakableParticleMW', 'JumpingPad', 'collisionBreak', true)
    self:addCollisionEnter('Boulder', 'JumpingPad', 'collisionJumpingPad', true)
    self:addCollisionEnter('Boulder', 'Solid', 'collisionSolid', true)
    self:addCollisionEnter('Boulder', 'MovingWall', 'collisionMovingWall', true)
    self:addCollisionEnter('Boulder', 'BreakableSolid', 'collisionBreakableSolid', true)
    self:addCollisionEnter('Player', 'Boulder', 'collisionBoulder', true)
    self:addCollisionEnter('Boulder', 'TNT', 'collisionTNT', true)
    self:addCollisionEnter('Blaster', 'Boulder', 'collisionBoulder')
    self:addCollisionEnter('Roller', 'Boulder', 'collisionBoulder')
    self:addCollisionEnter('Pumper', 'Boulder', 'collisionBoulder')
    self:addCollisionEnter('PumperProjectile', 'Player', 'collisionPlayer')
    self:addCollisionEnter('PumperProjectile', 'SpikedBall', 'collisionSpikedBall')
    self:addCollisionEnter('PumperProjectile', 'BreakableSolid', 'collisionBreakableSolid')
    self:addCollisionEnter('PumperProjectile', 'TNT', 'collisionTNT')
    self:addCollisionEnter('PumperProjectile', 'Boulder', 'collisionBoulder')
    self:addCollisionEnter('PumperProjectile', 'Blaster', 'collisionBlasterRoller')
    self:addCollisionEnter('PumperProjectile', 'Roller', 'collisionBlasterRoller')
    self:addCollisionEnter('PumperProjectile', 'JumpingPad', 'collisionSolid', true)
    self:addCollisionEnter('PumperProjectile', 'Solid', 'collisionSolid', true)
    self:addCollisionEnter('Hammer', 'Player', 'collisionPlayer')
    self:addCollisionEnter('Hammer', 'BreakableSolid', 'collisionBreakableSolid')
    self:addCollisionEnter('Hammer', 'TNT', 'collisionTNT')
    self:addCollisionEnter('Hammer', 'BreakableSolid', 'collisionBreakableSolid', true)
    self:addCollisionEnter('Hammer', 'TNT', 'collisionTNT', true)
    self:addCollisionEnter('Hammer', 'Blaster', 'collisionBlasterRoller')
    self:addCollisionEnter('Hammer', 'Roller', 'collisionBlasterRoller')
    self:addCollisionEnter('Hammer', 'Pumper', 'collisionPumper')
    self:addCollisionEnter('Hammer', 'PumperProjectile', 'collisionPumperProjectile')
    self:addCollisionEnter('Hammer', 'Solid', 'collisionSolid', true)
    self:addCollisionEnter('Hammer', 'JumpingPad', 'collisionJumpingPad')
    self:addCollisionEnter('AntigravityRock', 'Solid', 'collisionSolid')
    self:addCollisionEnter('AntigravityRock', 'JumpingPad', 'collisionSolid')
    self:addCollisionEnter('AntigravityRock', 'Blaster', 'collisionEnemy')
    self:addCollisionEnter('AntigravityRock', 'Roller', 'collisionEnemy')
    self:addCollisionEnter('AntigravityRock', 'Pumper', 'collisionEnemy')
    self:addCollisionEnter('AntigravityRock', 'BreakableSolid', 'collisionBreakableSolid')
    self:addCollisionEnter('AntigravityRock', 'TNT', 'collisionTNT')
    self:addCollisionEnter('Button', 'Player', 'collisionPlayerEnter', true)
    self:addCollisionExit('Button', 'Player', 'collisionPlayerExit', true)
    self:addCollisionEnter('MovingWall', 'Player', 'collisionPlayerEnter', true)
    self:addCollisionExit('MovingWall', 'Player', 'collisionPlayerExit', true)
    self:addCollisionEnter('Button', 'Hammer', 'collisionHammer', true)
    self:addCollisionEnter('Button', 'Boulder', 'collisionBoulder', true)
    self:addCollisionEnter('Trigger', 'Player', 'collisionPlayer')
    self:addCollisionEnter('MineCart', 'Player', 'collisionPlayerEnter', true)
    self:addCollisionExit('MineCart', 'Player', 'collisionPlayerExit', true)

    self:createToGroup('Player', 100, 100)
    self:createPostWorldStep()
    for _, group in ipairs(self.groups) do
        if group.name == 'Player' then
            self.player = group:getEntities()[1]
        end
    end
end

function World:update(dt)
    self:hitFrameStopUpdate(dt)
    if self.frame_stopped then return end
    for _, group in ipairs(self.groups) do group:update(dt) end
    for _, entity in ipairs(self.entities) do entity:update(dt) end

    self:backgroundUpdate(dt, Vector(self.player.x, self.player.y))
    self:cameraShakeUpdate(dt)
    self:particleUpdate(dt)
    self:renderUpdate(dt, Vector(self.player.x, self.player.y))
    self.world:update(dt)
    self:createPostWorldStep()
    self:removePostWorldStep()
    self:remove()
    for _, group in ipairs(self.groups) do group:removePostWorldStep() end
end

function World:beforeAllGroupDraw()
    for _, group_ro in ipairs(self.before_all_groups) do
        for _, group in ipairs(self.groups) do
            if group.name == group_ro then
                group:draw()
            end
        end
    end
end

function World:draw()
    self:renderAttach()
    self:backgroundDraw()
    self:beforeAllGroupDraw()
    self:mapDraw()
    self:renderDraw()
    self:particleDraw()
    self:renderDetach()
end

function World:add(entity)
    table.insert(self.entities, entity)
end

function World:remove(id)
    table.remove(self.entities, findIndexByID(self.entities, id))
end

function World:addGroup(group_name)
    table.insert(self.groups, Group(group_name))
end

function World:addToGroup(group_name, entity)
    for _, group in ipairs(self.groups) do
        if group.name == group_name then
            group:add(entity)
            return
        end
    end
end

function World:removeGroup(group_name)
    for i, group in ipairs(self.groups) do
        if group.name == group_name then
            group:destroy()
            table.remove(self.groups, i)
            return
        end
    end
end

function World:removeFromGroup(group_name, id)
    for _, group in ipairs(self.groups) do
        if group.name == group_name then
            group:remove(id)
            return
        end
    end
end

function World:removePostWorldStep()
    for i = #self.entities, 1, -1 do
        if self.entities[i].dead then
            if self.entities[i].class:includes(Timer) then self.entities[i]:timerDestroy() end
            if self.entities[i].class:includes(PhysicsRectangle) then
                self.entities[i].fixture:setUserData(nil)
                self.entities[i].sensor:setUserData(nil)
                self.entities[i].body:destroy()
                self.entities[i].fixture = nil
                self.entities[i].sensor = nil
                self.entities[i].body = nil
            end
            self.entities[i].world = nil
            self:remove(self.entities[i].id)
        end
    end
end

function World:destroy()
    for _, group in ipairs(self.groups) do
        group:apply(function(entity)
            entity.dead = true
        end)
    end
    for i, group in ipairs(self.groups) do 
        group:removePostWorldStep() 
        group:destroy()
    end
    for i, entity in ipairs(self.entities) do
        entity.dead = true
    end
    self:removePostWorldStep()
    self.entities = nil
    self.groups = nil
    self.player = nil
    self.camera = nil
    self.groups = nil
    self.world = nil
end

function World:keypressed(key)
    self.player:keypressed(key)
end

function World:keyreleased(key)
    self.player:keyreleased(key)
end
