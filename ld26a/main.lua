luid = 0

function love.load()
    W = love.graphics.getWidth()
    H = love.graphics.getHeight()
    reload()
    -- TEsound.playLooping({'res/ogre.ogg', 'res/age.ogg', 'res/dogs.ogg'})
end

function reload()
    UID = 0 function getID() UID = UID + 1; return UID end
    function copy(t) local copy = {} for k, v in pairs(t) do copy[k] = v end return copy end
    physics_meter = 16
    game_paused = false

    font12 = love.graphics.newFont('res/Fipps-Regular.otf', 12)
    font16 = love.graphics.newFont('res/Fipps-Regular.otf', 16)
    font20 = love.graphics.newFont('res/Fipps-Regular.otf', 20)
    font24 = love.graphics.newFont('res/Fipps-Regular.otf', 24)
    font28 = love.graphics.newFont('res/Fipps-Regular.otf', 28)
    font32 = love.graphics.newFont('res/Fipps-Regular.otf', 32)
    font48 = love.graphics.newFont('res/Fipps-Regular.otf', 48)
    font64 = love.graphics.newFont('res/Fipps-Regular.otf', 64)
    font80 = love.graphics.newFont('res/Fipps-Regular.otf', 80)
    font96 = love.graphics.newFont('res/Fipps-Regular.otf', 96)

    require 'lib/middleclass/middleclass'
    require 'lib/chrono/chrono'
    require 'lib/TEsound/TEsound'
    struct = require 'lib/chrono/struct'
    beholder = require 'lib/beholder/beholder'
    Vector = require 'lib/hump/vector'
    Camera = require 'lib/hump/camera'
    tween = require 'lib/tween/tween'
    anim8 = require 'lib/anim8/anim8'

    require 'utils'
    require 'Level'

    attack = struct('activation', 'cooldown', 'damage', 'multiple', 'pierce', 'reflect', 'back', 'area', 'speed')
    area = struct('r_i', 'r_f', 'duration', 'tween', 'on_hit', 'cooldown', 'damage', 'slow')
    areas = {}
    areas['initial'] = area(48, 48, 0, false, false, 1, 0, false)
    initial_attack = Attack(attack('hold', 0.3, 10, 1, 0, 0, false, false, 200))

    chrono = Chrono()
    camera = Camera()
    level = Level()

    love.graphics.setFont(font12)
    love.graphics.setColor(255, 255, 255)
end

function love.update(dt)
    if not game_paused then 
        tween.update(dt)
        chrono:update(dt)
        level:update(dt) 
    end

    TEsound.cleanup()
end

function love.draw()
    camera:attach()
    level:draw()
    camera:detach()
end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == 'escape' then if not game_over then game_paused = not game_paused end end
    level:keypressed(key)  
end

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

        if love.graphics then love.graphics.present() end
    end
end
