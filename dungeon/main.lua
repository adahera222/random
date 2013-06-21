struct = require 'struct'

math.randomseed(os.time())
math.random(); math.random(); math.random();

Point = struct('x', 'y')
Rectangle = struct('x', 'y', 'w', 'h')

function love.load()
    dungeon_w, dungeon_h = 16, 16
    min_room_w, min_room_h = 16, 16

    dungeon = {}
    for i = 1, dungeon_h do
        dungeon[i] = {}
        for j = 1, dungeon_w do
            dungeon[i][j] = 0
        end
    end

    printDungeon()
end

function printDungeon()
    local str = ""
    for i = 1, dungeon_h do
        str = ""
        str = str .. "[ " 
        for j = 1, dungeon_w do
            str = str .. dungeon[i][j] .. " "
        end
        str = str .. "]"
        print(str)
    end
end

function love.update(dt)
    
end

function love.draw()

end
