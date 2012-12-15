require 'Entity'

Projectile = class('Projectile', Entity)

function Projectile:initialize(x, y, r, speed)
    Entity.initialize(self, gl.entity_id(), x, y, 4, 4, gl.projectile) 
    self.r = r
    self.dir = Vector(math.cos(self.r), math.sin(self.r))
    self.shot_speed = speed
end

function Projectile:update(dt)
    Entity.update(self, dt)
    self.p.x = self.p.x + self.shot_speed*self.dir.x*dt
    self.p.y = self.p.y + self.shot_speed*self.dir.y*dt
end

function Projectile:draw()
    Entity.draw(self)
end
