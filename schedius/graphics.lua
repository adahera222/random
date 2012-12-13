-- Additional graphics effects/primitives not supported by LÖVE:
-- * Dotted lines for all basic shapes;

local graphics = {}

function graphics.dotted_line(x1, y1, x2, y2, strip_size, interval)
    local abs = math.abs
    local dx = abs(x1-x2)*abs(x1-x2)
    local dy = abs(y1-y2)*abs(y1-y2)
    local length = math.sqrt(dx + dy)
    local t = strip_size/length

    for i = 1, math.floor(length/strip_size) do
        if i % interval == 0 then
            love.graphics.line(x1+t*(i-1)*(x2-x1), y1+t*(i-1)*(y2-y1), 
                               x1+t*i*(x2-x1), y1+t*i*(y2-y1))
        end
    end
end

return graphics
