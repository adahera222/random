struct = require 'struct'

math.randomseed(os.time())
math.random(); math.random(); math.random();

function love.load()
    Point = struct('x', 'y')
    Rectangle = struct('x', 'y', 'w', 'h')
    cells = generateCells(2, 10)
end

function love.update(dt)
    
end

function love.draw()
    for _, cell in ipairs(cells) do
        love.graphics.rectangle('line', cell.x+400, cell.y+300, cell.w, cell.h)
    end
end

function generateCells(n, r)
    local cells = {}
    for i = 1, n do
        local cell = Rectangle(math.random(-r, r), math.random(-r, r), math.random(18, 56), math.random(18, 56))
        table.insert(cells, cell)
    end
    return cells
end

function colliding(c, cell)
    local lu, ld, ru, rd = Point(c.x-c.w, c.y-c.h), Point(c.x-c.w, c.y+c.h), Point(c.x+c.w, c.y-c.h), Point(c.x+c.w, c.y+c.h)
    local corners = {lu, ld, ru, rd}
    for _, corner in ipairs(corners) do
        if corner.x >= cell.x-cell.w and corner.x <= cell.w+cell.w and corner.y >= cell.y-cell.h and corner.y <= cell.y+cell.h then
            return true, corner.x-cell.x, corner.y-cell.y
        end
    end
    return false
end

function isOverlapping(cell, cells)
    for _, c in ipairs(cells) do
        local col, dx, dy = colliding(c, cell)
        if col then return col, dx, dy end
    end
    return false
end

function separateCells(cells)
    for _, c in ipairs(cells) do
        local col, dx, dy = isOverlapping(c, cells) 
    end
    return cells
end
