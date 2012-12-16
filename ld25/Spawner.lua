require 'Entity'

Spawner = class('Spawner', Entity)

function Spawner:initialize(x, y)
    Entity.initialize(self, gl.entity_id(), x, y, 64, 64, gl.spawner)
    self.p = Vector(x, y)
    self.next_spawn_delay = 5
    self.spawn_t = 0
end

function Spawner:update(dt)
    self:spawn(dt)
end

function Spawner:draw()
    Entity.draw(self)
end

function Spawner:spawn(dt)
    self.spawn_t = self.spawn_t + dt
    if self.spawn_t >= self.next_spawn_delay then
        self.spawn_t = 0
        self.next_spawn_delay = math.random(1, 4)
        local m = 1
        if self.next_spawn_delay % 2 == 0 then m = -1 end
        beholder:trigger('spawn', self.p.x + m*48, self.p.y)
    end
end
