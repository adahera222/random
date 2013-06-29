struct = require 'struct'
require 'Graph'
require 'Dungeon'

function love.load()
    dungeon = Dungeon(22, 12)
    dungeon:generateDungeon()
    n = 1
end

function love.update(dt)
    
end

function love.draw()
    dungeon:draw()
end

function love.keypressed(key)
    local draw_states = {'grid', 'colored', 'path', 'filled_path', 'join', 'connect', 'disconnect'}
    if key == 'n' then
        n = n + 1
        if n > 7 then n = 1 end
        dungeon.draw_state = draw_states[n]
    end
end
