B2Entity = class('B2Entity')

function B2Entity:initialize(world, type, shape_type, ...)
    local args = {...}
    shape_type = shape_type:lower()
    self.shapes = {}
    self.fixtures = {}

    if shape_type == "edge" then
        self.body = love.physics.newBody(world, 0, 0, type or 'dynamic')        
        local shape = love.physics.newEdgeShape(unpack(args))
        local fixture = love.physics.newFixture(self.body, shape, 1)
        table.insert(self.shapes, shape)
        table.insert(self.fixtures, fixture)

    elseif shape_type == "chain" then

    elseif shape_type == "polygon" then
        self.body = love.physics.newBody(world, args[1], args[2], type or 'dynamic')        
        local shape = love.physics.newPolygonShape()
        local fixture = love.physics.newFixture(self.body, shape, 1)
        table.insert(self.shapes, shape)
        table.insert(self.fixtures, fixture)

    elseif shape_type == "rectangle" then

    elseif shape_type == "circle" then

    else error("Invalid shape type.") end
end

function B2Entity:draw()

end
