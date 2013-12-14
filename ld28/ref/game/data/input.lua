local map_key = struct('type', 'action', 'keys')
player_keys = {
    map_key('down', 'MOVE LEFT', {'a', 'left'}),
    map_key('down', 'MOVE RIGHT', {'d', 'right'}),
    map_key('down', 'JUMP', {'w', ' ', 'up'}),
    map_key('down', 'DOWN', {'s', 'down'}),
    map_key('press', 'ATTACK 1 PRESSED', {'j', 'z'}),
    map_key('press', 'ATTACK 2 PRESSED', {'k', 'x'}),
    map_key('press', 'ATTACK 3 PRESSED', {'l', 'c'}),
    map_key('press', 'JUMP PRESSED', {'w', ' ', 'up'}),
    map_key('press', 'SHIELD PRESSED', {'lshift'}),
    map_key('release', 'ATTACK 3 RELEASED', {'l', 'c'}),
    map_key('release', 'JUMP RELEASED', {'w', ' ', 'up'}),
    map_key('release', 'DOWN RELEASED', {'s', 'down'}),
    map_key('release', 'SHIELD RELEASED', {'lshift'}),
}
