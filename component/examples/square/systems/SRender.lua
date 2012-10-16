require 'lib/middleclass'

-- Rendering system: handles how objects should be drawn to the screen.
-- Most objects should have a CRender or other related component to be drawn.
SRender = class('SRender')

-- Accesses -> CMovement



-- In this example the sprite batch is used to draw entities that use the
-- square.png sprite. Later on as things get more complex, either multiple
-- sprite batches will have to be used or entities will need to have their
-- CRender component and call a drawing function from there (slower).
--
-- sb_size: sprite batch size: number
function SRender:initialize(sb_size)

    -- Used to drawn many objects that use the same sprite effectively.
    self.img = love.graphics.newImage('examples/square/resources/square.png')
    self.sprite_batch = love.graphics.newSpriteBatch(self.img, sb_size)
    self.ids = {}
end

-- Adds a game objects' position to a sprite batch.
-- go: game object to be added: GameObject
function SRender:add(go)
    local mov = go:getGOC('CMovement')
    self.ids[#self.ids+1] = self.sprite_batch:add(mov.p.x, mov.p.y)
end

-- Updates all game objects' positions in the sprite batch.
-- game_objects: game objects to be updated: table -> GameObject
function SRender:update(dt, game_objects)
    for i, go in ipairs(game_objects) do
        local mov = go:getGOC('CMovement')
        self.sprite_batch:set(self.ids[i], mov.p.x, mov.p.y)
    end
end

-- Draws the sprite batch.
function SRender:draw()
    love.graphics.draw(self.sprite_batch, 0, 0)
end
