reloadb = false

function love.load()
    reload()
    TEsound.playLooping({'res/ogre.wav', 'res/age.wav', 'res/dogs.wav'})
end

function reload()
    UID = 0 function getID() UID = UID + 1; return UID end
    function copy(t) local copy = {} for k, v in pairs(t) do copy[k] = v end return copy end
    physics_meter = 16
    game_over = false 
    game_paused = false
    game_ui = false
    game_won = false
    enemy_counter = 30
    enemies_killed = 0
    score = 0
    score_rate = 0
    current_weapon_level = 0
    proj_speeds = {50, 100, 200, 300, 400}
    proj_speeds_pointer = 3
    area_sizes = {48, 64, 96, 128, 256} 
    area_sizes_pointer = 1
    area_slows = {0.75, 0.5, 0.25, 0.1}
    area_slows_pointer = 0
    last_key = nil
    last_keys = {}

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
    esc_help = love.graphics.newImage('res/esc_help.png')
    apply_help = love.graphics.newImage('res/apply_help.png')
    undo_help = love.graphics.newImage('res/undo_help.png')
    square = love.graphics.newImage('res/square.png')

    require 'lib/middleclass/middleclass'
    require 'lib/chrono/chrono'
    require 'lib/TEsound/TEsound'
    struct = require 'lib/chrono/struct'
    beholder = require 'lib/beholder/beholder'
    Vector = require 'lib/hump/vector'
    Camera = require 'lib/hump/camera'
    tween = require 'lib/tween/tween'
    anim8 = require 'lib/anim8/anim8'

    require 'Level'

    attack = struct('activation', 'cooldown', 'damage', 'multiple', 'pierce', 'reflect', 'back', 'area', 'speed')
    area = struct('r_i', 'r_f', 'duration', 'tween', 'on_hit', 'cooldown', 'damage', 'slow')
    areas = {}
    areas['initial'] = area(48, 48, 0, false, false, 1, 0, false)
    areas['main'] = area(48, 48, 0, false, false, 1, 0, false)
    initial_attack = Attack(attack('hold', 0.3, 10, 1, 0, 0, false, false, 200))
    stub_attack = attack('hold', 0, 0, 0, 0, 0, false, 'initial') 
    current_attack_table = Attack(attack('hold', 1, 0, 1, 0, 0, false, false, 200))
    current_attack_string = nil
    total_cost = calculateTotalCost(current_attack_table)

    chrono = Chrono()
    camera = Camera()
    level = Level()

    love.graphics.setFont(font12)
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)

    if not reloadb then game_paused = true end

    -- Perfection is achieved, not when there is nothing more to add, but when there is nothing left to take away.
end

function love.update(dt)
    if not game_over and not game_paused and not game_won then 
        tween.update(dt)
        chrono:update(dt)
        level:update(dt) 
        current_weapon_level = round(calculateTotalCost(level.player.attack), 1)
        score = score + current_weapon_level/1000
        score_rate = round(current_weapon_level/1000, 3)
        score = round(score, 2)
        if enemy_counter <= 0 then 
            if not game_over then
                game_over = true
            end
        end
        if 100-enemies_killed <= 0 then game_won = true end
    end

    TEsound.cleanup()
end

function love.draw()
    camera:attach()
    level:draw()
    camera:detach()
    
    if game_paused then
        love.graphics.setColor(32, 32, 32, 240)
        love.graphics.rectangle('fill', 0, 0, 1024, 872)
        love.graphics.setColor(255, 255, 255, 255)
    end

    love.graphics.setFont(font64)
    love.graphics.setColor(0, 0, 0)
    if not game_over and not game_won then 
        local w = font64:getWidth(score)
        love.graphics.print(score, 192-w/2, 16)
        local w = font64:getWidth(current_weapon_level)
        love.graphics.print(current_weapon_level, 212+592-w/2, 16)
        love.graphics.setFont(font16)
        local w = font16:getWidth("+(" .. score_rate .. ")")
        love.graphics.print("+(" .. score_rate .. ")", 192-w/2, 140)
        love.graphics.setFont(font80)
        local w = font80:getWidth(enemy_counter)
        love.graphics.print(enemy_counter, 212+300-w/2, 184+448)
        local w = font16:getWidth('Enemies left: ' .. 100 - enemies_killed)
        love.graphics.setFont(font16)
        love.graphics.print('Enemies left: ' .. 100 - enemies_killed, 212+300-w/2, 0)
        love.graphics.setFont(font16)
        local weapon_modifiers_text = buildTextFromAttack(level.player.attack)
        local w = font16:getWidth(weapon_modifiers_text)
        love.graphics.setColor(255, 192, 255)
        if not game_ui then love.graphics.print(weapon_modifiers_text, 8, 832) end
        love.graphics.setColor(0, 0, 0)
        if not game_ui then love.graphics.print('Press ESC for help!', 764, 832) end
    end

    if game_over then
        love.graphics.setFont(font48)
        local w = font48:getWidth('RIP in pieces. Retry (r)')
        love.graphics.print('RIP in pieces. Retry (r)', 212+300-w/2, 436-96)
    end

    if game_won then
        love.graphics.setFont(font48)
        local w = font48:getWidth("You won! Score: " .. score .. '!')
        love.graphics.print("You won! Score: " .. score .. '!', 212+300-w/2, 436-96)
        local w = font48:getWidth('Play again! (r)')
        love.graphics.print('Play again! (r)', 212+300-w/2, 436)
    end

    if game_paused then
        if not game_ui then
            love.graphics.setColor(255, 255, 255)
            love.graphics.draw(score_help, -24, 152)
            love.graphics.draw(weapon_help, 680, 160)
            love.graphics.draw(win_help, 596, 720)
            love.graphics.draw(win2_help, 254, 392)
            love.graphics.draw(esc_help, 312, 524)
            love.graphics.draw(attack_help, -32, 792)
            love.graphics.setFont(font64)
            local w = font64:getWidth(score)
            love.graphics.print(score, 192-w/2, 16)
            local w = font64:getWidth(current_weapon_level)
            love.graphics.print(current_weapon_level, 212+592-w/2, 16)
            love.graphics.setFont(font80)
            local w = font80:getWidth(enemy_counter)
            love.graphics.print(enemy_counter, 212+300-w/2, 184+448)
        end
    end

    if game_ui then
        love.graphics.setColor(255, 255, 255)
        love.graphics.draw(upgrade_help, 64, 16)
        love.graphics.setColor(255, 0, 0)
        love.graphics.setFont(font24)
        love.graphics.setColor(255, 255, 255)
        if current_attack_table.modifiers.damage >= 100 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Damage', 168, 128)
        if current_attack_table.modifiers.cooldown <= 0.1999 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Cooldown-', 416, 128)
        if current_attack_table.modifiers.cooldown >= 3 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('cooldowN+', 660, 128)
        if current_attack_table.modifiers.multiple >= 8 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Multiple', 168, 228)
        if proj_speeds_pointer <= 1 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Speed-', 452, 228)
        if proj_speeds_pointer >= #proj_speeds then love.graphics.setColor(192, 192, 192) 
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('speEd+', 720, 228)
        if current_attack_table.modifiers.pierce >= 8 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Pierce', 168, 328)
        if current_attack_table.modifiers.reflect >= 8 then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Reflect', 360, 328)
        if current_attack_table.modifiers.back then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Back', 580, 328)
        if current_attack_table.modifiers.area then love.graphics.setColor(192, 192, 192)
        else love.graphics.setColor(255, 255, 255) end
        love.graphics.print('Area', 760, 328)
        if not current_attack_table.modifiers.area then love.graphics.setColor(192, 192, 192); area_locked = true
        else love.graphics.setColor(255, 255, 255); area_locked = false end
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if area_sizes_pointer >= #area_sizes then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area siZe', 168, 428)
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if areas['main'].damage >= 50 then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area damaGe', 392, 428)
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if area_slows_pointer >= #area_slows then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area sLow', 682, 428)
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if areas['main'].cooldown >= 2 then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area damage cOoldown+', 16, 528)
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if areas['main'].cooldown <= 0.59999 then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area damage cooldoWn-', 544, 528)
        if not area_locked then love.graphics.setColor(255, 255, 255) end
        if areas['main'].on_hit then love.graphics.setColor(192, 192, 192) end
        love.graphics.print('area eXploding', 360, 628)

        love.graphics.setFont(font16)
        love.graphics.setColor(255, 192, 255)
        local w = font16:getWidth('Your attack: ' .. buildTextFromAttack(current_attack_table))
        love.graphics.print('Your attack: ' .. buildTextFromAttack(current_attack_table), 500-w/2, 736)
        love.graphics.setColor(255, 192, 192)
        local w = font16:getWidth("Your attack's cost: " .. total_cost)
        love.graphics.print("Your attack's cost: " .. total_cost, 500-w/2, 768)

        love.graphics.setColor(255, 255, 255)
        love.graphics.draw(esc_help, -44, 832)
        love.graphics.draw(apply_help, 628, 832)
        love.graphics.draw(undo_help, 712, 800)
    end
end

function chance(n, action)
    local c = math.random(1, 100)
    if c < n*100 then action() end
end


function buildTextFromAttack(attack)
    local string = ""
    for k, v in pairs(attack.modifiers) do
        if k == 'multiple' then if attack.modifiers.multiple then if attack.modifiers.multiple > 0 then string = string .. 'M' .. attack.modifiers.multiple .. '#' end end
        elseif k == 'pierce' then if attack.modifiers.pierce then if attack.modifiers.pierce > 0 then string = string .. 'P' .. attack.modifiers.pierce .. '#' end end
        elseif k == 'reflect' then if attack.modifiers.reflect then if attack.modifiers.reflect > 0 then string = string .. 'R' .. attack.modifiers.reflect .. '#' end end
        elseif k == 'damage' then if attack.modifiers.damage then if attack.modifiers.damage > 0 then string = string .. 'D' .. attack.modifiers.damage .. '#' end end
        elseif k == 'back' then if attack.modifiers.back then string = string .. 'B' .. '#' end
        elseif k == 'cooldown' then string = string .. 'C' .. attack.modifiers.cooldown .. '#'
        elseif k == 'speed' then string = string .. 'S' .. attack.modifiers.speed .. '#'
        elseif k == 'area' then 
            if attack.modifiers.area then
                if areas[attack.modifiers.area].cooldown then string = string .. 'AC' .. areas[attack.modifiers.area].cooldown .. '#' end
                if areas[attack.modifiers.area].damage then if areas[attack.modifiers.area].damage > 0 then string = string .. 'AD' .. areas[attack.modifiers.area].damage .. '#' end end
                if areas[attack.modifiers.area].slow then string = string .. 'AL' .. areas[attack.modifiers.area].slow .. '#' end
                if areas[attack.modifiers.area].on_hit then string = string .. 'AE' .. '#' end
                if areas[attack.modifiers.area].r_f then string = string .. 'AS' .. areas[attack.modifiers.area].r_f .. '#' end
            end
        end
    end
    string = string.sub(string, 1, -2)
    return string
end

function round(n, p)
    local m = math.pow(10, p or 0)
    return math.floor(n*m+0.5)/m
end

function calculateTotalCost(attack)
    local total_cost = 0
    local damage_cost = (attack.modifiers.damage*attack.modifiers.damage)/100
    local cooldown_cost = 0
    if attack.modifiers.cooldown > 1 then cooldown_cost = -attack.modifiers.cooldown*attack.modifiers.cooldown*10
    elseif attack.modifiers.cooldown < 1 then cooldown_cost = (1/attack.modifiers.cooldown)*10
    else cooldown_cost = 0 end
    local multiple_cost = (attack.modifiers.multiple*attack.modifiers.multiple)
    local pierce_cost = (attack.modifiers.pierce*attack.modifiers.pierce)
    local reflect_cost = (attack.modifiers.reflect*attack.modifiers.reflect)
    local speed_cost = 0
    if attack.modifiers.back then back_cost = 25 else back_cost = 0 end
    if attack.modifiers.speed then
        speed_cost = attack.modifiers.speed/4
    else speed_cost = 0 end
    local area_cost = 0
    local area_size_cost = 0
    local area_slow_cost = 0
    local area_cooldown_cost = 0
    local area_exploding_cost = 0
    if attack.modifiers.area then area_cost = 50 else area_cost = 0 end
    if attack.modifiers.area then
        area_damage_cost = areas[attack.modifiers.area].damage*areas[attack.modifiers.area].damage
        if areas[attack.modifiers.area].r_f > 50 then
            area_size_cost = areas[attack.modifiers.area].r_f/2
        end
        if areas[attack.modifiers.area].slow then
            area_slow_cost = (1/areas[attack.modifiers.area].slow)*10
        end
        if areas[attack.modifiers.area].cooldown > 1 then area_cooldown_cost = -areas[attack.modifiers.area].cooldown*areas[attack.modifiers.area].cooldown*10
        elseif areas[attack.modifiers.area].cooldown < 1 then area_cooldown_cost = (1/areas[attack.modifiers.area].cooldown)*50
        else area_cooldown_cost = 0 end
        if areas[attack.modifiers.area].on_hit then area_exploding_cost = 250 end
    end
    total_cost = damage_cost + cooldown_cost + multiple_cost + pierce_cost + reflect_cost + back_cost + 
                 speed_cost + area_cost + (area_damage_cost or 0) + (area_size_cost or 0) + (area_slow_cost or 0) +
                 (area_cooldown_cost or 0) + (area_exploding_cost or 0)
    return round(total_cost, 2)
end

function love.keypressed(key)
    local keya = false

    if key ~= 'lctrl' and key ~= 'rctrl' then
        if love.keyboard.isDown('lctrl') or love.keyboard.isDown('rctrl') then
            if key == 'z' or key == 'Z' then
                local last_key = last_keys[1]
                if last_key then
                    print(last_key.key)
                    table.remove(last_keys, 1)
                    local cm = current_attack_table.modifiers
                    if last_key.key == 'd' or last_key.key == 'D' then cm.damage = cm.damage - 10 end
                    if last_key.key == 'c' or last_key.key == 'C' then cm.cooldown = cm.cooldown + 0.1 end
                    if last_key.key == 'n' or last_key.key == 'N' then cm.cooldown = cm.cooldown - 0.1 end
                    if last_key.key == 'm' or last_key.key == 'M' then cm.multiple = cm.multiple - 1 end
                    if last_key.key == 'p' or last_key.key == 'P' then cm.pierce = cm.pierce -1 end
                    if last_key.key == 'r' or last_key.key == 'R' then cm.reflect = cm.reflect -1 end
                    if last_key.key == 'b' or last_key.key == 'B' then cm.back = false end
                    if last_key.key == 'e' or last_key.key == 'E' then 
                        proj_speeds_pointer = proj_speeds_pointer - 1
                        cm.speed = proj_speeds[proj_speeds_pointer]
                    end
                    if last_key.key == 's' or last_key.key == 'S' then 
                        proj_speeds_pointer = proj_speeds_pointer + 1
                        cm.speed = proj_speeds[proj_speeds_pointer]
                    end
                    if not last_key.ctrl and (last_key.key == 'a' or last_key.key == 'A') then cm.area = false end
                    if not last_key.ctrl and (last_key.key == 'z' or last_key.key == 'Z') then 
                        area_sizes_pointer = area_sizes_pointer - 1
                        areas['main'].r_i = area_sizes[area_sizes_pointer]
                        areas['main'].r_f = area_sizes[area_sizes_pointer]
                    end
                    if last_key.key == 'g' or last_key.key == 'G' then areas['main'].damage = areas['main'].damage - 5 end
                    if last_key.key == 'l' or last_key.key == 'L' then 
                        area_slows_pointer = area_slows_pointer - 1
                        areas['main'].slow = area_slows[area_slows_pointer]
                    end
                    if last_key.key == 'w' or last_key.key == 'W' then areas['main'].cooldown = areas['main'].cooldown + 0.1 end
                    if last_key.key == 'o' or last_key.key == 'O' then areas['main'].cooldown = areas['main'].cooldown - 0.1 end
                    if last_key.key == 'x' or last_key.key == 'X' then
                        areas['main'].cooldown = 1 
                        areas['main'].on_hit = false
                        areas['main'].tween = false
                        areas['main'].duration = 0
                        areas['main'].r_i = areas['main'].r_f
                    end
                end
            end
        end
    end

    if key == 'q' then love.event.push('quit') end
    if key == 'u' then 
        if not game_over and not game_paused and not game_won then
            area_slows_pointer = 1
            area_sizes_pointer = 1
            proj_speeds_pointer = 3
            game_paused = true
            game_ui = true
            current_attack_table = Attack(attack('hold', 1, 0, 1, 0, 0, false, false, 200))
        end
    end
    if key == 'escape' then 
        if not game_over and not game_won then
            game_paused = not game_paused 
            game_ui = false
        end
    end
    if key == 'r' then
        if game_over then
            game_over = false
            reload()
            reloadb = true
        end

        if game_won then
            game_won = false
            reload()
            reloadb = true
        end
    end

    if love.keyboard.isDown('lctrl') or love.keyboard.isDown('rctrl') then
        if key == 'a' or key == 'A' then
            level.player.attack = current_attack_table
            game_ui = false
            game_paused = not game_paused
        end
    end

    if game_ui then
        if key == 'd' or key == 'D' then if current_attack_table.modifiers.damage < 100 then current_attack_table.modifiers.damage = current_attack_table.modifiers.damage + 10; keya = true end end
        if key == 'c' or key == 'C' then if current_attack_table.modifiers.cooldown >= 0.2 then current_attack_table.modifiers.cooldown = current_attack_table.modifiers.cooldown - 0.1; keya = true end end
        if key == 'n' or key == 'N' then if current_attack_table.modifiers.cooldown <= 3 then current_attack_table.modifiers.cooldown = current_attack_table.modifiers.cooldown + 0.1; keya = true end end
        if key == 'm' or key == 'M' then if current_attack_table.modifiers.multiple < 8 then current_attack_table.modifiers.multiple = current_attack_table.modifiers.multiple + 1; keya = true end end
        if key == 'p' or key == 'P' then if current_attack_table.modifiers.pierce < 8 then current_attack_table.modifiers.pierce = current_attack_table.modifiers.pierce + 1; keya = true end end
        if key == 'r' or key == 'R' then if current_attack_table.modifiers.reflect < 8 then current_attack_table.modifiers.reflect = current_attack_table.modifiers.reflect + 1; keya = true end end
        if key == 'b' or key == 'B' then if not current_attack_table.modifiers.back then current_attack_table.modifiers.back = true; keya = true end end
        if key == 'e' or key == 'E' then
            if proj_speeds_pointer < #proj_speeds then
                proj_speeds_pointer = proj_speeds_pointer + 1
                keya = true
            end
            current_attack_table.modifiers.speed = proj_speeds[proj_speeds_pointer]
        end
        if key == 's' or key == 'S' then
            if proj_speeds_pointer > 1 then
                proj_speeds_pointer = proj_speeds_pointer - 1
                keya = true
            end
            current_attack_table.modifiers.speed = proj_speeds[proj_speeds_pointer]
        end

        if not love.keyboard.isDown('lctrl') and not love.keyboard.isDown('rctrl') then
            if key == 'a' or key == 'A' then 
                if not current_attack_table.modifiers.area then
                    keya = true
                    areas['main'] = area(48, 48, 0, false, false, 1, 0, false)
                    current_attack_table.modifiers.area = 'main' 
                end
            end
        end

        if current_attack_table.modifiers.area then
            if not love.keyboard.isDown('lctrl') and not love.keyboard.isDown('rctrl') then
                if key == 'z' or key == 'Z' then
                    if area_sizes_pointer < #area_sizes then
                        keya = true
                        area_sizes_pointer = area_sizes_pointer + 1
                    end
                    areas['main'].r_i = area_sizes[area_sizes_pointer]
                    areas['main'].r_f = area_sizes[area_sizes_pointer]
                end
            end
            if key == 'g' or key == 'G' then
                if areas['main'].damage < 50 then 
                    keya = true
                    areas['main'].damage = areas['main'].damage + 5
                end
            end
            if key == 'l' or key == 'L' then
                if area_slows_pointer < #area_slows then
                    keya = true
                    area_slows_pointer = area_slows_pointer + 1
                end
                areas['main'].slow = area_slows[area_slows_pointer]
            end
            if key == 'w' or key == 'W' then
                if areas['main'].cooldown >= 0.6 then 
                    keya = true
                    areas['main'].cooldown = areas['main'].cooldown - 0.1
                end
            end
            if key == 'o' or key == 'O' then
                if areas['main'].cooldown <= 2 then
                    keya = true
                    areas['main'].cooldown = areas['main'].cooldown + 0.1
                end
            end
            if key == 'x' or key == 'X' then 
                if not areas['main'].on_hit then
                    keya = true
                    areas['main'].cooldown = 0.1
                    areas['main'].on_hit = true
                    areas['main'].tween = 'inOutCubic'
                    areas['main'].duration = 1
                    areas['main'].r_i = 0
                end
            end
        end

        total_cost = calculateTotalCost(current_attack_table)
    end

    if game_ui then
        if key ~= 'lctrl' and key ~= 'rctrl' and key ~= 'u' then
            if not (love.keyboard.isDown('lctrl') or love.keyboard.isDown('rctrl')) then
                if keya then
                    local last_key = {key = key, ctrl = love.keyboard.isDown('lctrl') or love.keyboard.isDown('rctrl')}
                    table.insert(last_keys, 1, last_key)
                end
            end
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
