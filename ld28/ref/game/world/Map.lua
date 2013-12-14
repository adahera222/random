Map = {
    mapInit = function(self, name)
        self.name = name
        self.layout_data = {}
        self.width = nil
        self.height = nil
        self.tile_w = nil
        self.tile_h = nil
        self.offset = Vector(x, y)
        self:mapLoad()
    end,

    mapLoad = function(self)
        local data = require('resources/maps/' .. self.name)
        self.width = data.layers[1].width
        self.height = data.layers[1].height
        self.tile_w = data.tilesets[1].tilewidth
        self.tile_h = data.tilesets[1].tileheight
        for _, layer in ipairs(data.layers) do
            if layer.type == 'tilelayer' then
                for i = 1, self.height do
                    self.layout_data[i] = {}
                end
                local i, j = 1, 1
                for _, v in ipairs(layer.data) do
                    self.layout_data[i][j] = v
                    j = j + 1
                    if j > self.width then j = 1; i = i + 1 end
                end

            elseif layer.type == 'objectgroup' then
                for _, object in ipairs(layer.objects) do
                    if object.type == 'Solid' then
                        self:createToGroup('Solid', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height, grass = object.properties.grass})
                    elseif object.type == 'BreakableSolid' then
                        self:createToGroup('BreakableSolid', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'EnemyWall' then
                        self:createToGroup('EnemyWall',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'TNT' then
                        self:createToGroup('TNT', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'SpikedBall' then
                        self:createToGroup('SpikedBall', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y)
                    elseif object.type == 'Spikes' then
                        self:createToGroup('Spikes', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y)
                    elseif object.type == 'Ladder' then
                        self:createToGroup('Ladder', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'JumpingPad' then
                        self:createToGroup('JumpingPad', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y)
                    elseif object.type == 'ChainedSpikedBall' then
                        self:createToGroup('Solid',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height, visual = chain_base})
                        self:createToGroup('ChainedSpikedBall', 
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'MovingWall' then
                        self:createToGroup('MovingWall',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height, name = object.name .. self.id, hidden = object.properties.hidden,
                                           movement_direction = object.properties.movement_direction, spikes = object.properties.spikes,})
                    elseif object.type == 'Button' then
                        local triggerable_names = object.properties.triggerable_name
                        local triggerable_types = object.properties.triggerable_type
                        local names = {}
                        local types = {}
                        for name in string.gmatch(triggerable_names, "%S+") do table.insert(names, name .. self.id) end
                        for type in string.gmatch(triggerable_types, "%S+") do table.insert(types, type) end
                        self:createToGroup('Button',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height, triggerable_names = names, triggerable_types = types, base = object.properties.base})
                    elseif object.type == 'Trigger' then
                        local triggerable_names = object.properties.triggerable_name
                        local triggerable_types = object.properties.triggerable_type
                        local names = {}
                        local types = {}
                        for name in string.gmatch(triggerable_names, "%S+") do table.insert(names, name .. self.id) end
                        for type in string.gmatch(triggerable_types, "%S+") do table.insert(types, type) end
                        self:createToGroup('Trigger',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height, triggerable_names = names, triggerable_types = types})
                    elseif object.type == 'Rail' then
                        self:createToGroup('Rail',
                                           object.x+object.width/2+self.offset.x, object.y+object.height/2+self.offset.y,
                                          {w = object.width, h = object.height})
                    elseif object.type == 'MineCart' then
                        self:createToGroup('MineCart', object.x+self.offset.x, object.y+self.offset.y)
                    end
                end
            end
        end
    end,

    mapDraw = function(self)
        for i = 1, self.height do
            for j = 1, self.width do
                if self.layout_data[i][j] ~= 0 then
                    love.graphics.draw(tiles_data['temple_tiles'][self.layout_data[i][j]], 
                                      (j-1)*self.tile_w+self.offset.x, (i-1)*self.tile_h+self.offset.y)
                end
            end
        end
    end
}
