struct = require 'struct'
require 'Graph'
require 'Dungeon'

math.randomseed(os.time())
math.random(); math.random(); math.random();

function love.load()
    graph = Graph()
    graph:addNode('1')
    graph:addNode('2')
    graph:addNode('3')
    graph:addNode('4')
    graph:addNode('5')
    graph:addNode('6')
    graph:addNode('7')
    graph:addEdge('1', '3')
    graph:addEdge('2', '3')
    graph:addEdge('3', '4')
    graph:addEdge('3', '6')
    graph:addEdge('4', '5')
    graph:addEdge('6', '7')
    graph:addEdge('5', '7')
    graph:floydWarshall()
    print(graph)

    dungeon = Dungeon(16, 16)
    dungeon:initializeGrid()
    print(dungeon)
end

function love.update(dt)
    
end

function love.draw()

end
