
function love.load()
    world = love.physics.newWorld(0, 100, true)    
    entities = {}
    table.insert(entities, createRectangle('static', 400, 550, 800, 100))
    for i = 1, 10 do
        table.insert(entities, createCircle('dynamic', math.random(200, 400), 
        math.random(100, 200), math.random(10, 50)))
    end
    table.insert(entities, createLine('static', 100, 400, 700, 400))
    table.insert(entities, createChain('static', 0, 0, 100, 300, 200, 300, 400, 200))
end

function love.update(dt)
    world:update(dt)  
end

function love.draw()
    for _, e in ipairs(entities) do
        local type = e.shape:type()

        if type == 'EdgeShape' then
            love.graphics.line(e.body:getWorldPoints(e.shape:getPoints()))

        elseif type == 'PolygonShape' then 
            love.graphics.polygon('line', e.body:getWorldPoints(e.shape:getPoints())) 
        
        elseif type == 'CircleShape' then
            local x, y = e.body:getWorldCenter()
            love.graphics.circle('line', x, y, e.shape:getRadius())

        elseif type == 'ChainShape' then
            local points = {e.shape:getPoints()}
            for i = 1, #points, 2 do
                love.graphics.line(points[i], points[i+1], points[i+2], points[i+3])
            end
        end
    end
end

function createLine(type, x1, y1, x2, y2)
    local body = love.physics.newBody(world, 0, 0, type or 'dynamic')
    local shape = love.physics.newEdgeShape(x1, y1, x2, y2)
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end

function createChain(type, ...)
    local body = love.physics.newBody(world, 0, 0, type or 'dynamic')
    local shape = love.physics.newChainShape(false, unpack({...}))
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end

function createRectangle(type, x, y, w, h)
    local body = love.physics.newBody(world, x, y, type or 'dynamic')
    local shape = love.physics.newRectangleShape(w, h) 
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end

function createCircle(type, x, y, r)
    local body = love.physics.newBody(world, x, y, type or 'dynamic')
    local shape = love.physics.newCircleShape(r)
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end
