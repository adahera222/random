World = class('World')

function World:initialize()
    beholder.observe('REMOVE ME', function(id) self:remove(id) end)
    beholder.observe('ADD OBJECT', function(object) self:add(object) end)

    love.physics.setMeter(32)
    self.world = love.physics.newWorld(0, 0)
    self.renderer = Renderer()
    self.objects = {}
    self.map = Map(self.world)
    self.player = Player(self.world, self.map.current_block.x*1024+512, self.map.current_block.y*1024+512)
    self.renderer:add(self.player)

    -- Day/night cycle
    self.time = Time(2)
end

function World:add(object)
    self.objects[object.name] = object
    self.renderer:add(object)
end

function World:remove(id)
    self.objects[tostring(id)] = nil
    self.renderer:remove(id)
end

function World:update(dt)
    self.world:update(dt)
    self.time:update(dt)
    self.player:update(dt)
    local abs = math.abs
    local x, y = self.player.body:getPosition()
    for _, object in pairs(self.objects) do 
        local ox, oy = object.body:getPosition()
        if abs(ox-x) <= 1024 and abs(oy-y) <= 1024 then
            object.sleeping = false
            object:update(dt) 
        else object.sleeping = true end
    end
    self.map:update(x, y, dt)
    self.renderer:update(dt, Vector(self.player.body:getPosition()))
end

function World:draw()
    self.renderer.camera:attach()
    self.map:draw()
    self.renderer:draw()
    self.renderer.camera:detach()
    self.time:draw()
end
