Prop = class('Prop', Entity)

Prop:include(PhysicsRectangle)
Prop:include(Collector)
Prop:include(PropVisual)

function Prop:initialize(world, x, y, prop_type)
    Entity.initialize(self)
    self.type = prop_type
    if prop_type == 'bush' then 
        self:physicsRectangleInit(world, x, y, 'static', sizes[prop_type].w, sizes[prop_type].h, true)
    else self:physicsRectangleInit(world, x, y, 'static', sizes[prop_type].w, sizes[prop_type].h) end
    self:visualInit(prop_animations[prop_type], sizes[prop_type].offset_x, sizes[prop_type].offset_y)
end

function Prop:update(dt)
    Entity.update(self, dt)
    self:visualUpdate(dt)
end

function Prop:draw()
    self:visualDraw()
    self:physicsRectangleDraw()
end
