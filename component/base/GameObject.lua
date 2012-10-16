require 'lib/middleclass'

GameObject = class('GameObject')

-- Components implement specific behaviour of an object.
-- i.e.: CMovement implements all methods and contains all attributes to handle
-- object movement in one way or another. CInputPlayer does the same but in regards
-- to player input (keyboard). Often components will need to communicate with each 
-- other and that is done by using a message passing system. In the case of 
-- CInputPlayer and CMovement, the former sends a message when a player presses a 
-- key and the latter will interpret that message and translate it into velocity
-- or position changes, therefore moving the entity.

-- Attributes represent specific states/attributes(!) of an object.
-- i.e.: An object can be collidable (meaning other entities can collide with
-- it), static (meaning it can't move) and poisoned (meaning it will take poison
-- damage over time). All those things are boolean attributes of an object and
-- as such they are better off being stored inside a table:
-- attributes["colliding"] = true, attributes["static"] = true and so on...
-- This is used to avoid creating empty components (with no attributes/methods)
-- that only serve as a check for the object's current state.

-- As a rule of thumb, functionalities (components) that have data or methods
-- should actually be created as components and functionalities (attributes) 
-- that have no data nor methods should be added as attributes.

-- id_type: this object's uid/name: string
function GameObject:initialize(id_type)
    self.id_type = id_type
    self.components = {}
    self.attributes = {}
end

function GameObject:__tostring()
    local str = self.id_type
    for _, component in ipairs(self.components) do
        str = str .. component.ownerGO.id_type
    end

    return str
end

-- Gets the component that has a matching familyID type.
-- familyID: string
-- returns: Component or nil 
function GameObject:getGOC(familyID)
    for _, component in ipairs(self.components) do
        if component.familyID == familyID then
            return component 
        end
    end

    return nil
end

-- Adds a new component to this entity's components list.
-- newGOC: a component to be added to this entity: Component
-- returns: boolean
function GameObject:setGOC(newGOC)

    -- doesn't add newGOC if there is another component of the same
    -- family already in this object's components list
    for _, component in ipairs(self.components) do
        if component.familyID == newGOC.familyID then
           return false
        end
    end

    newGOC.ownerGO = self

    -- Setup event listeners.
    if newGOC.observe then newGOC:observe() end

    table.insert(self.components, newGOC)
    return true
end

function GameObject:clearGOCs()
    self.components = {} 
end

function GameObject:update(dt)
    for _, component in ipairs(self.components) do
        if component.update then
            component:update(dt)
        end
    end
end

function GameObject:draw()
    for _, component in ipairs(self.components) do
        if component.draw then
            component:draw()
        end
    end
end
