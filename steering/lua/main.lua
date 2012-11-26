require 'Entity'

function love.load()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)
    font = love.graphics.newFont('visitor1.ttf', 24)
    love.graphics.setFont(font)

    gArrivalRadius = 200
    gFleeRadius = 100
    slowing = false

    entity = Entity(20, 20, Vector(400, 300), Vector(0, 0), 1, 150, 100, gFleeRadius, gArrivalRadius)
    pursue_evade_entity = Entity(10, 10, Vector(500, 400), Vector(0, 0), 1, 150, 100, gFleeRadius, gArrivalRadius)

    -- Global behavior settings
    current = {
        behavior = 'seek',
        radius = 200,
        target_entity = nil
    }
end

function love.update(dt)
    x, y = love.mouse.getPosition()

    if equalsAny(current.behavior, 'seek', 'flee', 'arrival') then
        entity.behavior = current.behavior
        entity.seek_flee_arrival_target = Vector(x, y)
        entity:update(dt) 

    elseif equalsAny(current.behavior, 'pursue', 'evade') then
        entity.behavior = 'seek'
        entity.seek_flee_arrival_target = Vector(x, y) 
        entity:update(dt)
        pursue_evade_entity.behavior = current.behavior
        pursue_evade_entity.pursue_evade_entity = current.target_entity 
        pursue_evade_entity:update(dt)
    end
end

function love.draw()
    entity:draw()

    if equalsAny(current.behavior, 'pursue', 'evade') then
        pursue_evade_entity:draw()
    end

    -- Draw mouse position
    love.graphics.setColor(0, 0, 0)
    love.graphics.circle('line', x, y, 5, 360)

    if equalsAny(current.behavior, 'flee', 'arrival') then
        -- Draw slowing radius for arrival or flee
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
    if key == '2' then current.behavior = 'flee'; current.radius = gFleeRadius end
    if key == '3' then current.behavior = 'arrival'; current.radius = gArrivalRadius end
    if key == '4' then current.behavior = 'pursue'; current.target_entity = entity end
end
