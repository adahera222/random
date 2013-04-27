local attack = struct('activation', 'cooldown', 'damage', 'multiple', 'pierce', 'reflect', 'back', 'area')
attacks = {}
attacks['test'] = Attack(attack('press', 0.5, 50, 1, 1, 0, false, 'test'))

local area = struct('r_i', 'r_f', 'duration', 'tween', 'on_hit')
areas = {}
areas['test'] = area(48, 48, 1, false, false)
