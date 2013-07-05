local struct = require 'struct'
local GridNode = struct('id', 'w', 'h', 'color', 'in_path_original', 'in_path_additional', 'joined', 'original', 'ff_color')
local node_w, node_h = 32, 32

Dungeon = {}
Dungeon.__index = Dungeon

function Dungeon.new(w, h, n_colors, add_path, room_sizes, desired_con)
    return setmetatable({w = w or 1, h = h or 1, n_colors = n_colors,
                        red_neighbor = true, add_path = add_path, room_sizes = room_sizes, desired_con = desired_con,
                        grid = {}, connections_grid = {}, connections_room = {}, ff_buckets = {}}, Dungeon)
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

function Dungeon:generateDungeon()
    self:initializeGrid() 
    self:colorNodes()
    self:pathFind()
    self:randomizeRoomSizes()
    self:generateConnections()
    self:disconnect()
    self:reconnect()
end

function Dungeon:initializeGrid()
    self.grid = {}
    local k = 1
    for i = 1, self.h do
        self.grid[i] = {}
        for j = 1, self.w do
            self.grid[i][j] = GridNode(k, node_w, node_h)
            k = k + 1
        end
    end
end

function Dungeon:getGridXY(x, y)
    if self.grid[y] then
        if self.grid[y][x] then
            return self.grid[y][x]
        end
    end
end

function Dungeon:getNeighbors(x, y)
    return self:getGridXY(x-1, y), self:getGridXY(x, y-1), self:getGridXY(x+1, y), self:getGridXY(x, y+1)
end

function Dungeon:getNeighborsById(id)
    local id_positions = {}
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].id == id then table.insert(id_positions, {x = j, y = i}) end
        end
    end
    local contains = function(table, value)
        for _, v in ipairs(table) do
            if v == value then return true end
        end
        return false
    end
    local neighbors_id = {}
    for _, p in ipairs(id_positions) do
        local left, right, up, down = self:getNeighbors(p.x, p.y)
        if left then if left.id ~= id then if not contains(neighbors_id, left.id) then table.insert(neighbors_id, left.id) end end end
        if right then if right.id ~= id then if not contains(neighbors_id, right.id) then table.insert(neighbors_id, right.id) end end end
        if up then if up.id ~= id then if not contains(neighbors_id, up.id) then table.insert(neighbors_id, up.id) end end end
        if down then if down.id ~= id then if not contains(neighbors_id, down.id) then table.insert(neighbors_id, down.id) end end end
    end
    return neighbors_id
end

function Dungeon:colorNodes()
    local total_rooms = self.w*self.h
    if self.n_colors[1] + self.n_colors[2] + self.n_colors[3] ~= 1 then
        self.n_colors[1] = 0.25
        self.n_colors[2] = 0.35
        self.n_colors[3] = 0.4
    end
    local n_red_rooms = math.floor(total_rooms*self.n_colors[1])
    local n_blue_rooms = math.ceil(total_rooms*self.n_colors[2])
    local n_green_rooms = math.floor(total_rooms*self.n_colors[3])
    local colored_rooms = {}

    local isRoomColored = function(x, y)
        for _, room in ipairs(colored_rooms) do
            if x == room.x and y == room.y then return true end
        end
        return false
    end

    -- Returns true if more than n neighbors of x, y are colored with color, false otherwise
    local areNeighborsColored = function(x, y, color, n)
        local n_colored = 0
        local left, up, right, down = self:getNeighbors(x, y)
        local isNodeColored = function(node)
            if node then
                if node.color == color then n_colored = n_colored + 1 end
            end
        end
        isNodeColored(left)
        isNodeColored(right)
        isNodeColored(up)
        isNodeColored(down)
        if n_colored > n then return true 
        else return false end
    end

    -- Colors n_red_rooms red such that no red room has another red room as neighbor (preferably)
    local red_rooms = 0
    local red_tolerance = 0
    while red_rooms < n_red_rooms do
        local x, y = math.random(1, self.w), math.random(1, self.h) 
        if self.red_neighbor then
            if not isRoomColored(x, y) and not areNeighborsColored(x, y, 'red', 0) then
                self.grid[y][x].color = 'red'
                table.insert(colored_rooms, {x = x, y = y})
                red_rooms = red_rooms + 1
                red_tolerance = 0
            end
            red_tolerance = red_tolerance + 1
            if red_tolerance > 1000 then self.red_neighbor = false end
        else 
            self.grid[y][x].color = 'red'
            table.insert(colored_rooms, {x = x, y = y})
            red_rooms = red_rooms + 1
        end
    end

    -- Colors rooms around red rooms as blue and green (when possible)
    local blue_rooms, green_rooms = 0, 0
    local to_be_colored_rooms = {}
    for _, room in ipairs(colored_rooms) do
        local x, y = room.x, room.y
        local blue = areNeighborsColored(x, y, 'blue', 0)
        local green = areNeighborsColored(x, y, 'green', 0)
        -- Get uncolored neighbors
        local uncolored_neighbors = {}
        local left, up, right, down = self:getNeighbors(x, y)
        local isNodeNotColored = function(node) if node then if not node.color then return true end end end
        if isNodeNotColored(left) then table.insert(uncolored_neighbors, {x = x-1, y = y}) end
        if isNodeNotColored(right) then table.insert(uncolored_neighbors, {x = x+1, y = y}) end
        if isNodeNotColored(up) then table.insert(uncolored_neighbors, {x = x, y = y-1}) end
        if isNodeNotColored(down) then table.insert(uncolored_neighbors, {x = x, y = y+1}) end
        -- Colors one uncolored neighbor blue if x, y doesn't have other blue neighbors
        if not blue then 
            if #uncolored_neighbors > 0 then
                local room_ = table.remove(uncolored_neighbors, math.random(1, #uncolored_neighbors))
                if room_ then
                    local x_, y_ = room_.x, room_.y
                    self.grid[y_][x_].color = 'blue'
                    table.insert(to_be_colored_rooms, {x = x_, y = y_})
                    blue_rooms = blue_rooms + 1
                end
            end
        end
        -- Colors one uncolored neighbor green if x, y doesn't have other green neighbors
        if not green then
            if #uncolored_neighbors > 0 then
                local room_ = table.remove(uncolored_neighbors, math.random(1, #uncolored_neighbors))
                if room_ then
                    local x_, y_ = room_.x, room_.y
                    self.grid[y_][x_].color = 'green'
                    table.insert(to_be_colored_rooms, {x = x_, y = y_})
                    green_rooms = green_rooms + 1
                end
            end
        end
    end
    for _, room in ipairs(to_be_colored_rooms) do table.insert(colored_rooms, room) end
    
    -- Colors left over blue rooms randomly
    while blue_rooms < n_blue_rooms do
        local x, y = math.random(1, self.w), math.random(1, self.h) 
        if not isRoomColored(x, y) then
            self.grid[y][x].color = 'blue'
            table.insert(colored_rooms, {x = x, y = y})
            blue_rooms = blue_rooms + 1
        end
    end

    -- Colors left over green rooms randomly
    while green_rooms < n_green_rooms do
        local x, y = math.random(1, self.w), math.random(1, self.h) 
        if not isRoomColored(x, y) then
            self.grid[y][x].color = 'green'
            table.insert(colored_rooms, {x = x, y = y})
            green_rooms = green_rooms + 1
        end
    end
end

function Dungeon:pathFind()
    local range_x, range_y = math.floor(self.w/3), math.floor(self.h/3)

    -- self.grid to Jumper grid/map, 0 is walkable (blue/green)
    local map = {}
    for i = 1, self.h do
        map[i] = {}
        for j = 1, self.w do
            if self.red_neighbor then
                if self.grid[i][j].color then
                    if self.grid[i][j].color == 'red' then map[i][j] = 1
                    else map[i][j] = 0 end
                else map[i][j] = 0 end
            else
                if self.grid[i][j].color then map[i][j] = 0
                else map[i][j] = 0 end
            end
        end
    end

    -- Pathfind
    local Grid = require("jumper.grid")
    local Pathfinder = require("jumper.pathfinder")
    local grid = Grid(map)
    local finder = Pathfinder(grid, 'JPS', 0)
    finder:setMode('ORTHOGONAL')
    local path = false
    while not path do
        -- Choose initial and final nodes randomly
        local x1, y1, x2, y2 = math.random(1, range_x), math.random(1, range_y), math.random(self.w-range_x, self.w), math.random(self.h-range_y, self.h)
        local n1_color, n2_color = self.grid[y1][x1].color, self.grid[y2][x2].color
        -- self.grid[y1][x1].color = nil
        -- self.grid[y2][x2].color = nil

        path = finder:getPath(x1, y1, x2, y2)
        if path then
            for node, count in path:nodes() do
                local x, y = node.x, node.y
                self.grid[y][x].in_path_original = true
                -- Add all neighbor red nodes for each node in the path
                local addToPathIfColor = function(x, y, color)
                    if self.grid[y] then
                        if self.grid[y][x] then
                            if self.grid[y][x].color == color then 
                                self.grid[y][x].in_path_additional = true 
                            end
                        end
                    end
                end
                for _, color in ipairs(self.add_path) do
                    addToPathIfColor(x-1, y, color)
                    addToPathIfColor(x+1, y, color)
                    addToPathIfColor(x, y-1, color)
                    addToPathIfColor(x, y+1, color)
                end
            end
        else
            self.grid[y1][x1].color = n1_color
            self.grid[y2][x2].color = n2_color
        end
    end
end

-- Joins all rooms inside the area x, y, x1+w, y1+h and returns true if join was successful, false otherwise.
function Dungeon:join(x, y, w, h)
    if not self.grid[y+h-1] then return false end
    if not self.grid[y+h-1][x+w-1] then return false end
    for i = x, x+w-1 do
        for j = y, y+h-1 do
            if self.grid[j][i].joined then return false end
        end
    end
    self.grid[y][x].joined = true
    self.grid[y][x].original = true
    self.grid[y][x].w = w 
    self.grid[y][x].h = h
    for i = x, x+w-1 do
        for j = y, y+h-1 do
            self.grid[j][i].id = self.grid[y][x].id
            self.grid[j][i].color = self.grid[y][x].color
            self.grid[j][i].joined = true
            if not self.grid[j][i].in_path_original and not self.grid[j][i].in_path_additional then
                self.grid[j][i].in_path_additional = true
            end
        end
    end
    return true
end

function Dungeon:randomizeRoomSizes()
    local not_joined_path_nodes = {}
    local getNotJoinedPathNodes = function()
        not_joined_path_nodes = {}
        for i = 1, self.h do
            for j = 1, self.w do
                if not self.grid[i][j].joined and (self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional) then
                    table.insert(not_joined_path_nodes, {x = j, y = i})
                end
            end
        end
    end
    
    local chooseWithProb = function(choices, chances)
        local r = math.random(1, 1000)
        local intervals = {}
        for i = 1, #chances do 
            if i > 1 then table.insert(intervals, intervals[i-1]+chances[i]*1000) 
            else table.insert(intervals, chances[i]*1000) end
        end
        for i = 1, #intervals do
            if i > 1 then 
                if r >= intervals[i-1] and r <= intervals[i] then return choices[i] end
            else
                if r <= intervals[i] then return choices[i] end
            end
        end
    end

    getNotJoinedPathNodes()
    local n = #not_joined_path_nodes
    for i = 1, n do
        getNotJoinedPathNodes()
        if #not_joined_path_nodes > 0 then
            local joined = false
            while not joined do
                local p = not_joined_path_nodes[math.random(1, #not_joined_path_nodes)]
                local x, y = p.x, p.y
                local w, h = chooseWithProb(self.room_sizes[1], self.room_sizes[2]), chooseWithProb(self.room_sizes[1], self.room_sizes[2])
                joined = self:join(x, y, w, h)
            end
        end
    end
end

function Dungeon:generateConnections()
    self.connections_grid = {}
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                self.connections_grid[j .. i] = {x = j, y = i, left = nil, right = nil, up = nil, down = nil}
                local connect = function(x, y, dir)
                    if self.grid[y] then
                        if self.grid[y][x] then 
                            if self.grid[y][x].in_path_original or self.grid[y][x].in_path_additional then
                                if self.grid[i][j].id ~= self.grid[y][x].id then
                                    self.connections_grid[j .. i][dir] = true 
                                end
                            end
                        end
                    end
                end
                connect(j, i-1, 'up')
                connect(j, i+1, 'down')
                connect(j-1, i, 'left')
                connect(j+1, i, 'right')
            end
        end
    end
    self:calculateConnectionsRoom()
end

function Dungeon:calculateConnectionsRoom()
    self.connections_room = {}
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                self.connections_room[self.grid[i][j].id] = 0
            end
        end
    end
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                if self.connections_grid[j .. i] then
                    local c = self.connections_grid[j .. i]
                    if c.left then self.connections_room[self.grid[i][j].id] = self.connections_room[self.grid[i][j].id] + 1 end
                    if c.right then self.connections_room[self.grid[i][j].id] = self.connections_room[self.grid[i][j].id] + 1 end
                    if c.up then self.connections_room[self.grid[i][j].id] = self.connections_room[self.grid[i][j].id] + 1 end
                    if c.down then self.connections_room[self.grid[i][j].id] = self.connections_room[self.grid[i][j].id] + 1 end
                end
            end
        end
    end
end

function Dungeon:disconnect()
    local n_rooms = 0
    for _, _ in pairs(self.connections_room) do n_rooms = n_rooms + 1 end
    -- How many rooms should have 1, 2, 3 or >4 connections
    if self.desired_con[1] + self.desired_con[2] + self.desired_con[3] + self.desired_con[4] ~= 1 then
        self.desired_con[1] = 0.2
        self.desired_con[2] = 0.5
        self.desired_con[3] = 0.2
        self.desired_con[4] = 0.1
    end
    local desired_connections = {math.floor(self.desired_con[1]*n_rooms), math.floor(self.desired_con[2]*n_rooms), 
                                 math.floor(self.desired_con[3]*n_rooms), math.floor(self.desired_con[4]*n_rooms)} 
    -- How many rooms have 1, 2, 3 or >4 connections
    local connections_room = {0, 0, 0, 0}

    local calculateLocalConnectionsRoom = function()
        connections_room = {0, 0, 0, 0}
        -- Figure out how many rooms per number of connections
        for id, n in pairs(self.connections_room) do
            if n > 0 then
                if n < 4 then connections_room[n] = connections_room[n] + 1
                else connections_room[4] = connections_room[4] + 1 end
            end
        end
    end
    calculateLocalConnectionsRoom()

    local rooms_connection = {}
    local calculateRoomsConnection = function()
        rooms_connection = {{}, {}, {}, {}}
        -- n_rooms -> room id
        for id, n in pairs(self.connections_room) do
            if not rooms_connection[n] then rooms_connection[n] = {} end
            table.insert(rooms_connection[n], id)
        end
    end
    calculateRoomsConnection()

    local getByIdAndDirection = function(id, dir)
        local positions = {}
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j].id == id then
                    local c = self.connections_grid[j .. i]
                    if c.left and dir == 'left' then table.insert(positions, {x = j, y = i}) end
                    if c.right and dir == 'right' then table.insert(positions, {x = j, y = i}) end
                    if c.up and dir == 'up' then table.insert(positions, {x = j, y = i}) end
                    if c.down and dir == 'down' then table.insert(positions, {x = j, y = i}) end
                end
            end
        end
        return positions
    end

    local directions = {'left', 'right', 'up', 'down'}
    -- Remove extra rooms with n connections
    local removeConnections = function(n)
        while #rooms_connection[n] > 0 and (connections_room[n] > desired_connections[n]) do 
            local i = math.random(1, #rooms_connection[n])
            local current_id = rooms_connection[n][i]
            local direction = directions[math.random(1, #directions)]
            local positions = getByIdAndDirection(current_id, direction)
            if #positions > 0 then
                local p = positions[math.random(1, #positions)]
                self.connections_grid[p.x .. p.y][direction] = nil
                local x, y = p.x, p.y
                local opposite_direction = {left = 'right', right = 'left', up = 'down', down = 'up'}
                if direction == 'left' then x = x - 1 end
                if direction == 'right' then x = x + 1 end
                if direction == 'up' then y = y - 1 end
                if direction == 'down' then y = y + 1 end
                self.connections_grid[x .. y][opposite_direction[direction]] = nil
                table.remove(rooms_connection[n], i)
            end
            self:calculateConnectionsRoom()
            calculateLocalConnectionsRoom()
            calculateRoomsConnection()
        end
    end

    removeConnections(4)
    if connections_room[3] > desired_connections[3] then removeConnections(3) end
    if connections_room[2] > desired_connections[2] then removeConnections(2) end

    --[[
    print("Connections: ", connections_room[1], connections_room[2], connections_room[3], connections_room[4])
    print("Desired: ", desired_connections[1], desired_connections[2], desired_connections[3], desired_connections[4])
    ]]--
end

function Dungeon:setffColor(id, color)
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                if self.grid[i][j].id == id then
                    self.grid[i][j].ff_color = color
                end
            end
        end
    end
end

function Dungeon:floodFill(id, color)
    local contains = function(table, value)
        for _, v in ipairs(table) do
            if v == value then return true end
        end
        return false
    end

    if not self.ff_buckets[color] then self.ff_buckets[color] = {} end
    if not contains(self.ff_buckets[color], id) then 
        table.insert(self.ff_buckets[color], id)
        self:setffColor(id, color)
    else return end

    local neighbors = self:getNeighborsById(id)
    for _, neighbor_id in ipairs(neighbors) do
        if self:isIdInPath(neighbor_id) then
            if self:isConnectionBetween(id, neighbor_id) then
                if not contains(self.ff_buckets[color], neighbor_id) then 
                    self:floodFill(neighbor_id, color)
                end
            end
        end
    end
end

function Dungeon:isIdInPath(id)
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].id == id then
                if not self.grid[i][j].in_path_original and not self.grid[i][j].in_path_additional then
                    return false
                end
            end
        end
    end
    return true
end

function Dungeon:isConnectionBetween(id1, id2)
    local id1_positions = {}
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].id == id1 then table.insert(id1_positions, {x = j, y = i}) end
        end
    end
    for _, p in ipairs(id1_positions) do
        local left, up, right, down = self:getNeighbors(p.x, p.y)
        local neighbors = {left = left, up = up, right = right, down = down}
        for dir, n in pairs(neighbors) do
            if n.in_path_original or n.in_path_additional then
                if n.id == id2 then
                    if self.connections_grid[p.x .. p.y] then
                        if self.connections_grid[p.x .. p.y][dir] then
                            return true
                        end
                    end
                end
            end
        end
    end
    return false
end

function Dungeon:reconnect()
    local doWork = function()
        self.ff_buckets = {}

        local contains = function(table, value)
            for _, v in ipairs(table) do
                if v == value then return true end
            end
            return false
        end

        local ids_not_flood_filled = {}
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                    if not contains(ids_not_flood_filled, self.grid[i][j].id) then
                        table.insert(ids_not_flood_filled, self.grid[i][j].id)
                    end
                end
            end
        end

        local updateNotFloodFilled = function()
            local remove = function(id)
                for i = #ids_not_flood_filled, 1, -1 do
                    if id == ids_not_flood_filled[i] then table.remove(ids_not_flood_filled, i) end
                end
            end
            for v, ids in pairs(self.ff_buckets) do
                for _, n in ipairs(ids) do
                    remove(n)
                end
            end
        end

        local current_color = 1
        while #ids_not_flood_filled > 0 do
            self:floodFill(ids_not_flood_filled[math.random(1, #ids_not_flood_filled)], current_color)
            updateNotFloodFilled()
            current_color = current_color + 1
        end
    end

    local getPositionsById = function(id)
        local positions = {}
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                    if self.grid[i][j].id == id then table.insert(positions, {x = j, y = i}) end
                end
            end
        end
        return positions
    end

    local connect = function()
        local r = math.random(1, #self.ff_buckets)
        local positions = {}
        for _, id in ipairs(self.ff_buckets[r]) do
            local positions = getPositionsById(id)
            for _, p in ipairs(positions) do
                local current = self.grid[p.y][p.x]
                local left, up, right, down = self:getNeighbors(p.x, p.y)
                if left then if current.ff_color ~= left.ff_color then
                    if left.in_path_original or left.in_path_additional then
                        local x, y = p.x - 1, p.y
                        self.connections_grid[p.x .. p.y]['left'] = true
                        if self.connections_grid[x.. y] then self.connections_grid[x .. y]['right'] = true end
                        return
                    end
                end end
                if right then if current.ff_color ~= right.ff_color then
                    if right.in_path_original or right.in_path_additional then
                        local x, y = p.x + 1, p.y
                        self.connections_grid[p.x .. p.y]['right'] = true
                        if self.connections_grid[x .. y] then self.connections_grid[x .. y]['left'] = true end
                        return
                    end
                end end
                if up then if current.ff_color ~= up.ff_color then
                    if up.in_path_original or up.in_path_additional then
                        local x, y = p.x, p.y - 1
                        self.connections_grid[p.x .. p.y]['up'] = true
                        if self.connections_grid[x .. y] then self.connections_grid[x .. y]['down'] = true end
                        return
                    end
                end end
                if down then if current.ff_color ~= down.ff_color then
                    if down.in_path_original or down.in_path_additional then
                        local x, y = p.x, p.y + 1
                        self.connections_grid[p.x .. p.y]['down'] = true
                        if self.connections_grid[x .. y] then self.connections_grid[x .. y]['up'] = true end
                        return
                    end
                end end
            end
        end
    end

    doWork()
    while #self.ff_buckets > 1 do
        doWork()
        if #self.ff_buckets > 1 then connect() end
    end
end

function Dungeon:draw()
    love.graphics.setColor(255, 255, 255, 255)
    for i = 1, self.h do
        for j = 1, self.w do
            if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                if self.grid[i][j].original then
                    local w, h = node_w, node_h
                    local self_w, self_h = self.grid[i][j].w*node_w, self.grid[i][j].h*node_h
                    love.graphics.rectangle('line', j*w, i*h, self_w, self_h)
                    if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                        if self.grid[i][j].color == 'red' then love.graphics.setColor(192, 64, 64, 255) end
                        if self.grid[i][j].color == 'blue' then love.graphics.setColor(64, 64, 192, 255) end
                        if self.grid[i][j].color == 'green' then love.graphics.setColor(64, 192, 64, 255) end
                        love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, self_w-w/4, self_h-h/4)
                        love.graphics.setColor(255, 255, 255, 255)
                        -- love.graphics.print(self.grid[i][j].id, j*w+4, i*h+4)
                    end
                end
            end
        end
    end
    love.graphics.setColor(228, 228, 228, 255)
    local w, h = node_w, node_h
    for xy, dirs in pairs(self.connections_grid) do
        if self.grid[dirs.y][dirs.x].in_path_original or self.grid[dirs.y][dirs.x].in_path_additional then
            if dirs.left then love.graphics.rectangle('line', dirs.x*w-w/8, dirs.y*h+h/3, w/4, h/4) end
            if dirs.right then love.graphics.rectangle('line', dirs.x*w+w-w/8, dirs.y*h+h/3, w/4, h/4) end
            if dirs.up then love.graphics.rectangle('line', dirs.x*w+w/2-w/8, dirs.y*h-h/8, w/4, h/4) end
            if dirs.down then love.graphics.rectangle('line', dirs.x*w+w/2-w/8, dirs.y*h+h-h/8, w/4, h/4) end
        end
    end
    love.graphics.setColor(255, 255, 255, 255)
end

setmetatable(Dungeon, {__call = function(_, ...) local d = Dungeon.new(...); d:generateDungeon(); return d end})
