struct = require 'struct'
tween = require 'tween'
require 'chrono'

function love.load()
    chrono = Chrono()
    love.graphics.setDefaultImageFilter('nearest', 'nearest')
    belt = love.graphics.newImage('belt.png')
    book = love.graphics.newImage('book.png')
    crystal_ball = love.graphics.newImage('crystal_ball.png')
    fire_frame = love.graphics.newImage('fire_frame.png')
    gem = love.graphics.newImage('gem.png')
    letter = love.graphics.newImage('letter.png')
    lightning_frame = love.graphics.newImage('lightning_frame.png')
    meat = love.graphics.newImage('meat.png')
    mineral = love.graphics.newImage('mineral.png')
    treasure_map = love.graphics.newImage('treasure_map.png')
    water_frame = love.graphics.newImage('water_frame.png')
    water_pipe_valve = love.graphics.newImage('water_pipe_valve.png')
    item_info = struct('x', 'y', 'c')
    item_list = {meat, book, treasure_map, gem, fire_frame, letter, lightning_frame, belt, mineral, crystal_ball, water_frame, water_pipe_valve} 
    ti = 0.33
    br = 2*math.pi/#item_list
    r = 128
    cc = 92
    item_info_list = {}
    for i = 1, #item_list do
        if i == #item_list then
            item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, 255)
        else
            item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, cc)
        end
    end
    can_turn = true
end

function love.update(dt)
    tween.update(dt)
    chrono:update(dt)
end

function love.draw()
    for i, item in ipairs(item_list) do
        love.graphics.setColor(item_info_list[i].c, item_info_list[i].c, item_info_list[i].c, item_info_list[i].c)
        love.graphics.draw(item, item_info_list[i].x, item_info_list[i].y, 0, 2, 2)
        love.graphics.setColor(255, 255, 255, 255)
    end
end

function table.shiftRight(t)
    local last = t[#t]
    for i = #t-1, 1, -1 do t[i+1] = t[i] end
    t[1] = last
end

function table.shiftLeft(t)
    local head = t[1]
    for i = 2, #t do t[i-1] = t[i] end
    t[#t] = head
end

function love.keypressed(key)
    if not can_turn then return end
    can_turn = false
    chrono:after(ti, function() can_turn = true end)

    if key == 'right' then 
        for i, item_info in ipairs(item_info_list) do
            tween(ti, item_info, {x = 400+r*math.cos((i+1)*br)-32}, 'inOutCubic')
            tween(ti, item_info, {y = 300+r*math.sin((i+1)*br)-32}, 'inOutCubic')
            if i ~= #item_list-1 then
                tween(ti, item_info, {c = cc}, 'inOutCubic')
            else
                tween(ti, item_info, {c = 255}, 'inOutCubic')
            end
        end
        chrono:after(ti, function() 
            table.shiftRight(item_list)
            item_info_list = {}
            for i = 1, #item_list do
                if i ~= #item_list then
                    item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, cc)
                else
                    item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, 255)
                end
            end
        end)
    end
    if key == 'left' then 
        for i, item_info in ipairs(item_info_list) do
            tween(ti, item_info, {x = 400+r*math.cos((i-1)*br)-32}, 'inOutCubic')
            tween(ti, item_info, {y = 300+r*math.sin((i-1)*br)-32}, 'inOutCubic')
            if i ~= 1 then
                tween(ti, item_info, {c = cc}, 'inOutCubic')
            else
                tween(ti, item_info, {c = 255}, 'inOutCubic')
            end
        end
        chrono:after(ti, function() 
            table.shiftLeft(item_list) 
            item_info_list = {}
            for i = 1, #item_list do
                if i ~= #item_list then
                    item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, cc)
                else
                    item_info_list[i] = item_info(400+r*math.cos(i*br)-32, 300+r*math.sin(i*br)-32, 255)
                end
            end
        end)
    end
end
