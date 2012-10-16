require 'lib/middleclass'

-- Each object contains only one component of familyID type.
-- ownerGO has a reference to the parent object and is set on creation.
Component = class('Component')

-- familyID:        string
-- componentID:     string
function Component:initialize(familyID, componentID)
    self.familyID = familyID
    self.componentID = componentID
    self.ownerGO = nil
end

function Component:isIDOwnerGO(id)
    if id == self.ownerGO.id_type then return true
    else return false end
end
