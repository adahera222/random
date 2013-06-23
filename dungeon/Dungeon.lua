Dungeon = {}
Dungeon.__index = Dungeon

function Dungeon.new(w, h)
    return setmetatable({w = w or 1, h = h or 1, grid = {}}, Dungeon)
end

function Dungeon:__tostring()
    local str = "----\n"
    for i = 1, self.w do
        str = str .. "[ "
        for j = 1, self.h do
            str = str .. self.grid[i][j] .. ", "
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

function Dungeon:getRandomRoomSize()
    return math.random(2, 6), math.random(1, 4)
end

function Dungeon:getFreeSubgridWidth(i, j)
    if self.grid[i] then
        if self.grid[i][j] ~= 0 then return 0 end
    else return 0 end
    return 1 + self:getFreeSubgridWidth(i+1, j)
end

function Dungeon:getFreeSubgridHeight(i, j)
    if self.grid[i] then
        if self.grid[i][j] ~= 0 then return 0 end
    else return 0 end
    return 1 + self:getFreeSubgridHeight(i, j+1) 
end

-- Returns w, h -> the size of the unnocupied subgrid below and to the right of i, j.
function Dungeon:getFreeSubgridSize(i, j)
    return self:getFreeSubgridWidth(i, j), self:getFreeSubgridHeight(i, j)
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

-- Adds rooms of random sizes to the grid until it's completely filled.
-- When there are few spots available it changes to filling them up with rooms of the appropriate size.
function Dungeon:processGrid()
    
end

setmetatable(Dungeon, {__call = function(_, ...) return Dungeon.new(...) end})
