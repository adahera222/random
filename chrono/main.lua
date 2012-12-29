require 'chrono'

function love.load()
    chrono = Chrono()
    id1 = chrono:after(2, function() print(1) end)
end

function love.update(dt)
    chrono:update(dt)
end

function love.draw()
    
end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == 'r' then chrono:remove(id1) end
end
