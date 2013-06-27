require 'Graph'

GridNode = struct('id', 'w', 'h', 'color', 'in_path_original', 'in_path_additional')
local node_w, node_h = 32, 32

Dungeon = {}
Dungeon.__index = Dungeon

function Dungeon.new(w, h)
    return setmetatable({w = w or 1, h = h or 1, grid = {}, graph = Graph(), draw_state = 'grid'}, Dungeon)
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
    self:generateGraph()
    self:colorNodes()
    self:pathFind()
    self:randomizeRoomSizes()
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

function Dungeon:generateGraph()
    self.graph:findNodes()
    self.graph:findEdges()
    for i = 1, self.h do
        for j = 1, self.w do
            local current = self:getGridXY(j, i) and self:getGridXY(j, i).id
            local left = self:getGridXY(j-1, i) and self:getGridXY(j-1, i).id
            local right = self:getGridXY(j+1, i) and self:getGridXY(j+1, i).id
            local up = self:getGridXY(j, i-1) and self:getGridXY(j, i-1).id
            local down = self:getGridXY(j, i+1) and self:getGridXY(j, i+1).id
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

function Dungeon:colorNodes()
    local total_rooms = self.w*self.h
    local n_red_rooms = math.floor(total_rooms*0.25)
    local n_blue_rooms = math.ceil(total_rooms*0.35)
    local n_green_rooms = math.floor(total_rooms*0.4)
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

    -- Colors n_red_rooms red such that no red room has another red room as neighbor 
    local red_rooms = 0
    while red_rooms < n_red_rooms do
        local x, y = math.random(1, self.w), math.random(1, self.h) 
        if not isRoomColored(x, y) and not areNeighborsColored(x, y, 'red', 0) then
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
            if self.grid[i][j].color then
                if self.grid[i][j].color == 'red' then map[i][j] = 1
                else map[i][j] = 0 end
            else map[i][j] = 0 end
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
        self.grid[y1][x1].color = nil
        self.grid[y2][x2].color = nil

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
                addToPathIfColor(x-1, y, 'red')
                addToPathIfColor(x+1, y, 'red')
                addToPathIfColor(x, y-1, 'red')
                addToPathIfColor(x, y+1, 'red')
                addToPathIfColor(x-1, y, 'blue')
                addToPathIfColor(x+1, y, 'blue')
                addToPathIfColor(x, y-1, 'blue')
                addToPathIfColor(x, y+1, 'blue')
                addToPathIfColor(x-1, y, 'green')
                addToPathIfColor(x+1, y, 'green')
                addToPathIfColor(x, y-1, 'green')
                addToPathIfColor(x, y+1, 'green')
            end
        else
            self.grid[y1][x1].color = n1_color
            self.grid[y2][x2].color = n2_color
        end
    end
end

function Dungeon:randomizeRoomSizes()
    local widths = {32, 64}
    local heights = {32, 64}
end

function Dungeon:draw()
    love.graphics.setColor(255, 255, 255, 255)
    if self.draw_state == 'grid' then
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j] then
                    local w, h = self.grid[i][j].w, self.grid[i][j].h
                    love.graphics.rectangle('line', j*w, i*h, w, h)
                end
            end
        end
    elseif self.draw_state == 'colored' then
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j] then
                    local w, h = self.grid[i][j].w, self.grid[i][j].h
                    love.graphics.rectangle('line', j*w, i*h, w, h)
                    if self.grid[i][j].color == 'red' then love.graphics.setColor(192, 64, 64, 255) end
                    if self.grid[i][j].color == 'blue' then love.graphics.setColor(64, 64, 192, 255) end
                    if self.grid[i][j].color == 'green' then love.graphics.setColor(64, 192, 64, 255) end
                    love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, w-w/4, h-h/4)
                    love.graphics.setColor(255, 255, 255, 255)
                end
            end
        end
    elseif self.draw_state == 'path' then
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j] then
                    local w, h = self.grid[i][j].w, self.grid[i][j].h
                    love.graphics.rectangle('line', j*w, i*h, w, h)
                    if self.grid[i][j].in_path_original then
                        if self.grid[i][j].color == 'red' then love.graphics.setColor(192, 64, 64, 255) end
                        if self.grid[i][j].color == 'blue' then love.graphics.setColor(64, 64, 192, 255) end
                        if self.grid[i][j].color == 'green' then love.graphics.setColor(64, 192, 64, 255) end
                        love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, w-w/4, h-h/4)
                    else
                        if self.grid[i][j].color == 'red' then love.graphics.setColor(48, 16, 16, 255) end
                        if self.grid[i][j].color == 'blue' then love.graphics.setColor(16, 16, 48, 255) end
                        if self.grid[i][j].color == 'green' then love.graphics.setColor(16, 48, 16, 255) end
                        love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, w-w/4, h-h/4)
                    end
                    love.graphics.setColor(255, 255, 255, 255)
                end
            end
        end
    elseif self.draw_state == 'filled_path' then
        for i = 1, self.h do
            for j = 1, self.w do
                if self.grid[i][j] then
                    local w, h = self.grid[i][j].w, self.grid[i][j].h
                    love.graphics.rectangle('line', j*w, i*h, w, h)
                    if self.grid[i][j].in_path_original or self.grid[i][j].in_path_additional then
                        if self.grid[i][j].color == 'red' then love.graphics.setColor(192, 64, 64, 255) end
                        if self.grid[i][j].color == 'blue' then love.graphics.setColor(64, 64, 192, 255) end
                        if self.grid[i][j].color == 'green' then love.graphics.setColor(64, 192, 64, 255) end
                        love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, w-w/4, h-h/4)
                    else
                        if self.grid[i][j].color == 'red' then love.graphics.setColor(48, 16, 16, 255) end
                        if self.grid[i][j].color == 'blue' then love.graphics.setColor(16, 16, 48, 255) end
                        if self.grid[i][j].color == 'green' then love.graphics.setColor(16, 48, 16, 255) end
                        love.graphics.rectangle('fill', j*w+w/8, i*h+h/8, w-w/4, h-h/4)
                    end
                    love.graphics.setColor(255, 255, 255, 255)
                end
            end
        end
    end
end

setmetatable(Dungeon, {__call = function(_, ...) return Dungeon.new(...) end})
