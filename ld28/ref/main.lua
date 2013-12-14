function love.load()
    love.graphics.setDefaultImageFilter('nearest', 'nearest')

    -- Libraries
    class = require 'libraries/middleclass/middleclass'
    require 'libraries/Vector'
    struct = require 'libraries/chrono/struct'
    beholder = require 'libraries/beholder/beholder'
    Camera = require 'libraries/hump/camera'
    GTimer = require 'libraries/hump/timer'
    require 'libraries/anal/AnAL'
    require 'libraries/TEsound'
    require 'utils'

    -- Data
    require 'game/data/data'
    require 'game/data/collision'
    require 'game/data/input'
    require 'game/data/visual'
    require 'game/data/groups'
    require 'game/data/particles'
    require 'game/data/items'
    require 'game/data/sound'
    require 'game/data/music'

    -- Mixins
    require 'game/mixins/EnemyExploder'
    require 'game/mixins/TNTExploder'
    require 'game/mixins/Fader'
    require 'game/mixins/HittableInvulnerable'
    require 'game/mixins/HittableRed'
    require 'game/mixins/Input'
    require 'game/mixins/IdleAnimatedVisual'
    require 'game/mixins/Jumper'
    require 'game/mixins/Movable'
    require 'game/mixins/PhysicsCircle'
    require 'game/mixins/PhysicsRectangle'
    require 'game/mixins/PlayerAttacker'
    require 'game/mixins/PlayerVisual'
    require 'game/mixins/Stats'
    require 'game/mixins/Steerable'
    require 'game/mixins/Timer'
    require 'game/mixins/Visual'
    require 'game/mixins/Modifiers'
    require 'game/mixins/ActiveItem'

    -- Entities
    require 'game/entities/Blaster'
    require 'game/entities/BreakableParticle'
    require 'game/entities/BreakableParticleMW'
    require 'game/entities/BreakableSolid'
    require 'game/entities/ChainedSpikedBall'
    require 'game/entities/Effect'
    require 'game/entities/Entity'
    require 'game/entities/FaderParticle'
    require 'game/entities/Item'
    require 'game/entities/JumpingPad'
    require 'game/entities/Ladder'
    require 'game/entities/MeleeArea'
    require 'game/entities/PhysicsParticle'
    require 'game/entities/Player'
    require 'game/entities/Roller'
    require 'game/entities/Solid'
    require 'game/entities/SpikedBall'
    require 'game/entities/Spikes'
    require 'game/entities/TNT'
    require 'game/entities/EnemyWall'
    require 'game/entities/Boulder'
    require 'game/entities/Pumper'
    require 'game/entities/PumperProjectile'
    require 'game/entities/Hammer'
    require 'game/entities/AntigravityRock'
    require 'game/entities/Trail'
    require 'game/entities/AntigravityRockTrail'
    require 'game/entities/SeekerParticle'
    require 'game/entities/PumperProjectileTrail'
    require 'game/entities/MovingWall'
    require 'game/entities/Button'
    require 'game/entities/Trigger'
    require 'game/entities/MovingEffect'
    require 'game/entities/Prop'
    require 'game/entities/Rail'
    require 'game/entities/MineCart'

    -- Main
    require 'game/Game'
    require 'game/Sound'

    initialize()
end

function initialize()
    uid = 0
    t = 0
    debug_draw = true 
    zoom = 2
    game_width = love.graphics.getWidth()
    game_height = love.graphics.getHeight()
    timer = GTimer.new()
    game = Game()
    sound = Sound()
end

function love.update(dt)
    sound:update(dt)
    t = t + dt
    timer:update(dt)
    game:update(dt)
    if game.current_run then game.current_run.current_floor.current_world.camera:zoomTo(zoom) end
end

function love.draw()
    game:draw()
    love.graphics.print('Camera zoom: ' .. zoom .. 'X', 10, 10)
    love.graphics.print(tostring(math.round(collectgarbage("count"), 0) .. 'Kb'), 10, 600)
    love.graphics.print("FPS: " .. love.timer.getFPS(), 10, 620)
end

function love.mousepressed(x, y, button)
    if button == 'wu' then zoom = zoom + 0.05 end
    if button == 'wd' then zoom = zoom - 0.05 end
end

function love.mousereleased(x, y, button)

end

function love.keypressed(key)
    game:keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == 'c' then collectgarbage("collect") end
    if key == 'b' then game.current_run.current_floor.current_world:createToGroup('Blaster', 200, 600) end
    if key == 'r' then game.current_run.current_floor.current_world:createToGroup('Roller', 800, 600) end
    if key == 'u' then game.current_run.current_floor.current_world:createToGroup('Boulder', 50, 100, {r = 15.5}) end
    if key == 'p' then game.current_run.current_floor.current_world:createToGroup('Pumper', math.random(200, 400), 600) end
    if key == 'f1' then debug_draw = not debug_draw end
    if key == '1' then 
        for _, group in ipairs(game.current_run.current_floor.current_world.groups) do
            if group.name == 'MovingWall' then
                for _, mw in ipairs(group:getEntities()) do
                    if mw.name == 'wall1' .. game.current_run.current_floor.current_world.id then
                        mw:trigger()
                    end
                end
            end
        end
    end
    if key == '2' then
        for _, group in ipairs(game.current_run.current_floor.current_world.groups) do
            if group.name == 'MovingWall' then
                for _, mw in ipairs(group:getEntities()) do
                    if mw.name == 'wall2' .. game.current_run.current_floor.current_world.id then
                        mw:trigger()
                    end
                end
            end
        end
    end
    --[[
    if key == '1' then game.current_run.current_floor.current_world.layers = {unpack(game.current_run.current_floor.current_world.layers_1)} end
    if key == '2' then game.current_run.current_floor.current_world.layers = {unpack(game.current_run.current_floor.current_world.layers_2)} end
    if key == '3' then game.current_run.current_floor.current_world.layers = {unpack(game.current_run.current_floor.current_world.layers_3)} end
    if key == '4' then game.current_run.current_floor.current_world.layers = {unpack(game.current_run.current_floor.current_world.layers_4)} end
    ]]--
end

function love.keyreleased(key)
    game:keyreleased(key)
end

-- 0.8
function love.run()
    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    if love.load then love.load(arg) end

    local t = 0
    local dt = 0
    local fixed_dt = 1/60 
    local accumulator = 0

    -- Main loop time
    while true do
        -- Process events
        if love.event then
            love.event.pump()
            for e, a, b, c, d in love.event.poll() do
                if e == "quit" then
                    if not love.quit or not love.quit() then
                        if love.audio then
                            love.audio.stop()
                        end
                        return
                    end
                end
                love.handlers[e](a, b, c, d)
            end
        end

        -- Update dt, as we'll be passing it to update
        if love.timer then
            love.timer.step()
            dt = love.timer.getDelta()
        end

        accumulator = accumulator + dt

        while accumulator >= fixed_dt do
            if love.update then love.update(fixed_dt) end
            accumulator = accumulator - fixed_dt
            t = t + fixed_dt
        end

        if love.graphics then
            love.graphics.clear()
            if love.draw then love.draw() end
        end

        if love.timer then love.timer.sleep(0.001) end
        if love.graphics then love.graphics.present() end
    end
end

-- 0.9
--[[
function love.run()
    math.randomseed(os.time())
    math.random() math.random()

    if love.event then love.event.pump() end
    if love.load then love.load(arg) end

    local dt = 0
    local fixed_dt = 1/60
    local accumulator = 0

    -- Main loop time.
    while true do
        -- Process events.
        if love.event then
            love.event.pump()
            for e,a,b,c,d in love.event.poll() do
                if e == "quit" then
                    if not love.quit or not love.quit() then
                        if love.audio then love.audio.stop() end
                        return
                    end
                end
                love.handlers[e](a,b,c,d)
            end
        end

        -- Update dt, as we'll be passing it to update
        if love.timer then
            love.timer.step()
            dt = love.timer.getDelta()
        end

        -- Call update and draw
        accumulator = accumulator + dt
        while accumulator >= fixed_dt do
            if love.update then love.update(fixed_dt) end
            accumulator = accumulator - fixed_dt
        end

        if love.window and love.graphics then
            love.graphics.clear()
            love.graphics.origin()
            if love.draw then love.draw() end
            love.graphics.present()
        end

        if love.timer then love.timer.sleep(0.001) end
    end
end
--]]
