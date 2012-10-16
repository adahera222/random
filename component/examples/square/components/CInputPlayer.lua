require 'base/Component'

-- Handles player input (keyboard, gamepad).
CInputPlayer = class('CInputPlayer', Component)

-- Messages sent -> CMovement:
-- 'MOVE LEFT':         moves left (-x, constant), time dependant
-- 'MOVE RIGHT':        moves right (+x, constant), time dependant
-- 'MOVE UP':           moves up (constant, +y), time dependant
-- 'MOVE DOWN':         moves down (constant, -y), time dependant



-- componentID: component name: string
function CInputPlayer:initialize(componentID)
    Component.initialize(self, 'CInput', componentID)
end

function CInputPlayer:update(dt)
    local id = self.ownerGO.id_type

    if love.keyboard.isDown('left') then beholder.trigger('MOVE LEFT_' .. id) end
    if love.keyboard.isDown('right') then beholder.trigger('MOVE RIGHT_' .. id) end
    if love.keyboard.isDown('up') then beholder.trigger('MOVE UP_' .. id) end
    if love.keyboard.isDown('down') then beholder.trigger('MOVE DOWN_' .. id) end
end
