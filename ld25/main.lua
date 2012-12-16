require 'Intro'
require 'Level_1'
require 'Level_2'
require 'Level_3'
require 'Room'
gl = require 'globals'
beholder = require 'beholder'

function love.load()
    love.graphics.setMode(1024, 768, false, false, 0)
    gl.width = love.graphics.getWidth()
    gl.height = love.graphics.getHeight()

    transition_delay = 1
    transition_c = 0
    change_level = false
    change_level_new = false
    to_level = nil

    transition_effect = love.graphics.newPixelEffect[[
       extern number t;
       vec4 effect(vec4 color, Image texture, vec2 texture_coords, vec2 screen_coords) {
           vec4 dd = Texel(texture, texture_coords);
           return dd*t;
       }
    ]]

    levels = {
        level_1 = Level_1('level_1', 'gfx/level_1.png'),
        level_2 = Level_2('level_2', 'gfx/Level_2.png'),
        level_3 = Level_3('level_3', 'gfx/Level_3.png'),
        room_1 = Room('room_1', 'gfx/room_1.png', 'level_1', 'gun_1'),
        room_2 = Room('room_2', 'gfx/room_2.png', 'level_2', 'gun_1'),
        room_3 = Room('room_3', 'gfx/room_3.png', 'level_3', 'gun_1'),
        room_4 = Room('room_4', 'gfx/room_4.png', 'room_5', 'gun_1')
    }

    current_level = levels.room_4
    beholder.observe('transition', 
                     function(level) 
                         change_level = true
                         to_level = level
                     end)
    beholder.observe('transition_self',
                     function(level)
                         change_level_new = true
                         to_level = level
                     end)

end

function love.update(dt)
    if change_level or change_level_new then
        transition_c = transition_c + dt
    end

    if transition_c >= transition_delay then 
        transition_c = 0

        if change_level_new then
            if to_level == 'level_3' then
                current_level = Level_3('level_3', 'gfx/Level_3.png')
            end
        else current_level = levels[to_level] end
        change_level = false
        change_level_new = false
    end
    
    transition_effect:send("t", 1-transition_c)
    current_level:update(dt) 
end

function love.draw()
    love.graphics.setPixelEffect(transition_effect)
    current_level:draw()
    love.graphics.setPixelEffect()
end

function love.keypressed(key)
    current_level:keypressed(key)
end

function love.mousepressed(x, y, button)
    current_level:mousepressed(x, y, button)
end

function love.run()
    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    if love.load then love.load(arg) end

    local t = 0
    local dt = 0
    local fixed_dt = 1/60 
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
