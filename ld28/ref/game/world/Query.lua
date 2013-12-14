Query = {
    queryInit = function(self)

    end,

    queryName = function(self, name, type)
        for _, group in ipairs(self.groups) do
            if group.name == type then
                for _, object in ipairs(group:getEntities()) do
                    if object.name == name then
                        return object
                    end
                end
            end
        end
    end,

    queryAreaCircle = function(self, position, radius, object_types)
        local objects = {}
        for _, type in ipairs(object_types) do
            for _, group in ipairs(self.groups) do
                if group.name == type then
                    for _, object in ipairs(group:getEntities()) do
                        local x, y = object.body:getPosition()
                        local dx, dy = math.abs(position.x - x), math.abs(position.y - y)
                        local distance = math.sqrt(dx*dx + dy*dy)
                        if distance < radius then 
                            table.insert(objects, object)
                        end
                    end
                end
            end
        end
        return objects
    end,

    queryAreaRectangle = function(self, position, w, h, object_types)
        local objects = {}
        for _, type in ipairs(object_types) do
            for _, group in ipairs(self.groups) do
                if group.name == type then
                    for _, object in ipairs(group:getEntities()) do
                        local x, y = object.body:getPosition()
                        local dx, dy = math.abs(position.x - x), math.abs(position.y - y)
                        if dx <= object.w/2 + w/2 and dy <= object.h/2 + h/2 then
                            table.insert(objects, object)
                        end
                    end
                end
            end
        end
        return objects
    end,

    applyAreaRectangle = function(self, position, w, h, object_types, action)
        local objects = self:queryAreaRectangle(position, w, h, object_types)
        if #objects > 0 then
            for _, object in ipairs(objects) do
                action(object)
            end
        end
    end
}

