Graph = {}
Graph.__index = Graph

function Graph.new()
    return setmetatable({adjacency_list = {}, nodes = {}, edges = {}, floyd_dists = {}}, Graph)
end

function Graph:__tostring()
    local str = "----\nAdjacency List: \n"
    for node, list in pairs(self.adjacency_list) do
        str = str .. node .. " ->   "
        for _, adj in ipairs(list) do
            str = str .. adj .. ", "
        end
        str = string.sub(str, 0, -3)
        str = str .. "\n"
    end
    str = str .. "\nNodes: \n"
    for _, node in ipairs(self.nodes) do
        str = str .. node .. "\n"
    end
    str = str .. "\nEdges: \n"
    for _, edge in ipairs(self.edges) do
        str = str .. edge[1] .. ", " .. edge[2]
        str = str .. "\n"
    end
    str = str .. "\nFloyd Warshall Distances: \n"
    for node, _ in pairs(self.floyd_dists) do
        for _node, _ in pairs(self.floyd_dists[node]) do
            str = str .. "(" .. node .. ", " .. _node .. ") = " .. self.floyd_dists[node][_node]
            str = str .. "\n"
        end
    end
    str = str .. "----\n"
    return str
end

function Graph:getNode(node)
    if self.adjacency_list[node] then
        return self.adjacency_list[node]
    end
end

function Graph:findNodes()
    self.nodes = {}
    for node, _ in pairs(self.adjacency_list) do
        table.insert(self.nodes, node)
    end
end

function Graph:addNode(node)
    if node then
        if not self.adjacency_list[node] then
            self.adjacency_list[node] = {}
        end
    end
end

function Graph:removeNode(node)
    if node then
        if self.adjacency_list[node] then
            for _node, list in pairs(self.adjacency_list) do
                self:removeEdge(node, _node)
            end
            self.adjacency_list[node] = nil
        end
    end
end

function Graph:getEdge(node1, node2)
    if self.adjacencey_list[node1] and self.adjacency_list[node2] then
        for _, node in ipairs(self.adjacency_list[node1]) do
            if node == node2 then return true end
        end
        return false
    end
end

local function containsEdge(table, edge)
    for _, v in ipairs(table) do
        if (v[1] == edge[1] and v[2] == edge[2]) or (v[1] == edge[2] and v[2] == edge[1]) then
            return true
        end
    end
    return false
end

function Graph:findEdges()
    self.edges = {}
    for node, list in pairs(self.adjacency_list) do
        for _, _node in ipairs(list) do
            if not containsEdge(self.edges, {node, _node}) then
                table.insert(self.edges, {node, _node})
            end
        end
    end
end

local function containsNode(table, node)
    for _, v in ipairs(table) do
        if v == node then return true end
    end
    return false
end

function Graph:addEdge(node1, node2)
    if node1 and node2 then
        if self.adjacency_list[node1] and self.adjacency_list[node2] then
            if not containsNode(self.adjacency_list[node1], node2) and
               not containsNode(self.adjacency_list[node2], node1) then 
                table.insert(self.adjacency_list[node1], node2)
                table.insert(self.adjacency_list[node2], node1)
            end
        end
    end
end

function Graph:removeEdge(node1, node2)
    if node1 and node2 then
        if self.adjacency_list[node1] and self.adjacency_list[node2] then
            for i, node in ipairs(self.adjacency_list[node1]) do
                if node == node2 then 
                    table.remove(self.adjacency_list[node1], i) 
                    break
                end
            end
            for i, node in ipairs(self.adjacency_list[node2]) do
                if node == node1 then
                    table.remove(self.adjacency_list[node2], i) 
                    break
                end
            end
        end
    end
end

-- Comments follow pseudocode from http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm.
function Graph:floydWarshall()
    self:findNodes()
    self:findEdges()
    -- initialize multidimensional to be array
    for _, node in ipairs(self.nodes) do
        self.floyd_dists[node] = {}
    end
    -- let floyd_dist be a |V|x|V| array of minimun distance initialized to infinity
    for _, node in ipairs(self.nodes) do
        for _, _node in ipairs(self.nodes) do
            self.floyd_dists[node][_node] = 10000 -- 10000 is big enough for an unweighted graph
            self.floyd_dists[_node][node] = 10000
        end
    end
    -- set dist[v][v] to 0
    for _, node in ipairs(self.nodes) do
        self.floyd_dists[node][node] = 0
    end
    -- set dist[u][v] to w(u, v) which is always 1 in the case of an unweighted graph
    for _, edge in ipairs(self.edges) do
        self.floyd_dists[edge[1]][edge[2]] = 1
        self.floyd_dists[edge[2]][edge[1]] = 1
    end
    -- main triple loop
    for _, nodek in ipairs(self.nodes) do
        for _, nodei in ipairs(self.nodes) do
            for _, nodej in ipairs(self.nodes) do
                if self.floyd_dists[nodei][nodek] + self.floyd_dists[nodek][nodej] < self.floyd_dists[nodei][nodej] then
                    self.floyd_dists[nodei][nodej] = self.floyd_dists[nodei][nodek] + self.floyd_dists[nodek][nodej]
                end
            end
        end
    end
end

setmetatable(Graph, {__call = function() return Graph.new() end})
