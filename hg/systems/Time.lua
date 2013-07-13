Time = class('Time')

function Time:initialize(seconds_in_game_hour)
    self.s = seconds_in_game_hour
    self.time = 12
    self.day = true
    self.overlay_alpha = 0

    chrono:every(self.s, function() 
        self.time = self.time + 1 
        if self.time == 6 then 
            self.day = true 
            beholder.trigger('NIGHT TO DAY', 2*self.s)
        end

        if self.time == 18 then
            self.day = false 
            beholder.trigger('DAY TO NIGHT', 2*self.s)
        end

        if self.time == 24 then self.time = 0 end
    end)

    self.clock_anim = newAnimation(clock, 206, 205, 2*self.s, 0)
    self.clock_anim:seek(4)

    beholder.observe('NIGHT TO DAY', function(d) tween(d, self, {overlay_alpha = 0}, 'linear') end)
    beholder.observe('DAY TO NIGHT', function(d) tween(d, self, {overlay_alpha = 255}, 'linear') end)
end

function Time:update(dt)
    self.clock_anim:update(dt)
end

function Time:draw()
    love.graphics.setColor(255, 255, 255, self.overlay_alpha)
    love.graphics.draw(night_overlay, 0, 0)
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.print("Time: " .. self.time, 10, 10)
    self.clock_anim:draw(400-103*0.25, 5, 0, 0.25, 0.25)
end
