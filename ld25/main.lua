require 'Intro'
require 'Level_1'
gl = require 'globals'
beholder = require 'beholder'

function love.load()
    love.graphics.setMode(1024, 768, false, true, 0)

    levels = {
        intro = Intro('intro'),
        level_1 = Level_1('level_1', 'gfx/level_1.png')
    }

    current_level = levels.intro
    beholder.observe('transition', 
                     function(level) current_level = levels[level] end)
end

function love.update(dt)
    current_level:update(dt) 
end

function love.draw()
    current_level:draw()
end

function love.keypressed(key)
    current_level:keypressed(key)
end

function love.run()
    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    if love.load then love.load(arg) end

    local t = 0
    local dt = 0
    local fixed_dt = 0.01 
    local accumulator = 0.0

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

        while dt > 0.0 do
            local delta = math.min(dt, fixed_dt)
            if love.update then love.update(delta) end
            dt = dt - delta
            t = t + delta
        end

        if love.graphics then
            love.graphics.clear()
            if love.draw then love.draw() end
        end

        if love.graphics then love.graphics.present() end
    end
end
