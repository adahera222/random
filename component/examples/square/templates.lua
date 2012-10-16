-- Component templates:
component_templates = {}

-- CMovement:
component_templates.CMovement = {}
component_templates.CMovement.player = {
    {width, 32}, {height, 32},
    {position, {400, 300}},
    {velocity, {0, 0}}, {acceleration, {1000, 1000}},
    {max_velocity, {200, 200}}, {damping, 0.91}
}
component_templates.CMovement.block = {
    {width, 32}, {height, 32},
    {position, {0, 0}},
    {velocity, {0, 0}}, {acceleration, {500, 500}},
    {max_velocity, {100, 100}}, {damping, 0.91}
}

-- CInputPlayer:
component_templates.CInputPlayer = {}
component_templates.CInputPlayer.player = {}

-- CInputAI
component_templates.CInputAI = {}
component_templates.CInputAI.player = {}
component_templates.CInputAI.block = {}



-- Game object templates:
go_templates = {}

-- player:
go_templates.player = {
    name = 'player',
    components = {'CMovement', 'CInputAI'},
    attributes = {'collidable', 'renderable'}
}

-- block:
go_templates.block = {
    name = 'block',
    components = {'CMovement', 'CInputAI'}, 
    attributes = {'collidable', 'renderable', 'static'}, 
    extra = {
        function(go) 
            local mov = go:getGOC('CMovement')
            mov.p.x = math.random(0, 800)
            mov.p.y = math.random(0, 640)
        end
    }
}
