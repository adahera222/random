function loadInput()
    local map_key = struct('type', 'action', 'keys') 
    player_keys = {
        map_key('down', 'MOVE LEFT', {'left', 'a'}),
        map_key('down', 'MOVE RIGHT', {'right', 'd'}),
        map_key('down', 'MOVE UP', {'up', 'w'}),
        map_key('down', 'MOVE DOWN', {'down', 's'})}
end
