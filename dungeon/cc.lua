-- Returns two random numbers between 1, 6 and 1, 4 (for room width and height)
local function getRandomRoomSize(max_w, max_h)
    return math.random(1, math.min(math.max(1, max_w), 6)), math.random(1, math.min(math.max(1, max_h), 4))
end

local function getFreeSubgridWidth(dungeon, x, y)
    if dungeon.grid[y] then
        if dungeon.grid[y][x] ~= 0 then return 0 end
    else return 0 end
    return 1 + getFreeSubgridWidth(dungeon, x+1, y)
end

local function getFreeSubgridHeight(dungeon, x, y)
    if dungeon.grid[y] then
        if dungeon.grid[y][x] ~= 0 then return 0 end
    else return 0 end
    return 1 + getFreeSubgridHeight(dungeon, x, y+1) 
end

-- Returns w, h -> the size of the unnocupied subgrid below and to the right of i, j.
local function getFreeSubgridSize(dungeon, i, j)

end

