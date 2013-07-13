Block = class('Block')

local sub_block = struct('source', 'x', 'y')

function Block:initialize(source, x, y)
    self.x = x
    self.y = y
    self.sub_blocks = {}
    table.insert(self.sub_blocks, sub_block(source, x, y)) 
    table.insert(self.sub_blocks, sub_block(source, x+512, y)) 
    table.insert(self.sub_blocks, sub_block(source, x, y+512)) 
    table.insert(self.sub_blocks, sub_block(source, x+512, y+512)) 
end

function Block:draw()
    for i, sb in ipairs(self.sub_blocks) do
        love.graphics.draw(sb.source, sb.x, sb.y)
        love.graphics.print(tostring(i), sb.x+10, sb.y+10)
    end
end
