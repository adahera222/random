require 'middleclass/middleclass'
require 'B2Entity'

function love.load()
    world = love.physics.newWorld(0, 100, true)    
    entities = {}
    table.insert(entities, createRectangle(400, 550, 800, 100, 'static'))
    for i = 1, 10 do
        table.insert(entities, createCircle(math.random(200, 400), 
        math.random(100, 200), math.random(10, 50)))
    end
    table.insert(entities, createLine(100, 400, 700, 400, 'static'))
    
    e = B2Entity('dynamic', 'circle')
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
        end
    end
end

function createLine(x1, y1, x2, y2, type)
    local body = love.physics.newBody(world, 0, 0, type or 'dynamic')
    local shape = love.physics.newEdgeShape(x1, y1, x2, y2)
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end

function createRectangle(x, y, w, h, type)
    local body = love.physics.newBody(world, x, y, type or 'dynamic')
    local shape = love.physics.newRectangleShape(w, h) 
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end

function createCircle(x, y, r, type)
    local body = love.physics.newBody(world, x, y, type or 'dynamic')
    local shape = love.physics.newCircleShape(r)
    local fixture = love.physics.newFixture(body, shape, 1)
    return {body = body, shape = shape, fixture = fixture}
end
