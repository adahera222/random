require 'Intro'
require 'Level_1'
require 'Level_2'
require 'Level_3'
require 'Room'
gl = require 'globals'
beholder = require 'beholder'

function love.load()
    gl.width = love.graphics.getWidth()
    gl.height = love.graphics.getHeight()

    transition_delay = 1
    transition_c = 0
    change_level = false
    change_level_new = false
    to_level = nil
    supported = love.graphics.isSupported('canvas', 'pixeleffect')

    if supported then
        canvas = love.graphics.newCanvas()

        effect = love.graphics.newPixelEffect[[
           extern number t;
           extern number tt;
           extern number vignetteIntensity;
           vec4 effect(vec4 color, Image texture, vec2 texture_coords, vec2 screen_coords) {
               vec4 texcolor = Texel(texture, texture_coords);
               float g;

               if (tt == 1) {
                   g = dot(texcolor.rgb, vec3(0.299, 0.587, 0.114));
                   vec2 dist = texture_coords - 0.5f;
                   texcolor = vec4(g*vec3(1.2, 1.0, 0.8)*(1-dot(dist,dist)*vignetteIntensity), texcolor.a);
               }

               return texcolor*t;
           }
        ]]
    end

    levels = {
        level_1 = Level_1('level_1', 'gfx/level_1.png'),
        level_2 = Level_2('level_2', 'gfx/level_2.png'),
        level_3 = Level_3('level_3', 'gfx/level_3.png'),
        room_1 = Room('room_1', 'gfx/room_1.png', 'level_1', 'gun_1'),
        room_2 = Room('room_2', 'gfx/room_2.png', 'level_2', 'gun_1'),
        room_3 = Room('room_3', 'gfx/room_3.png', 'level_3', 'gun_1'),
        room_4 = Room('room_4', 'gfx/room_4.png', 'room_5', 'gun_1'),
        room_5 = Room('room_5', 'gfx/room_5.png', '', 'gun_2')
    }

    current_level = levels.room_5
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

    if supported then
        if current_level.name == 'level_1' or current_level.name == 'level_2' or current_level.name == 'level_3' then
            effect:send("tt", 1)
        else effect:send("tt", 2) end
        effect:send("vignetteIntensity", math.random(40,60)/100)
        effect:send("t", 1-transition_c)
    end
    current_level:update(dt) 
end

function love.draw()
    if supported then
        canvas:clear()
        love.graphics.setPixelEffect(effect)
        canvas:renderTo(function() current_level:draw() end)
        love.graphics.draw(canvas, 0, 0)
        love.graphics.setPixelEffect()
    else current_level:draw() end
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
