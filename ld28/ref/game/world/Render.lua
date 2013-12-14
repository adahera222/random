Render = {
    renderInit = function(self)
        self.camera = Camera()
        self.camera_v = Vector(0, 0)
        self.camera_v_multiplier = 0.2
        self.game_width = game_width
        self.game_height = game_height
    end,

    renderUpdate = function(self, dt, follow)
        local x, y = self.camera:pos()
        self.camera_v = Vector(follow.x - x, follow.y - y)
        self.camera:move(self.camera_v.x*self.camera_v_multiplier, self.camera_v.y*self.camera_v_multiplier)
    end,

    renderAttach = function(self)
        self.camera:attach()
    end,

    renderDetach = function(self)
        self.camera:detach()
    end,

    renderDraw = function(self)
        for _, group_ro in ipairs(groups_render_order) do
            for _, group in ipairs(self.groups) do
                if group.name == group_ro then
                    group:draw()
                end
            end
        end
    end
}
