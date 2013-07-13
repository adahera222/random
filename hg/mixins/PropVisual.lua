PropVisual = {
    visualInit = function(self, animations, offset_x, offset_y)
        self.animations = {}
        for k, anim in pairs(animations) do
            self.animations[k] = newAnimation(anim.source, anim.w, anim.h, anim.delay, 0)
        end
        self.offset_x = offset_x
        self.offset_y = offset_y
    end,

    visualUpdate = function(self, dt)
        self.animations.idle:update(dt)
    end,

    visualDraw = function(self)
        local x, y = self.body:getPosition()
        x, y = x - self.w/2 - self.offset_x, y - self.h/2 - self.offset_y
        self.animations.idle:draw(x, y)
    end
}
