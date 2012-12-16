require 'Movable'

Player = class('Player', Movable)

function Player:initialize(x, y, weapon)
    Movable.initialize(self, x, y, 32, 32, 250, Vector(500, 500), 0.90, 600, -250, 2)
    self.image = gl.player_normal
    self.weapon = weapon
    self.weapon_image = gl[weapon] or nil
    self.dir = 'right'
    self.r = 0
    self.shot_t = 0
    self.current_speech = nil
    self.current_t = 0
    self.current_end = 3
    self.current_count = false
    self.dead = false

    if weapon == 'gun_1' then
        self.recoil = 75
        self.shot_delay = 0.3
    elseif weapon == 'gun_2' then
        self.recoil = 150
        self.shot_delay = 0.2
    elseif weapon == 'gun_3' then
        self.recoil = 225
        self.shot_delay = 0.15
    end

    beholder.observe('player speak mom' .. self.id,
                     function(times)
                         if times == 1 then 
                             self.current_speech = gl.himom
                             self.current_count = true
                         elseif times == 2 then 
                             self.current_speech = gl.sorry
                             self.current_count = true
                         else 
                             self.current_speech = gl.dots 
                             self.current_count = true
                         end
                     end)

    beholder.observe('player speak friends' .. self.id,
                     function() 
                         self.current_speech = gl.higuys
                         self.current_count = true
                     end)
end

function Player:update(dt, camera)
    Movable.update(self, dt, self.id)
    self:setDirection(camera)
    self.shot_t = self.shot_t + dt
    if self.current_count then
        self.current_t = self.current_t + dt
    end

    if self.current_t >= self.current_end then
        self.current_count = false
        self.current_t = 0
        self.current_speech = nil
    end
end

function Player:draw()
    Movable.draw(self)
    self:speak()
end

function Player:speak()
    if self.current_speech then
        love.graphics.draw(self.current_speech, self.p.x + self.w/2, self.p.y - self.h)
    end
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
        if self.shot_t >= self.shot_delay then
            beholder:trigger('create projectile', self.r) 
            if not gl.shot:isStopped() then
                gl.shot:rewind()
            end
            love.audio.play(gl.shot)
            self.v.x = self.v.x - self.recoil*math.cos(self.r)
            self.v.y = self.v.y - self.recoil*math.sin(self.r)
            self.shot_t = 0
        end
    end
end
