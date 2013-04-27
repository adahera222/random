local attack = struct('activation', 'cooldown', 'damage', 'multiple', 'pierce', 'reflect', 'back', 'area')
attacks = {}
attacks['test'] = Attack(attack('press', 0.5, 10, 1, 1, 0, false, 'test'))

local area = struct('r_i', 'r_f', 'duration', 'tween', 'on_hit', 'cooldown', 'damage', 'slow')
areas = {}
areas['test'] = area(48, 48, 1, false, false, 0.5, 25, 0.25)
