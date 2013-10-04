Timer = require 'hump.timer'

function love.load()
    love.graphics.setDefaultImageFilter('nearest', 'nearest')
    main_timer = Timer.new()
    mineral = love.graphics.newImage('mineral.png')

    color = {255, 255, 255, 255}
end

function love.update(dt)
    main_timer:update(dt)
    print(collectgarbage("count")*1024)
end

function love.draw()
    love.graphics.setColor(unpack(color))
    love.graphics.draw(mineral, 400-64, 300-64, 0, 4, 4) 
end

function pulseTween(tweened_table, duration1, target1, method1, duration2, target2, method2)
    return main_timer:addPeriodic(duration1+duration2, function()
        main_timer:tween(duration1, tweened_table, target1, method1)
        main_timer:add(duration1, function() main_timer:tween(duration2, tweened_table, target2, method2) end)
    end)
end

function love.keypressed(key)
    if key == 'c' then
        main_timer:cancel(id1)
    end
    if key == 'b' then
        collectgarbage()
    end
    if key == 't' then
        id1 = pulseTween(color, 1, {0, 0, 0, 0}, 'linear', 1, {255, 255, 255, 255}, 'linear')
    end
end
