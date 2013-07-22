require 'Dungeon'

function love.load()
    -- width = 25, height = 16
    -- 25% rooms = red, 35% = blue, 40% = green
    -- red, blue and green rooms get added around the path
    -- sizes for room width/height 1 -> 70% prob, 2 -> 20%, 3 -> 10%
    -- desired connections per room -> 100% -> 1 connection, 0% -> 2 connections, 0% -> 3 connections, 0% -> 4 connections
    dungeon1 = Dungeon(5, 5, {0.25, 0.35, 0.4}, {'red', 'blue', 'green'}, {{1, 2, 3}, {0.5, 0.3, 0.2}}, {0.7, 0.2, 0.05, 0.05})
    room_w, room_h = 32, 32

    text_grid = {}
    for i = 1, dungeon1.h*2+1 do
        text_grid[i] = {}
    end

    -- Initial
    for i = 1, dungeon1.h do
        local str = ""
        for j = 1, dungeon1.w do
            if dungeon1.grid[i][j].in_path_original or dungeon1.grid[i][j].in_path_additional then
                local px, py = 2*j-1, 2*i-1
                text_grid[py][px] = 0
                text_grid[py+1][px] = 0
                text_grid[py+2][px] = 0
                text_grid[py][px+1] = 0
                text_grid[py][px+2] = 0
                text_grid[py+1][px+1] = dungeon1.grid[i][j].id
                text_grid[py+2][px+2] = 0
                text_grid[py+2][px+1] = 0
                text_grid[py+1][px+2] = 0
            else
                local px, py = 2*j-1, 2*i-1
                text_grid[py][px] = 0
                text_grid[py+1][px] = 0
                text_grid[py+2][px] = 0
                text_grid[py][px+1] = 0
                text_grid[py][px+2] = 0
                text_grid[py+1][px+1] = 0
                text_grid[py+2][px+2] = 0
                text_grid[py+2][px+1] = 0
                text_grid[py+1][px+2] = 0
            end
        end
    end

    local isEqual = function(id, x, y)
        if text_grid[y] then
            if text_grid[y][x] == id then
                return true
            end
        end
        return false
    end

    -- Connect inner rooms
    for i = 1, dungeon1.h*2+1 do
        for j = 1, dungeon1.w*2+1 do
            if text_grid[i] then
                if text_grid[i][j] ~= 0 then
                    -- print(text_grid[i][j])
                    if isEqual(text_grid[i][j], j-2, i) then text_grid[i][j-1] = text_grid[i][j] end
                    if isEqual(text_grid[i][j], j+2, i) then text_grid[i][j+1] = text_grid[i][j] end
                    if isEqual(text_grid[i][j], j, i-2) then text_grid[i-1][j] = text_grid[i][j] end
                    if isEqual(text_grid[i][j], j, i+2) then text_grid[i+1][j] = text_grid[i][j] end
                end
            end
        end
    end

    local connect = function(x, y, dx, dy)
        if text_grid[y+dy] then
            text_grid[y+dy][x+dx] = -1
        end
    end

    -- Connect all rooms
    for xy, dirs in pairs(dungeon1.connections_grid) do
        if dungeon1.grid[dirs.y][dirs.x].in_path_original or dungeon1.grid[dirs.y][dirs.x].in_path_additional then
            local px, py = 2*dirs.x-1, 2*dirs.y-1
            if dirs.left then connect(px+1, py+1, -1, 0) end
            if dirs.right then connect(px+1, py+1, 1, 0) end
            if dirs.up then connect(px+1, py+1, 0, -1) end
            if dirs.down then connect(px+1, py+1, 0, 1) end
        end
    end

    local f = love.filesystem.newFile("out")
    f:open("w")
    f:write("\n\r")
    for i = 1, dungeon1.h*2+1 do
        local str = ""
        for j = 1, dungeon1.w*2+1 do
            if text_grid[i][j] == -1 then
                str = str .. "-- "
            elseif text_grid[i][j] < 10 then
                str = str .. "0" .. text_grid[i][j] .. " "
            else
                str = str .. text_grid[i][j] .. " "
            end
        end
        str = str .. "\n\r"
        f:write(str)
    end
    f:close()
end

function love.draw()
    -- dungeon1:draw()
    for i = 1, dungeon1.h*2+1 do
        local str = ""
        for j = 1, dungeon1.w*2+1 do
            if text_grid[i][j] == -1 then
                str = str .. "//// "
            elseif text_grid[i][j] < 10 then
                str = str .. "0" .. text_grid[i][j] .. " "
            else
                str = str .. text_grid[i][j] .. " "
            end
        end
        str = str .. "\n"
        love.graphics.print(str, 20, i*20)
    end
end
