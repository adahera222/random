struct = require 'struct'
require 'Graph'
require 'Dungeon'

math.randomseed(os.time())
math.random(); math.random(); math.random();

function love.load()
    dungeon = Dungeon(3, 3)
    dungeon:generateGraph()
    print(dungeon.graph)
end

function love.update(dt)
    
end

function love.draw()

end
