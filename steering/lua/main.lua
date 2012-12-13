require 'Entity'

function love.load()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)
    font = love.graphics.newFont('visitor1.ttf', 24)
    love.graphics.setFont(font)
    debug_draw = true

    w = love.graphics.getWidth()
    h = love.graphics.getHeight()

    gFleeRadius = 200 -- flee
    gArrivalRadius = 200 -- arrival
    slowing = false -- flee, arrival
    nAvoidanceObstacles = 10 -- avoidance

    entity = Entity(20, 20, Vector(400, 300), Vector(0, 0), 1, 150, 100, 
                    gFleeRadius, gArrivalRadius) 

    pursue_evade_entity = Entity(10, 10, Vector(500, 400), Vector(0, 0), 1, 
                                 300, 200, gFleeRadius, gArrivalRadius)

    avoidance_obstacles = {}
    for i = 1, nAvoidanceObstacles do
        table.insert(avoidance_obstacles, {
            x = math.random(50, w-50),
            y = math.random(50, h-50),
            r = math.random(20, 100)
        })
    end

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
    
    elseif current.behavior == 'avoidance' then

    end
end

function love.draw()
    entity:draw()

    if equalsAny(current.behavior, 'pursue', 'evade') then 
        pursue_evade_entity:draw() 
    end

    if current.behavior == 'avoidance' then
        for _, obstacle in ipairs(avoidance_obstacles) do
            love.graphics.setColor(0, 0, 0)
            love.graphics.circle('line', obstacle.x, obstacle.y, 
                                 obstacle.r, 360)
        end
    end

    -- Draw mouse position
    love.graphics.setColor(0, 0, 0)
    love.graphics.circle('line', x, y, 5, 360)

    -- Print current behavior
    love.graphics.setColor(0, 0, 0)
    love.graphics.print(current.behavior, 10, 10)
end
    
function love.keypressed(key)
    if key == 'd' then debug_draw = not debug_draw end
    if key == 'q' then love.event.push('quit') end
    if key == '1' then current.behavior = 'seek' end
    if key == '2' then current.behavior = 'flee'; current.radius = gFleeRadius end
    if key == '3' then current.behavior = 'arrival'; current.radius = gArrivalRadius end
    if key == '4' then current.behavior = 'pursue'; current.target_entity = entity end
    if key == '5' then current.behavior = 'evade'; current.target_entity = entity end
    if key == '6' then current.behavior = 'avoidance'; setBehavior('avoidance') end
end

function setBehavior(behavior)
    if behavior == 'avoidance' then

    end
end
