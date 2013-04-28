function love.load()
    reload()
end

function reload()
    UID = 0 function getID() UID = UID + 1; return UID end
    function copy(t) local copy = {} for k, v in pairs(t) do copy[k] = v end return copy end
    physics_meter = 16
    game_over = false 
    game_paused = false
    game_ui = false
    enemy_counter = 30
    enemies_killed = 0
    score = 0
    current_weapon_level = 0
    current_attack_table = {} 
    current_attack_string = nil

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

    score_help = love.graphics.newImage('res/score_help.png')
    weapon_help = love.graphics.newImage('res/weapon_help.png')
    win_help = love.graphics.newImage('res/win_help.png')
    win2_help = love.graphics.newImage('res/win2_help.png')
    attack_help = love.graphics.newImage('res/attack_help.png')
    upgrade_help = love.graphics.newImage('res/upgrade_help.png')

    require 'lib/middleclass/middleclass'
    require 'lib/chrono/chrono'
    struct = require 'lib/chrono/struct'
    beholder = require 'lib/beholder/beholder'
    Vector = require 'lib/hump/vector'
    Camera = require 'lib/hump/camera'
    tween = require 'lib/tween/tween'
    anim8 = require 'lib/anim8/anim8'

    require 'Level'

    chrono = Chrono()
    camera = Camera()
    level = Level()

    love.graphics.setFont(font12)
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)
end

function love.update(dt)
    if not game_over and not game_paused then 
        tween.update(dt)
        chrono:update(dt)
        level:update(dt) 
    end
    if enemy_counter <= 0 then game_over = true end
end

function love.draw()
    camera:attach()
    level:draw()
    camera:detach()
    
    if game_paused then
        love.graphics.setColor(64, 64, 64, 192)
        love.graphics.rectangle('fill', 0, 0, 1024, 872)
        love.graphics.setColor(255, 255, 255, 255)
    end

    love.graphics.setFont(font96)
    love.graphics.setColor(0, 0, 0)
    if not game_over then 
        local w = font80:getWidth(score)
        love.graphics.print(score, 200-w/2, -32)
        local w = font80:getWidth(current_weapon_level)
        love.graphics.print(current_weapon_level, 168+592-w/2, -32)
        local w = font80:getWidth(enemy_counter)
        love.graphics.print(enemy_counter, 200+300-w/2, 184+448)
        love.graphics.setFont(font16)
        local weapon_modifiers_text = buildTextFromAttack(level.player.attack)
        local w = font16:getWidth(weapon_modifiers_text)
        love.graphics.print(weapon_modifiers_text, 8, 832)
        love.graphics.print('Press ESC for help!', 764, 832) 
    end

    if game_over then
        love.graphics.setFont(font48)
        local w = font48:getWidth('RIP in pieces. Retry (r)')
        love.graphics.print('RIP in pieces. Retry (r)', 212+300-w/2, 436-96)
    end

    if game_paused then
        if not game_ui then
            love.graphics.setColor(255, 255, 255)
            love.graphics.draw(score_help, -24, 152)
            love.graphics.draw(weapon_help, 680, 160)
            love.graphics.draw(win_help, 616, 736)
            love.graphics.draw(win2_help, 254, 392)
            love.graphics.draw(attack_help, -32, 792)
        end
    end

    if game_ui then
        love.graphics.setColor(255, 255, 255)
        love.graphics.draw(upgrade_help, 64, 16)
        love.graphics.setFont(font24)
        love.graphics.setColor(255, 255, 255)
        love.graphics.print('Damage', 168, 128)
        love.graphics.print('Cooldown-', 416, 128)
        love.graphics.print('cooldowN+', 660, 128)
        love.graphics.print('Multiple', 168, 260)
        love.graphics.print('Speed-', 452, 260)
        love.graphics.print('speeD+', 720, 260)
        love.graphics.print('Pierce', 168, 392)
        love.graphics.print('Reflecting', 416, 392)
        love.graphics.print('Area', 760, 392)
        love.graphics.print('area siZe', 168, 524)
        love.graphics.print('area damaGe', 392, 524)
        love.graphics.print('area sLow', 682, 524)
        love.graphics.print('area damage cOoldown+', 16, 656)
        love.graphics.print('area damage cooldoWn-', 544, 656)
        love.graphics.print('area eXploding', 360, 788)
    end
end

function buildTextFromAttack(attack)
    local string = ""
    for k, v in pairs(attack.modifiers) do
        if k == 'multiple' then for i = 1, attack.modifiers.multiple do string = string .. 'M' end
        elseif k == 'pierce' then for i = 1, attack.modifiers.pierce do string = string .. 'P' end
        elseif k == 'reflect' then for i = 1, attack.modifiers.reflect do string = string .. 'R' end
        elseif k == 'damage' then if attack.modifiers.damage then string = string .. 'D' .. attack.modifiers.damage end
        elseif k == 'back' then if attack.modifiers.back then string = string .. 'B' end
        elseif k == 'cooldown' then string = string .. 'C' .. attack.modifiers.cooldown
        elseif k == 'area' then 
            if attack.modifiers.area then
                if areas[attack.modifiers.area].cooldown then string = string .. 'AC' .. areas[attack.modifiers.area].cooldown end
                if areas[attack.modifiers.area].damage then string = string .. 'AD' .. areas[attack.modifiers.area].damage end
                if areas[attack.modifiers.area].slow then string = string .. 'AL' .. areas[attack.modifiers.area].slow end
                if areas[attack.modifiers.area].on_hit then string = string .. 'AE' .. areas[attack.modifiers.area].slow end
            end
        end
    end
    return string
end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == 's' then score = score + 100 end
    if key == 'u' then 
        if not game_over and not game_paused then
            game_paused = true
            game_ui = true
        end
    end
    if key == 'escape' then 
        if not game_over then
            game_paused = not game_paused 
            game_ui = false
        end
    end
    if key == 'r' then
        if game_over then
            game_over = false
            reload()
        end
    end

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