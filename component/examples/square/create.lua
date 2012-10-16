require 'base/GameObject'
require 'examples/square/templates'
require 'examples/square/components/init'

-- Common data used by multiple components.
local commons = {}

-- Unique id (for game objects) counter incremented before every object creation.
local uid_count = 0

local function loadResources()
    local image = love.graphics.newImage('examples/square/resources/square.png')
    commons.square_img = image
end

-- Creates a component and returns it.
-- component_name:      component name (class name):        string
-- name:                component name (id):                string
-- template:            template from component_templates:  table -> ...
function createComponent(component_name, name, template)
    local parameters = {} 

    if template then
        for _, v in ipairs(template) do
            table.insert(parameters, v[2])
        end
    end

    local component = assert(loadstring("return " .. component_name ..
    ":new(...)"))(name, unpack(parameters))
    return component
end

loadResources()

-- Creates a game object and returns it.
-- name:                template/object name:               string
function createGameObject(name)
    uid_count = uid_count + 1
    local template = go_templates[name]
    local go = GameObject:new(uid_count)

    -- Creates and sets components.
    for _, component in ipairs(template.components) do
        local component_template = component_templates[component][name]
        if #component_template == 0 then component_template = nil end

        local new_component = createComponent(component,
        component .. template.name, component_template)

        go:setGOC(new_component)
    end

    -- Sets attributes.
    for _, attribute in ipairs(template.attributes) do
        go.attributes[attribute] = true
    end

    -- Executes extra setup steps.
    if template.extra then
        for _, extra in ipairs(template.extra) do extra(go) end
    end

    return go
end
