Collector = {
    collectorInit = function(self)
        self.messages = {}
        self.timers = {}
        self.tweens = {}
    end,

    collectorAddMessage = function(self, message_id)
        table.insert(self.messages, message_id)
    end,

    collectorAddTimer = function(self, timer_id)
        table.insert(self.timers, timer_id)
    end,

    collectorAddTween = function(self, tween_id)
        table.insert(self.tweens, tween_id)
    end,

    collectorDestroy = function(self)
        for _, m in ipairs(self.messages) do beholder.stopObserving(m) end
        for _, t in ipairs(self.timers) do chrono:cancel(t) end
        for _, t in ipairs(self.tweens) do tween.stop(t) end
    end
}
