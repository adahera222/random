require 'Graph'

Dungeon = {}
Dungeon.__index = Dungeon

function Dungeon.new(w, h)
    return setmetatable({w = w or 1, h = h or 1, grid = {}, graph = Graph()}, Dungeon)
end

function Dungeon:__tostring()
    local str = "----\n"
    for i = 1, self.h do
        str = str .. "[ "
        for j = 1, self.w do
            str = str .. self.grid[i][j] .. ", \t"
        end
        str = string.sub(str, 0, -3)
        str = str .. " ]\n"
    end
    str = str .. "----\n"
    return str
end

function Dungeon:initializeGrid()
    self.grid = {}
    local k = 1
    for i = 1, self.h do
        self.grid[i] = {}
        for j = 1, self.w do
            self.grid[i][j] = k
            k = k + 1
        end
    end
end

function Dungeon:generateGraph()
    local getGridXY = function(x, y)
        if self.grid[y] then
            if self.grid[y][x] then
                return self.grid[y][x]
            end
        end
    end
    self:initializeGrid()
    for i = 1, self.h do
        for j = 1, self.w do
            local current = getGridXY(j, i)
            local left = getGridXY(j-1, i)
            local right = getGridXY(j+1, i)
            local up = getGridXY(j, i-1)
            local down = getGridXY(j, i+1)
            self.graph:addNode(current)
            self.graph:addNode(left)
            self.graph:addNode(right)
            self.graph:addNode(up)
            self.graph:addNode(down)
            self.graph:addEdge(current, left)
            self.graph:addEdge(current, right)
            self.graph:addEdge(current, up)
            self.graph:addEdge(current, down)
        end
    end
    self.graph:floydWarshall()
end

setmetatable(Dungeon, {__call = function(_, ...) return Dungeon.new(...) end})
