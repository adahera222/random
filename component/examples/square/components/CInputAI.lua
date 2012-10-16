require 'base/Component'

-- Computes AI (for now) and sends messages to CMovement.
CInputAI = class('CInputAI', Component)

-- Messages sent -> CMovement:
-- 'MOVE LEFT':         moves left (-x, constant), time dependant
-- 'MOVE RIGHT':        moves right (+x, constant), time dependant
-- 'MOVE UP':           moves up (constant, +y), time dependant
-- 'MOVE DOWN':         moves down (constant, -y), time dependant



-- componentID: component name: string
function CInputAI:initialize(componentID)
    Component.initialize(self, 'CInput', componentID)

    self.direction_change_t = 0 -- auxiliary counter
    self.direction_change_delay = 0.2 -- changes direction every n seconds
    self.directions = {'left', 'right', 'up', 'down'}
    self.direction = self.directions[math.random(1, #self.directions)] 
end

function CInputAI:update(dt)
    local id = self.ownerGO.id_type

    -- Changes direction every direction_change_delay seconds.
    self.direction_change_t = self.direction_change_t + dt
    if self.direction_change_t >= self.direction_change_delay then
        self.direction = self.directions[math.random(1, #self.directions)]
        self.direction_change_t = 0
    end

    if self.direction == 'left' then beholder.trigger('MOVE LEFT_' .. id) end
    if self.direction == 'right' then beholder.trigger('MOVE RIGHT_' .. id) end
    if self.direction == 'up' then beholder.trigger('MOVE UP_' .. id) end
    if self.direction == 'down' then beholder.trigger('MOVE DOWN_' .. id) end
end

