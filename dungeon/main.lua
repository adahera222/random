struct = require 'struct'
require 'Graph'
require 'Dungeon'

math.randomseed(os.time())
math.random(); math.random(); math.random();

function love.load()
    dungeon = Dungeon(6, 6)
    dungeon:generateGrid()
    print(dungeon)
end

function love.update(dt)
    
end

function love.draw()

end
