-- The problem:
-- Lua has a problem whenever you want to define a C-like struct.
-- For instance, when I want to define a point structure without having 
-- to define a new class I can create a table like so:
--
-- {x = number, y = number}
--
-- And a function that does something to points can use them like this:
--
-- function dist(p1, p2)
--   local dx, dy = p1.x - p2.x, p1.y - p2.y
--   return math.sqrt(dx*dx + dy*dy)
-- end
--
-- The problem with this is that whenever I have to create a new point
-- I have to create a naked table like in line 6 and it feels "loose".
-- There's no indication of what type that table is before I have to
-- read its contents and there's also no feedback when I try to access
-- p1.z on dist, for instance.
--

-- The solution:
-- An ideal solution would allow me to detect access on undefined 
-- fields and to specify a type for the struct I am creating, like this:
--
-- local Point = struct('x', 'y')
-- local p1 = Point(1, 1)       -- OK
-- local p2 = Point(1, 2, 3)    -- error, unknown 3rd argument
-- print(p1.x) -- OK
-- print(p1.z) -- error

function struct(fields)
    local struct_table = setmetatable({}, {
        __index = 
            function(struct_table, key)
                for _, field in ipairs(fields) do
                    if field == key then return struct_table[key] end
                end
                error("Unknown field '" .. key .. "'")
            end,

        __newindex =
            function(struct_table, key, value)
                for _, field in ipairs(fields) do
                    if field == key then 
                        rawset(struct_table, key, value) 
                        return
                    end
                end
                error("Unknown field '" .. key .. "'")
            end,

        __call = 
            function(struct_table, ...)
                for i, arg in ipairs({...}) do
                    if fields[i] then struct_table[fields[i]] = arg 
                    else error("Unknown argument #" .. tostring(i)) end 
                end
                return struct_table
            end
    })
    return struct_table
end

local Point = struct({'x', 'y'})
local p1 = Point(1, 2)
local p2 = Point(3, 4)
print(p1.x)
print(p1.y)
print(p2.x)
print(p2.y)
