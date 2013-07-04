require 'Dungeon'

function love.load()
    dungeon = Dungeon(10, 10, {0.25, 0.35, 0.4}, {'red', 'blue', 'green'}, {{1, 2, 3}, {0.7, 0.2, 0.1}}, {1, 0, 0, 0})
    dungeon:generateDungeon()
end

function love.update(dt)
    
end

function love.draw()
    dungeon:draw()
end
