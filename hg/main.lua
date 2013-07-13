function love.load()
    -- Libraries
    require 'lib/middleclass/middleclass'
    require 'lib/chrono/chrono'
    struct = require 'lib/chrono/struct'
    beholder = require 'lib/beholder/beholder'
    Vector = require 'lib/hump/vector'
    Camera = require 'lib/hump/camera'
    tween = require 'lib/tween/tween'
    anim8 = require 'lib/anal/AnAL'
    require 'utils'

    -- Main
    require 'Game'

    -- Systems
    require 'systems/Renderer'
    require 'systems/Block'
    require 'systems/Time'
    require 'systems/Map'

    -- Definitions
    require 'definitions/collisions'
    require 'definitions/input'
    require 'definitions/visuals'

    -- Mixins
    require 'mixins/PhysicsCircle'
    require 'mixins/PhysicsRectangle'
    require 'mixins/Input'
    require 'mixins/Collector'
    require 'mixins/Movable'
    require 'mixins/ActorVisual'
    require 'mixins/PropVisual'

    -- Game objects
    require 'game_objects/Entity'
    require 'game_objects/Player'
    require 'game_objects/Prop'

    initialize()
end

function initialize()
    uid = 0
    loadCollisions()
    loadInput()
    loadVisuals()
    chrono = Chrono()
    game = Game()
    love.mouse.setVisible(false)
end

function getUID()
    uid = uid + 1
    return uid
end

function love.update(dt)
    tween.update(dt)
    chrono:update(dt)
    game:update(dt)
end

function love.draw()
    game:draw()
    love.graphics.draw(cursor, love.mouse.getPosition()) 
    love.graphics.print(tostring(math.round(collectgarbage("count"), 0) .. 'Kb'), 10, 25)
    love.graphics.print("FPS: " .. love.timer.getFPS(), 10, 40)
end

function love.mousepressed(x, y, button)

end

function love.mousereleased(x, y, button)

end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == 'c' then collectgarbage() end
end

function love.keyreleased(key)

end
