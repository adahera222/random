Spawner = class('Spawner')

function Spawner:initialize()
    local enemy = struct('w', 'h', 'v', 'hp')
    self.ess = enemy(16, 16, 100, 300)
    self.esf = enemy(16, 16, 250, 225)
    self.ebs = enemy(32, 32, 50, 750)
    self.ebf = enemy(32, 32, 150, 450)
    self.ehs = enemy(44, 44, 100, 3000)

    directions = {'right', 'left'}
    spawn_table = {}
    spawn_rate = 3
    for i = 1, 1000 do
        if i <= 100 then table.insert(spawn_table, 'ss')
        elseif i > 100 and i <= 250 then table.insert(spawn_table, 'sf')
        elseif i >= 250 and i < 400 then table.insert(spawn_table, '3ss')
        elseif i >= 400 and i < 550 then table.insert(spawn_table, '3sf')
        elseif i >= 550 and i < 700 then table.insert(spawn_table, 'bs')
        elseif i >= 700 and i < 850 then table.insert(spawn_table, 'bf')
        else table.insert(spawn_table, 'hs') end
    end

    self.spawn_timer = 0
    self.next_spawn = spawn_rate
end

function Spawner:update(dt)
    self.spawn_timer = self.spawn_timer + dt
    if self.spawn_timer > self.next_spawn then
        self.spawn_timer = 0
        self.next_spawn = math.random(spawn_rate-spawn_rate/2, spawn_rate+spawn_rate/2)
        local spawn_type = spawn_table[math.random(1, 1000)]
        if spawn_type == 'ss' then
            beholder.trigger('CREATE ENEMY', 212+300, 16,
            self.ess.w, self.ess.h, self.ess.v, self.ess.hp, directions[math.random(1, 2)])

        elseif spawn_type == 'sf' then
            beholder.trigger('CREATE ENEMY', 212+300, 16,
            self.esf.w, self.esf.h, self.esf.v, self.esf.hp, directions[math.random(1, 2)])

        elseif spawn_type == 'bs' then
            beholder.trigger('CREATE ENEMY', 212+300, 16,
            self.ebs.w, self.ebs.h, self.ebs.v, self.ebs.hp, directions[math.random(1, 2)])

        elseif spawn_type == 'bf' then
            beholder.trigger('CREATE ENEMY', 212+300, 16,
            self.ebf.w, self.ebf.h, self.ebf.v, self.ebf.hp, directions[math.random(1, 2)])

        elseif spawn_type == 'hs' then
            beholder.trigger('CREATE ENEMY', 212+300, 16,
            self.ehs.w, self.ehs.h, self.ehs.v, self.ehs.hp, directions[math.random(1, 2)])

        elseif spawn_type == '3ss' then
            local direction = directions[math.random(1, 2)]
            chrono:every(0.2, 3, function()
                beholder.trigger('CREATE ENEMY', 212+300, 16,
                self.ess.w, self.ess.h, self.ess.v, self.ess.hp, direction)
            end)

        elseif spawn_type == '3sf' then
            chrono:every(0.2, 3, function()
                beholder.trigger('CREATE ENEMY', 212+300, 16,
                self.esf.w, self.esf.h, self.esf.v, self.esf.hp, direction)
            end)
        end
    end

    if enemies_killed <= 20 then spawn_rate = 2
    elseif enemies_killed > 20 and enemies_killed <= 40 then spawn_rate = 1
    elseif enemies_killed > 40 and enemies_killed <= 60 then spawn_rate = 0.75
    elseif enemies_killed > 60 then spawn_rate = 0.5 end
end
