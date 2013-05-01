luid = 0

function love.load()
    reload()
    -- TEsound.playLooping({'res/ogre.ogg', 'res/age.ogg', 'res/dogs.ogg'})
    W = love.graphics.getWidth()
    H = love.graphics.getHeight()
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
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)

    red = love.graphics.newPixelEffect[[
        vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
            vec4 c = Texel(tex, tc);
            return vec4(c.r, 0, 0, c.a);
        }
    ]]
    green = love.graphics.newPixelEffect[[
        vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
            vec4 c = Texel(tex, tc);
            return vec4(0, c.g, 0, c.a);
        }
    ]]
    blue = love.graphics.newPixelEffect[[
        vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
            vec4 c = Texel(tex, tc);
            return vec4(0, 0, c.b, c.a);
        }
    ]]
    screen = love.graphics.newPixelEffect[[
        extern Image img;
        vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
            vec4 base = Texel(tex, tc);
            vec4 blend = Texel(img, tc);
            return vec4(1-((1-base)*(1-blend)));
        }
    ]]

    normal_canvas = love.graphics.newCanvas()
    r_screen_canvas = love.graphics.newCanvas()
    g_screen_canvas = love.graphics.newCanvas()
    b_screen_canvas = love.graphics.newCanvas()
    gb_screen_canvas = love.graphics.newCanvas()
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
    local n = 2
    normal_canvas:clear()
    r_screen_canvas:clear()
    g_screen_canvas:clear()
    b_screen_canvas:clear()
    gb_screen_canvas:clear()
    camera:attach()
    love.graphics.setColor(64, 64, 64)
    level:draw()
    normal_canvas:renderTo(function() level:draw() end)
    r_screen_canvas:renderTo(function()
        love.graphics.setPixelEffect(red)
        love.graphics.draw(normal_canvas, math.random(0, 2*n)-n, math.random(0, 2*n)-n)
    end)
    g_screen_canvas:renderTo(function()
        love.graphics.setPixelEffect(green)
        love.graphics.draw(normal_canvas, math.random(0, 2*n)-n, math.random(0, 2*n)-n) 
    end)
    b_screen_canvas:renderTo(function()
        love.graphics.setPixelEffect(blue)
        love.graphics.draw(normal_canvas, math.random(0, 2*n)-n, math.random(0, 2*n)-n)
    end)
    screen:send("img", g_screen_canvas)
    gb_screen_canvas:renderTo(function()
        love.graphics.setPixelEffect(screen)
        love.graphics.draw(b_screen_canvas, 0, 0)
    end)
    screen:send("img", gb_screen_canvas)
    love.graphics.setPixelEffect(screen)
    love.graphics.draw(r_screen_canvas, 0, 0)
    love.graphics.setPixelEffect()
    camera:detach()
    
    if game_paused then
        love.graphics.setColor(32, 32, 32, 240)
        love.graphics.rectangle('fill', 0, 0, 1024, 872)
        love.graphics.setColor(255, 255, 255, 255)
    end
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
