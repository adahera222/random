Timer = {
    timerInit = function(self)
        self.timer = GTimer.new()
    end,
    
    timerUpdate = function(self, dt)
        self.timer:update(dt)
    end,

    timerDestroy = function(self)
        self.timer:clear()
        self.timer = nil
    end
}
