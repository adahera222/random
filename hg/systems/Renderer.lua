Renderer = class('Renderer')

function Renderer:initialize()
    self.camera = Camera()
    self.objects = {}
end

function Renderer:add(object)
    table.insert(self.objects, object)
end

function Renderer:remove(id)
    for i, object in ipairs(self.objects) do
        if object.id == id then
            table.remove(self.objects, i)
            return
        end
    end
end

function Renderer:sort()
    table.sort(self.objects, function(object1, object2)
        if not object1.sleeping or not object2.sleeping then
            local x1, y1 = object1.body:getPosition()
            local x2, y2 = object2.body:getPosition()
            return y1 < y2 
        end
    end)
end

function Renderer:update(dt, center)
    self:sort()
    self.camera:lookAt(center.x, center.y)
end

function Renderer:draw()
    for _, object in ipairs(self.objects) do 
        if not object.sleeping then object:draw() end
    end
end

