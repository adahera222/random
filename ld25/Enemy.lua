require 'Movable'

Enemy = class('Enemy', Movable)

function Enemy:initialize(enemy_type, x, y, f_radius, level)
    if enemy_type == 'child' then
        Movable.initialize(self, x, y, 16, 16, math.random(500, 1000), 
                           Vector(math.random(200, 500), math.random(200, 500)), 0.90, 400, -200, 1)
        self.image = gl.child
    else
        Movable.initialize(self, x, y, 32, 32, 200, Vector(400, 400), 0.90, 400, -50, 1)
        self.image = gl.person_normal
    end

    math.randomseed(os.time())
    math.random(); math.random(); math.random();

    self.type = enemy_type

    self.speaking_bad = false
    self.speaking_mom = false
    self.current_speech = nil
    self.current_duration = 0
    self.current_t = 0
    self.speak_delay = math.random(0, 500)/100
    self.speak_t = 0
    self.jump_delay = math.random(0, 500)/100
    self.jump_t = 0
    self.can_jump = false
    self.dt = dt

    self.seek_target = Vector(math.random(64, level.width-64), math.random(64, level.height-64))
    self.flee_radius = f_radius
    self.desired_velocity = Vector()
    self.steering = Vector()
    self.steering_force = Vector()
    self.fleeing = false
end

function Enemy:update(dt, player)
    Movable.update(self, dt)

    self:behavior(dt, player.p)
    if self.type == 'child' then
        self:flee(player.p)

        self.steering_force = self.steering:min(500)
        self.a = self.steering_force
        self.v = (self.v + self.a*dt):min(self.max_v)
        self.p = self.p + self.v*dt
    end
end

function Enemy:speak()
    if self.current_duration > 0 then
        if self.type == 'child' then
            love.graphics.draw(self.current_speech, self.p.x - self.w/4, self.p.y - 2*self.h)
        else
            love.graphics.draw(self.current_speech, self.p.x + self.w/2, self.p.y - self.h)
        end
        self.current_duration = self.current_duration - self.dt
    end
end

function Enemy:behavior(dt, target)
    self.dt = dt

    if self.type == 'person' then
        local d = math.abs(self.p.x - target.x)
        if d < 300 then self.speaking_mom = true
        else self.speaking_mom = false end
    end

    if self.fleeing then self.speaking_bad = true
    else self.speaking_bad = false end

    if self.can_jump then
        beholder:trigger('jump' .. self.id)
        self.can_jump = false
    end

    if self.speak_t >= self.speak_delay then
        self.speak_t = 0

        if self.type == 'child' then
            self.speak_delay = math.random(200, 500)/100
            if self.speaking_bad then
                local rn = math.random(1, #gl.flee)
                self.current_speech = gl.flee[rn][1]
                self.current_duration = gl.flee[rn][2]
            else
                local rn = math.random(1, #gl.happy)
                self.current_speech = gl.happy[rn][1]
                self.current_duration = gl.happy[rn][2]
            end
        else
            self.speak_delay = math.random(500, 1000)/100
            if self.speaking_mom then
                local rn = math.random(1, #gl.mom_speak)
                self.current_speech = gl.mom_speak[rn][1]
                self.current_duration = gl.mom_speak[rn][2]
            end
        end

    end

    if self.jump_t >= self.jump_delay then
        self.can_jump = true
        self.jump_t = 0
        if self.fleeing then
            local distance = math.abs(self.p.x - target.x)
            self.jump_delay = math.random(distance, 3*distance)/100
        else self.jump_delay = math.random(100, 500)/100 end
    end

    self.jump_t = self.jump_t + dt
    self.speak_t = self.speak_t + dt
end

function Enemy:seek(target)
    self.desired_velocity = (target - self.p):normalized()*self.max_v
    self.steering = self.desired_velocity - self.v
end

function Enemy:flee(target)
    self.desired_velocity = (self.p - target)
    local distance = self.desired_velocity:len()

    if distance < self.flee_radius then
        self.fleeing = true
        self.desired_velocity = 
        self.desired_velocity:normalized()*self.max_v*(1-(distance/self.flee_radius))
    else
        self.fleeing = false
        self.desired_velocity = Vector()
    end
   
    self.steering = self.desired_velocity - self.v
end

function Enemy:draw()
    Movable.draw(self)
    self:speak()
    love.graphics.setColor(255, 0, 0)
    -- love.graphics.circle('line', self.p.x - self.w/2, self.p.y - self.h/2, self.flee_radius)
    love.graphics.setColor(255, 255, 255)
end
