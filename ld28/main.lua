function love.load()
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
    require 'Game'
    require 'Planet'
    require 'Resource'
    require 'ResourceFader'
    require 'People'
    require 'PeopleFader'
    require 'MouseFader'
    require 'ActiveLine'
    require 'ConnectLine'

    t = 0
    uid = 0
    love.window.setMode(1280, 800, {centered = true, display = 1, fsaa = 4})
    love.graphics.setLineStyle('rough')
    game_width = love.graphics.getWidth()
    game_height = love.graphics.getHeight()
    timer = GTimer.new()
    -- camera = Camera(4.5*game_width, game_height/2)
    camera = Camera()
    main_font_huge = love.graphics.newFont('Moon Flower.ttf', 128)
    main_font_big = love.graphics.newFont('Moon Flower.ttf', 96)
    main_font_small = love.graphics.newFont('Moon Flower.ttf', 48)

    bg_color = {232, 232, 232}
    love.graphics.setBackgroundColor(bg_color[1], bg_color[2], bg_color[3])
    love.graphics.setFont(main_font_huge)
    love.mouse.setVisible(false)
    love.mouse.setGrabbed(true)
    camerat = {actual_zoom = 1, zoom = 1, can_zoom = false, v = Vector(0, 0), a = Vector(0, 0), v_multiplier = 0.05, 
               moving = {left = false, right = false, up = false, down = false}, damping = 0.95}
    mouse = {x = 0, y = 0, radius = 4, color = {32, 32, 32}, pressed = false, active = false}
    mouse.x, mouse.y = love.mouse.getPosition()
    mouse_faders = {}

    in_intro = true
    in_game = false
    intro = Intro()
    game_intro = {alpha = 255}
    createGame()
end

function createGame()
    camera:lookAt(game_width/2, game_height/2)
    timer:tween(4, bg_color, {232, 232, 232}, 'in-out-cubic')
    timer:tween(4, game_intro, {alpha = 0}, 'in-out-cubic') 
    timer:after(4, function() camerat.can_zoom = true end)
    in_intro = false
    in_game = true
    game = Game()
end

function love.update(dt)
    t = t + dt
    mouse.x, mouse.y = love.mouse.getPosition()
    for i = #mouse_faders, 1, -1 do
        if mouse_faders[i].dead then table.remove(mouse_faders, i) end
    end
    timer:update(dt)
    if in_intro then intro:update(dt) end
    if in_game then game:update(dt) end
end

function love.draw()
    love.graphics.setBackgroundColor(bg_color[1], bg_color[2], bg_color[3])
    camera:attach()
    if in_intro then intro:draw() end
    if in_game then 
        love.graphics.setColor(32, 32, 32, game_intro.alpha)
        local wx, wy = camera:pos()
        wx, wy = wx - game_width/2, wy - game_height/2
        love.graphics.rectangle('fill', wx, wy, game_width, game_height)
        love.graphics.setColor(255, 255, 255, 255)
        game:draw() 
    end
    for _, mouse_fader in ipairs(mouse_faders) do mouse_fader:draw() end
    camera:detach()
    love.graphics.setFont(main_font_small)
    love.graphics.setColor(32, 32, 32, game.people_left_alpha)
    love.graphics.print("#PEOPLE ALIVE: " .. #game.people .. " (must be >15)", 10, game_height - main_font_small:getHeight())
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.setColor(mouse.color[1], mouse.color[2], mouse.color[3])
    love.graphics.setLineWidth(2)
    love.graphics.circle('line', mouse.x, mouse.y, mouse.radius, 360)
end

function love.keypressed(key)
    if key == 'escape' or key == 'q' then love.event.push('quit') end
end

function love.mousepressed(x, y, button)
    if button == 'l' or button == 'r' then
        mouse.pressed = true
        timer:tween(0.25, mouse, {radius = 2}, 'out-elastic')
    end
    if in_intro then intro:mousepressed(x, y, button) end
    if in_game then game:mousepressed(x, y, button) end
end

function love.mousereleased(x, y, button)
    if button == 'l' or button == 'r' then
        mouse.pressed = false
        timer:tween(0.5, mouse, {radius = 4}, 'out-elastic')
        local wx, wy = camera:worldCoords(mouse.x, mouse.y)
        table.insert(mouse_faders, MouseFader(wx, wy, {color = mouse.color}))
    end
    if in_intro then intro:mousereleased(x, y, button) end
    if in_game then game:mousereleased(x, y, button) end
end

function randomInCircle(r)
    local x = math.prandom(0, 1)*2*r - r
    local y = math.prandom(0, 1)*math.sqrt(r*r - x*x)*2-math.sqrt(r*r - x*x)
    return x, y
end

function xyCollidingPerson(x, y, person)
    local d = Vector.distance(Vector(x, y), Vector(person.x, person.y))
    if d <= 2*person.size then return true end
    return false
end

function mouseCollidingPerson(person)
    local x, y = camera:worldCoords(mouse.x, mouse.y)
    local d = Vector.distance(Vector(x, y), Vector(person.x, person.y))
    if d <= person.size then return true end
    return false
end

function xyCollidingResource(x, y, resource)
    local d = Vector.distance(Vector(x, y), Vector(resource.x, resource.y))
    if d > 2*resource.size then return false end
    return true    
end

function mouseCollidingResource(resource)
    local x, y = camera:worldCoords(mouse.x, mouse.y)
    local d = Vector.distance(Vector(x, y), Vector(resource.x, resource.y))
    if d > resource.size then return false end
    return true

    --[[
    local nvert = #resource.points/2
    local xvert, yvert = {}, {}
    for i = 1, #resource.points do
        if i % 2 ~= 0 then table.insert(xvert, resource.points[i]) end
        if i % 2 == 0 then table.insert(yvert, resource.points[i]) end
    end
    local result = false
    local j = nvert
    for i = 1, nvert do
        if ((yvert[i] > y) ~= (yvert[j] > y)) and (x < (xvert[j]-xvert[i])*(y-yvert[i])/(yvert[j]-yvert[i]) + xvert[i]) then
            result = not result
        end
        j = i
    end
    return result 
    ]]--
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
