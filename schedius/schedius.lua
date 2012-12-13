-- Template configuration -- Edit this if you want to change default values
-- You can also add new types like huge = 1920 (instead of changing big)...
--
-- Image sizes: number
sizes = {
    small   = 320,
    medium  = 640,
    big     = 800
}

-- Colors: {r, g, b} - table: number
colors = {
    white   = {255, 255, 255},
    black   = {0, 0, 0}
}

-- Schedius -- DO NOT EDIT THIS
--
schedius = {}
schedius.graphics = require 'graphics'

-- All variables defined in file should be accounted for as 
-- schedius.variable_name. If a variable is left out in the 
-- image specification file then schedius.variable_name will 
-- be set to 'None' or a default value.
function schedius.load(file)
    dofile(file)

    -- Basic configurations
    schedius.width = sizes[width] or 320 
    schedius.height = sizes[height] or 320 
    schedius.background_color = colors[background_color] or {255, 255, 255}
    schedius.main_color = colors[main_color] or {0, 0, 0}

    -- Line
    schedius.lines = {}

    for _, line in pairs(lines) do
        table.insert(schedius.lines, {
                     a = {x = get_absolute_position('x', line.a.x),
                          y = get_absolute_position('y', line.a.y)},
                     b = {x = get_absolute_position('x', line.b.x),
                          y = get_absolute_position('y', line.b.y)},
                     dotted = line.dotted,
                     strip_size = line.strip_size or 4,
                     interval = line.interval or 3,
                     width = line.width or 1,
                     blur = line.blur,
                     alpha = line.alpha or 255})
    end
end

function get_absolute_position(axis, relative_position)
    if axis == 'x' then
        if type(relative_position) == 'number' then
            return relative_position*schedius.width
        else 
            if relative_position == 'center' then
                return schedius.width/2
            end
        end

    else 
        if type(relative_position) == 'number' then
            return relative_position*schedius.height
        else
            if relative_position == 'center' then
                return schedius.height/2
            end
        end
    end
end

-- Sets basic image configurations
function schedius.configure()
    love.graphics.setMode(schedius.width, schedius.height, false, false, 0)
    love.graphics.setBackgroundColor(unpack(schedius.background_color))
    love.graphics.setColor(unpack(schedius.main_color))
end

function schedius.draw()
    draw_lines()
end

function draw_lines()
    for _, line in ipairs(schedius.lines) do
        love.graphics.setLineWidth(line.width)
        love.graphics.setColor(schedius.main_color[1], 
                               schedius.main_color[2],
                               schedius.main_color[3], line.alpha)
        if line.dotted then
            schedius.graphics.dotted_line(line.a.x, line.a.y, 
                                          line.b.x, line.b.y,
                                          line.strip_size, line.interval)
        else
            love.graphics.line(line.a.x, line.a.y, line.b.x, line.b.y)
        end
    end
end
