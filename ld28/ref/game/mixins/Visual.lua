-- Requires PhysicsRectangle
Visual = {
    visualInit = function(self, visual, offset, wiggle)
        self.visual = visual
        self.wiggle = wiggle
        self.offset = offset or Vector(0, 0)
    end,

    visualDraw = function(self)
        if not self.visual then return end
        local x, y = self.body:getPosition()
        local w, h = self.visual:getWidth(), self.visual:getHeight()
        pushRotate(x, y, self.body:getAngle())
        x, y = x - w/2 - self.offset.x, y - h/2 - self.offset.y
        if self.wiggle then love.graphics.draw(self.visual, x + self.wiggle_direction*self.wiggle_x, y)
        else love.graphics.draw(self.visual, x, y) end
        love.graphics.pop()
    end
}
