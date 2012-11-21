require 'Entity'

function love.load()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)
    font = love.graphics.newFont('visitor1.ttf', 24)
    love.graphics.setFont(font)

    gArrivalRadius = 200
    gFleeRadius = 100
    slowing = false
    current = {
        behavior = 'seek',
        radius = 200
    }
    entity = Entity(20, 20, Vector(400, 300), Vector(0, 0), 1, 150, 100)
end

function love.update(dt)
    x, y = love.mouse.getPosition()
    entity:update(dt, Vector(x, y))
end

function love.draw()
    entity:draw()

    -- Draw mouse position
    love.graphics.setColor(0, 0, 0)
    love.graphics.circle('fill', x, y, 10, 360)

    if current.behavior == 'arrival' or current.behavior == 'flee' then
        -- Draw slowing radius
        if slowing then love.graphics.setColor(255, 0, 0)
        else love.graphics.setColor(0, 0, 0) end
        love.graphics.circle('line', x, y, current.radius, 360)
    end

    love.graphics.setColor(0, 0, 0)
    love.graphics.print(current.behavior, 10, 10)
end
    
function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
    if key == '1' then current.behavior = 'seek' end
    if key == '2' then current.behavior = 'flee' ;current.radius = gFleeRadius end
    if key == '3' then current.behavior = 'arrival'; current.radius = gArrivalRadius end
end
