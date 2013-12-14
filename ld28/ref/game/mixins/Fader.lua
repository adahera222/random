Fader = {
    faderInit = function(self, fade_in)
        self.fade_in = fade_in
        if fade_in then self.fade_alpha = 0 else self.fade_alpha = 255 end
    end,

    fadeIn = function(self, delay, duration, tween_function)
        self.timer:after(delay, function()
            self.timer:tween(duration, self, {fade_alpha = 255}, tween_function)
        end)
    end,

    fadeOut = function(self, delay, duration, tween_function)
        self.timer:after(delay, function()
            self.timer:tween(duration, self, {fade_alpha = 0}, tween_function)
            self.timer:after(duration, function() self.dead = true end)
        end)
    end,

    faderDraw = function(self)
        love.graphics.setColor(255, 255, 255, self.fade_alpha)
    end
}
