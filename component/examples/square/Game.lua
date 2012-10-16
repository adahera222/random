require 'examples/square/create'
require 'examples/square/systems/init'
beholder = require 'lib/beholder'

Game = class('Game')

function Game:initialize()
    self.game_objects = {}
    self.collision_system = SCollision:new(64)
    self.render_system = SRender:new(10000)

    -- Creates player.
    local player = createGameObject('player')
    table.insert(self.game_objects, player)
    self.collision_system:add(player)
    self.render_system:add(player)

    -- Creates static blocks.
    for i = 1, 10 do
        local block = createGameObject('block')
        table.insert(self.game_objects, block)
        if block.attributes.collidable then self.collision_system:add(block) end
        self.render_system:add(block)
    end
end

function Game:update(dt)
    self.collision_system:update(dt)
    for _, go in ipairs(self.game_objects) do go:update(dt) end
    self.render_system:update(dt, self.game_objects)
end

function Game:draw()
    self.render_system:draw()
end
