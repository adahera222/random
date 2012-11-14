require 'Entity'

function love.load()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)

    seeker1 = Entity:new(20, 20, Vector(400, 300), Vector(0, 0), 1, 100, 200)
    arrivalSlowingRadius = 200
    slowing = false
    current_behavior = 'seek'
    font = love.graphics.newFont('visitor1.ttf', 36)
    love.graphics.setFont(font)
end

function love.update(dt)
    x, y = love.mouse.getPosition()

    seeker1:update(dt, Vector(x, y))
end

function love.draw()
    seeker1:draw()

    if current_behavior == 'seek' or
       current_behavior == 'flee' or
       current_behavior == 'arrival' then
        -- Draw mouse position
        love.graphics.setColor(0, 0, 0)
        love.graphics.circle('fill', x, y, 10, 360)
    end

    if current_behavior == 'arrival' then
        -- Draw slowing radius
        if slowing then love.graphics.setColor(255, 0, 0)
        else love.graphics.setColor(0, 0, 0) end
        love.graphics.circle('line', x, y, arrivalSlowingRadius, 360)
    end

    love.graphics.setColor(0, 0, 0)
    love.graphics.print(current_behavior, 10, 10)
end
    
function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == '1' then current_behavior = 'seek' end
    if key == '2' then current_behavior = 'flee' end
    if key == '3' then current_behavior = 'arrival' end
end
