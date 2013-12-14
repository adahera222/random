local Shake = struct('creation_time', 'id', 'intensity', 'duration')

CameraShake = {
    cameraShakeInit = function(self)
        self.uid = 0
        self.p = Vector(self.camera:pos())
        self.shakes = {}
        self.shake_intensity = 0
    end,

    cameraShakeUpdate = function(self, dt)
        self.shake_intensity = 0
        self.p = Vector(self.camera:pos())
        for _, shake in ipairs(self.shakes) do
            if love.timer.getTime() > shake.creation_time + shake.duration then
                self:cameraShakeRemove(shake.id)
            else self.shake_intensity = self.shake_intensity + shake.intensity end
        end

        self.shake_intensity = math.min(self.shake_intensity, 10)
        self.camera:lookAt(self.p.x + math.prandom(-self.shake_intensity, self.shake_intensity),
                           self.p.y + math.prandom(-self.shake_intensity, self.shake_intensity))
        if self.shake_intensity == 0 then self.camera:lookAt(self.p.x, self.p.y) end
    end,

    cameraShakeAdd = function(self, intensity, duration)
        self.uid = self.uid + 1
        table.insert(self.shakes, Shake(love.timer.getTime(), self.uid, intensity, duration))
    end,

    cameraShakeRemove = function(self, id)
        table.remove(self.shakes, findIndexByID(self.shakes, id))
    end
}
