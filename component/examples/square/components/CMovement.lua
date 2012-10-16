require 'base/Component'

-- Handles movement of the owner mov_component (velocity).
CMovement = class('CMovement', Component)

-- Messages received <- AI/Input 
-- 'MOVE LEFT':         moves left (-x, constant), time dependant
-- 'MOVE RIGHT':        moves right (+x, constant), time dependant
-- 'MOVE UP':           moves up (constant, +y), time dependant
-- 'MOVE DOWN':         moves down (constant, -y), time dependant

-- <- SCollision
-- 'DISPLACE':
--  dx:                 displacement vector, component x:           number
--  dy:                 displacement vector, component y:           number



-- componentID:         component name:                 string
-- width:               static width:                   number
-- height:              static height:                  number
-- position:            current x, y position:          table -> number, number
-- velocity:            current x, y velocity:          table -> number, number
-- acceleration:        current x, y acceleration:      table -> number, number
-- max_velocity:        maximum x, y velocity:          table -> number, number
-- damping:             velocity decrease over time:    number: [0, 1]
function CMovement:initialize(componentID, width, height, position, velocity,
    acceleration, max_velocity, damping)
    Component.initialize(self, 'CMovement', componentID)

    -- attributes
    self.p = {x = position[1], y = position[2]}
    self.v = {x = velocity[1], y = velocity[2]}
    self.w = width
    self.h = height
    self.a = {x = acceleration[1], y = acceleration[2]}
    self.max_v = {x = max_velocity[1], y = max_velocity[2]}
    self.dmp = damping

    -- control
    self.moving = {
        x = {left = false, right = false},
        y = {up = false, down = false}
    }
end

function CMovement:observe()
    local id = self.ownerGO.id_type

    -- <- CInput
    beholder.observe('MOVE LEFT_' .. id,
    function() self.moving.x.left = true end) 
    beholder.observe('MOVE RIGHT_' .. id,
    function() self.moving.x.right = true end)
    beholder.observe('MOVE UP_' .. id,
    function() self.moving.y.up = true end)
    beholder.observe('MOVE DOWN_' .. id,
    function() self.moving.y.down = true end)

    -- <- SCollision
    beholder.observe('DISPLACE_' .. id,
    function(dx, dy) displace(self, dx, dy) end)
end

function CMovement:update(dt)
    self:movement(dt)
    self:position(dt)
end

-- Updates position using velocity.
function CMovement:position(dt)
    self.p.x = self.p.x + self.v.x*dt
    self.p.y = self.p.y + self.v.y*dt
end

-- Handles movement in four directions.
-- Updates velocity using acceleration ([-max_v, max_v]).
function CMovement:movement(dt)
    if self.moving.x.left then
        self.v.x = math.max(self.v.x - self.a.x*dt, -self.max_v.x)
    end

    if self.moving.x.right then
        self.v.x = math.min(self.v.x + self.a.x*dt, self.max_v.x)
    end

    if self.moving.y.up then
        self.v.y = math.max(self.v.y - self.a.y*dt, -self.max_v.y)
    end

    if self.moving.y.down then
        self.v.y = math.min(self.v.y + self.a.y*dt, self.max_v.y)
    end

    -- Apply linear damping horizontally (x component) if neither
    -- left or right keys are pressed.
    if not self.moving.x.left and not self.moving.x.right then
        self.v.x = self.v.x * self.dmp
    end

    -- Apply linear damping vertically (y component) if neither
    -- up or down keys are pressed.
    if not self.moving.y.up and not self.moving.y.down then
        self.v.y = self.v.y * self.dmp
    end

    -- Resets the moving state variables. They will be set again automagically
    -- (before this component is called to be updated) by beholder.observe 
    -- if the proper event is triggered by a CInput component.
    self.moving.x.left = false
    self.moving.x.right = false
    self.moving.y.up = false
    self.moving.y.down = false
end

function displace(mov_component, dx, dy) 
    if not mov_component.ownerGO.attributes.static then
        mov_component.p.x = mov_component.p.x + dx
        mov_component.p.y = mov_component.p.y + dy
    end
end
