struct = require 'struct'
require 'Graph'

math.randomseed(os.time())
math.random(); math.random(); math.random();

function love.load()
    graph = Graph()
    graph:findNodes()
    graph:findEdges()
    graph:floydWarshall()
    print(graph)
end

function love.update(dt)
    
end

function love.draw()

end
