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

    require 'Entity'
    require 'Intro'
    require 'Planet'
    require 'Resource'
    require 'ResourceFader'
    require 'DrainParticle'

    t = 0
    uid = 0
    game_width = love.graphics.getWidth()
    game_height = love.graphics.getHeight()
    timer = GTimer.new()
    -- camera = Camera(2.5*game_width, game_height/2)
    camera = Camera()
    main_font_huge = love.graphics.newFont('Moon Flower.ttf', 128)

    love.graphics.setBackgroundColor(232, 232, 232)
    love.graphics.setFont(main_font_huge)

    intro = Intro()
end

function love.update(dt)
    t = t + dt
    timer:update(dt)
    intro:update(dt)
end

function love.draw()
    camera:attach()
    intro:draw()
    camera:detach()
end

function love.mousepressed(x, y, button)
    intro:mousepressed(x, y, button)
end

function love.mousereleased(x, y, button)
    intro:mousereleased(x, y, button)
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
