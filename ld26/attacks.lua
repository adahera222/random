local attack = struct('activation', 'cooldown', 'damage', 'multiple', 'pierce', 'reflect', 'back', 'area')
attacks = {}
attacks['test'] = Attack(attack('hold', 0.3, 10, 1, 0, 0, false, false)) 

local area = struct('r_i', 'r_f', 'duration', 'tween', 'on_hit', 'cooldown', 'damage', 'slow')
areas = {}
areas['test'] = area(48, 48, 1, false, false, false, false, false)

-- Perfection is achieved, not when there is nothing more to add, but when there is nothing left to take away.
