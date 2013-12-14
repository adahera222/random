Entity = class('Entity')

function Entity:init(world, x, y, settings)
    self.id = getUID()
    self.dead = false
    self.world = world
    self.x = x
    self.y = y
    if settings then
        for k, v in pairs(settings) do self[k] = v end
    end
end
