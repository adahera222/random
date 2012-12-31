require 'chrono'

function love.load()
    print(love.timer.getMicroTime())
    chrono = Chrono()
    id = chrono:every(0.5, 2, f):after(10, f):do_for(4, f)
    -- interleave leftttt
    print(id.id)
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
