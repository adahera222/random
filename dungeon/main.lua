require 'Dungeon'

function love.load()
    -- width = 25, height = 16
    -- 25% rooms = red, 35% = blue, 40% = green
    -- red, blue and green rooms get added around the path
    -- sizes for room width/height 1 -> 70% prob, 2 -> 20%, 3 -> 10%
    -- desired connections per room -> 100% -> 1 connection, 0% -> 2 connections, 0% -> 3 connections, 0% -> 4 connections
    dungeon1 = Dungeon(22, 16, {0.25, 0.35, 0.4}, {'red', 'blue', 'green'}, {{1, 2, 3}, {0.7, 0.2, 0.1}}, {1, 0, 0, 0})
end

function love.update(dt)
    
end

function love.draw()
    dungeon1:draw()
end
