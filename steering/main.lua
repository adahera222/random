require 'Entity'

function love.load()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)

    seeker1 = Entity(20, 20, Vector(400, 300), Vector(0, 0), 1, 100, 50)
end

function love.update(dt)
    x, y = love.mouse.getPosition()

    seeker1:update(dt, Vector(x, y))
end

function love.draw()

    -- Draw mouse position
    love.graphics.setColor(0, 0, 0)
    love.graphics.circle('fill', x, y, 10, 360)

    seeker1:draw()
end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
end
