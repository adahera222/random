Entity = class('Entity')

function Entity:initialize(name)
    self.id = getUID()
    self.name = name or tostring(id)
    self.dead = false
    self.sleeping = false
end

function Entity:update(dt)
    if self.dead then beholder.trigger('REMOVE ME', self.id) end
end
