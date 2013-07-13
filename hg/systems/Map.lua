Map = class('Map')

function Map:initialize(world)
    self.world = world
    self.blocks = {}
    for i = 1, 1000 do 
        self.blocks[i] = {}
        for j = 1, 1000 do
            self.blocks[i][j] = 0
        end
    end
    self.blocks[500][500] = Block(grass, 500*1024, 500*1024)

    self.current_blocks = {}
    for i = 1, 3 do
        self.current_blocks[i] = {}
        for j = 1, 3 do
            self.current_blocks[i][j] = 0
        end
    end

    self.current_block = Vector(500, 500)
    self.current_blocks[2][2] = self.blocks[self.current_block.x][self.current_block.y]
    self:populateBlockWithProps(500*1024, 500*1024, 10)
    self:updateCurrentBlocks()
end

function Map:populateBlockWithProps(x, y, n)
    local prop_types = {'rock', 'boulder', 'bush', 'tree'}
    for i = 1, n do
        beholder.trigger('ADD OBJECT', Prop(self.world, math.random(x, x+1024), math.random(y, y+1024), prop_types[math.random(1, #prop_types)]))
    end
end

function Map:updateCurrentBlocks()
    for i = -1, 1, 1 do
        for j = -1, 1, 1 do
            if i ~= 0 or j ~= 0 then
                if self.blocks[self.current_block.x+i][self.current_block.y+j] == 0 then
                    local block = Block(grass, (self.current_block.x+i)*1024, (self.current_block.y+j)*1024)
                    self.blocks[self.current_block.x+i][self.current_block.y+j] = block
                    self:populateBlockWithProps(block.x, block.y, 10)
                    self.current_blocks[2+i][2+j] = self.blocks[self.current_block.x+i][self.current_block.y+j]
                    -- print("GENERATING " .. tostring(self.current_block.x+i) .. " " .. tostring(self.current_block.y+j)) 
                else self.current_blocks[2+i][2+j] = self.blocks[self.current_block.x+i][self.current_block.y+j] end
            end
        end
    end
end

function Map:update(player_x, player_y, dt)
    self.current_block = Vector(math.floor(player_x/1024), math.floor(player_y/1024))
    self.current_blocks[2][2] = self.blocks[self.current_block.x][self.current_block.y]
    self:updateCurrentBlocks()
end

function Map:draw()
    for i = 1, 3 do for j = 1, 3 do self.current_blocks[i][j]:draw() end end
end
