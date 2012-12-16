require 'Movable'

Player = class('Player', Movable)

function Player:initialize(x, y, weapon)
    Movable.initialize(self, x, y, 32, 32, 250, Vector(500, 500), 0.90, 600, -250, 2)
    self.image = gl.player_normal
    self.weapon = weapon
    self.weapon_image = gl[weapon] or nil
    self.dir = 'right'
    self.r = 0
end

function Player:update(dt, camera)
    Movable.update(self, dt, self.id)
    self:setDirection(camera)
end

function Player:draw()
    Movable.draw(self)
end

function Player:setDirection(camera)
    local x, y = love.mouse.getPosition()
    local delta = Vector(x - self.p.x + camera.p.x,
                         y - self.p.y + camera.p.y)
    self.r = math.atan2(delta.y, delta.x)
    if radToDeg(self.r) >= -90 and radToDeg(self.r) <= 90 then self.direction = 'right'
    else self.direction = 'left' end
end

function Player:mousepressed(x, y, button)
    if button == 'l' then
        beholder:trigger('create projectile', self.r) 
        if not gl.shot:isStopped() then
            gl.shot:rewind()
        end
        love.audio.play(gl.shot)
        self.v.x = self.v.x - 200*math.cos(self.r)
        self.v.y = self.v.y - 200*math.sin(self.r)
    end
end
