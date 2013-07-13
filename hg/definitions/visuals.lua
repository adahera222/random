function loadVisuals()
    grass = love.graphics.newImage('res/hggrassground.png')
    night_overlay = love.graphics.newImage('res/nightoverlay.png')
    clock = love.graphics.newImage('res/clock.png')
    cursor = love.graphics.newImage('res/cursor.png')

    local animation = struct('source', 'w', 'h', 'delay', 'mode')    
    player_animations = {
        idle_up = animation(love.graphics.newImage('res/player/player_idle_up.png'), 54, 92, 0.2),
        idle_down = animation(love.graphics.newImage('res/player/player_idle_down.png'), 54, 92, 0.2),
        idle_left = animation(love.graphics.newImage('res/player/player_idle_left.png'), 54, 92, 0.2),
        idle_right = animation(love.graphics.newImage('res/player/player_idle_right.png'), 54, 92, 0.2),
        walk_up = animation(love.graphics.newImage('res/player/player_walk_up.png'), 54, 92, 0.2),
        walk_down = animation(love.graphics.newImage('res/player/player_walk_down.png'), 54, 92, 0.2),
        walk_left = animation(love.graphics.newImage('res/player/player_walk_left.png'), 54, 92, 0.2),
        walk_right = animation(love.graphics.newImage('res/player/player_walk_right.png'), 54, 92, 0.2)}
    prop_animations = {
        rock = {idle = animation(love.graphics.newImage('res/objects/rock_idle.png'), 52, 18, 0.2)},
        boulder = {idle = animation(love.graphics.newImage('res/objects/boulder_idle.png'), 152, 134, 0.2)},
        bush = {idle = animation(love.graphics.newImage('res/objects/bush_idle.png'), 89, 57, 0.2)},
        tree = {idle = animation(love.graphics.newImage('res/objects/tree_idle.png'), 147, 289, 0.2)}}
end
