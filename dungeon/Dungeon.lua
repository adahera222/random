Dungeon = {}
Dungeon.__index = Dungeon

function Dungeon.new(w, h)
    return setmetatable({w = w or 1, h = h or 1, grid = {}, free_slots = {}}, Dungeon)
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
    for i = 1, self.w do
        self.grid[i] = {}
        for j = 1, self.h do
            self.grid[i][j] = 0
        end
    end
end

-- Returns two random numbers between 1, 6 and 1, 4 (for room width and height)
local function getRandomRoomSize(max_w, max_h)
    return math.random(1, math.min(math.max(1, max_w), 6)), math.random(1, math.min(math.max(1, max_h), 4))
end

local function getFreeSubgridWidth(dungeon, i, j)
    if dungeon.grid[i] then
        if dungeon.grid[i][j] ~= 0 then return 0 end
    else return 0 end
    return 1 + getFreeSubgridWidth(dungeon, i+1, j)
end

local function getFreeSubgridHeight(dungeon, i, j)
    if dungeon.grid[i] then
        if dungeon.grid[i][j] ~= 0 then return 0 end
    else return 0 end
    return 1 + getFreeSubgridHeight(dungeon, i, j+1) 
end

-- Returns w, h -> the size of the unnocupied subgrid below and to the right of i, j.
local function getFreeSubgridSize(dungeon, i, j)

end

function Dungeon:findFreeSlots()
    self.free_slots = {}
    for i = 1, self.w do
        for j = 1, self.h do
            if self.grid[i][j] == 0 then 
                table.insert(self.free_slots, {i, j})
            end
        end
    end
end

-- Sets all the grids starting at position i, j and ending at i+w, j+h to id. 
function Dungeon:setSubgrid(id, i, j, w, h)
    for k = 1, w do
        for l = 1, h do
            if self.grid[i+k-1] then
                if self.grid[i+k-1][j+l-1] then
                    if self.grid[i+k-1][j+l-1] == 0 then
                        self.grid[i+k-1][j+l-1] = id 
                    end
                end
            end
        end
    end
end

-- Adds rooms of random sizes to the grid until it's completely filled up :3.
function Dungeon:generateGrid()
    self:initializeGrid()
    self:findFreeSlots()
    local id = 0
    while #self.free_slots ~= 0 do
        id = id + 1
        local slot = self.free_slots[math.random(1, #self.free_slots)]
        local i, j = slot[1], slot[2]
        local sw, sh = getFreeSubgridSize(self, i, j)
        local w, h = getRandomRoomSize(sw, sh)
        self:setSubgrid(id, i, j, h, w)
        print(j, i, w, h)
        print(self)
        self:findFreeSlots()
    end
end

setmetatable(Dungeon, {__call = function(_, ...) return Dungeon.new(...) end})
