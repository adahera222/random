function dottedLine(x1, y1, x2, y2, size, interval)
    local size = size or 5
    local interval = interval or 2

    local dx = (x1-x2)*(x1-x2)
    local dy = (y1-y2)*(y1-y2)
    local length = math.sqrt(dx+dy)
    local t = size/length

    for i = 1, math.floor(length/size) do
        if i % interval == 0 then
            love.graphics.line(x1+t*(i-1)*(x2-x1), y1+t*(i-1)*(y2-y1), 
                               x1+t*i*(x2-x1), y1+t*i*(y2-y1))
        end
    end
end

function arrowedLine(x1, y1, x2, y2, name, both, length)
    love.graphics.line(x1, y1, x2, y2)
    local sin, cos = math.sin, math.cos
    local r = 4
    local angle = math.atan2(y2-y1, x2-x1)

    local find_points = 
        function(c, angle)
            local p1x = c.x + cos(angle)*2*r
            local p1y = c.y + sin(angle)*2*r
            local p2x = c.x + cos(angle-math.pi/2)*r
            local p2y = c.y + sin(angle-math.pi/2)*r
            local p3x = c.x + cos(angle+math.pi/2)*r
            local p3y = c.y + sin(angle+math.pi/2)*r
            return p1x, p1y, p2x, p2y, p3x, p3y
        end

    love.graphics.triangle('fill', find_points({x = x2, y = y2}, angle))
    if both then love.graphics.triangle('fill', find_points({x = x1, y = y1}, math.pi+angle)) end
    if name then
        local pfx = x2 + cos(angle)*2.5*r
        local pfy = y2 + sin(angle)*2.5*r
        love.graphics.print(name, pfx, pfy-8)
    end
    if length then 
        local pix = x1 + cos(math.pi+angle)*2*r
        local piy = y1 + sin(math.pi+angle)*2*r 
        local p1x = pix + cos(math.pi+angle-math.pi/2)*1.2*r
        local p1y = piy + sin(math.pi+angle-math.pi/2)*1.2*r
        local p2x = pix + cos(math.pi+angle+math.pi/2)*1.2*r
        local p2y = piy + sin(math.pi+angle+math.pi/2)*1.2*r
        love.graphics.line(p1x, p1y, p2x, p2y)

        local pfx = x2 + cos(angle)*2*r
        local pfy = y2 + sin(angle)*2*r 
        local p1x = pfx + cos(angle-math.pi/2)*1.2*r
        local p1y = pfy + sin(angle-math.pi/2)*1.2*r
        local p2x = pfx + cos(angle+math.pi/2)*1.2*r
        local p2y = pfy + sin(angle+math.pi/2)*1.2*r
        love.graphics.line(p1x, p1y, p2x, p2y)
    end
end

function love.load()
    w = 300
    h = 240
    love.graphics.setMode(w, h, false, false, 8)
    font = love.graphics.newFont('LinLibertine_RB.ttf', 16)
    love.graphics.setFont(font)
    canvas = love.graphics.newCanvas(w, h)

    -- Implement FXAA when I actually have the MENTAL POWER to understand it...
    -- Seems pretty cool!
    -- fxaa = love.graphics.newPixelEffect[[]]
end

function love.draw()
    love.graphics.setBackgroundColor(255, 255, 255)
    love.graphics.setColor(0, 0, 0)
    love.graphics.setLineStyle('smooth')
    OBB()

    --[[
    canvas:renderTo(function() OBB() end)
    love.graphics.draw(canvas, 0, 0)
    ]]--
end

function love.keypressed(key)
    if key == 'p' then

    end
end

function dotProductProjection()
    local xi, yi = w/12, h-h/4
    local xf, yf = 2*w/3, h/6
    local theta = math.atan2(yf-yi, xf-xi)
    arrowedLine(xi, yi, 8.75*w/10, yi, 'u')
    arrowedLine(xi, yi, xf, yi)
    arrowedLine(xi, yi, xf, yf, 'v') 
    dottedLine(xf+6, yf-7, xf+6, yi, 1, 5) 
    love.graphics.arc('line', xi, yi, 35, 0, theta)
    love.graphics.print('a', xi+38, yi-24)
    arrowedLine(xi+8, yi+10, xf-2, yi+10, nil, true, true)
    arrowedLine(xi, yi-12, xf-8, yf-8, nil, true, true)
    love.graphics.print('|d| = u v/||u|| = ||v||cos(a)', xi, yi+20)
    love.graphics.circle('fill', xi+46, yi+30, 1)
    love.graphics.print('||v||', xi+58, yi-104)
end

function AABBVoronoiRegions()
    local xi, yi = 2*w/10, 2*h/10
    local xf, yf = 8*w/10, 8*h/10
    love.graphics.rectangle('line', xi, yi, xf-xi, yf-yi)
    dottedLine(xi, yi, xi, yi-w/10, 1, 5)
    dottedLine(xi, yi, xi-w/10, yi, 1, 5)
    dottedLine(xf, yi, xf+w/10, yi, 1, 5)
    dottedLine(xf, yi, xf, yi-w/10, 1, 5)
    dottedLine(xi, yf, xi, yf+w/10, 1, 5)
    dottedLine(xi, yf, xi-w/10, yf, 1, 5)
    dottedLine(xf, yf, xf+w/10, yf, 1, 5)
    dottedLine(xf, yf, xf, yf+w/10, 1, 5)
    love.graphics.print('E', w/2-4, yf+12)
    love.graphics.print('E', w/2-4, yi-28)
    love.graphics.print('E', xi-24, h/2-12)
    love.graphics.print('E', xf+12, h/2-12)
    love.graphics.print('V', xi-24, yi-28)
    love.graphics.print('V', xi-24, yf+12)
    love.graphics.print('V', xf+12, yi-28)
    love.graphics.print('V', xf+12, yf+12)
end

function OBB()
    local xi, yi = 2*w/10, 2*h/10
    local xf, yf = 8*w/10, 8*h/10
    love.graphics.circle('fill', w/2, h/2, 3)
    love.graphics.push()
    love.graphics.translate(w/2, h/2)
    love.graphics.rotate(-math.pi/4)
    love.graphics.translate(-w/2, -h/2)
    love.graphics.rectangle('line', xi, yi, xf-xi, yf-yi)
    arrowedLine(w/2, h/2, w/2+w/10, h/2)
    arrowedLine(w/2, h/2, w/2, h/2-w/10)
    arrowedLine(w/2, yf+10, xf-8, yf+10, nil, true, true)
    arrowedLine(xi-10, h/2, xi-10, yi+8, nil, true, true)
    love.graphics.pop()
    love.graphics.print('C', w/2+2, h/2+2)
    love.graphics.print('u', w/2+30, h/2-30) 
    love.graphics.print('0', w/2+39, h/2-22, 0, 0.65, 0.65)
    love.graphics.print('u', w/2-43, h/2-30)
    love.graphics.print('1', w/2-35, h/2-22, 0, 0.65, 0.65)
    love.graphics.print('e', w/2+3*w/10-4, h/2+28)
    love.graphics.print('0', w/2+3*w/10-4+7, h/2+28+8, 0, 0.65, 0.65)
    love.graphics.print('e', w/2-4*w/10+12, h/2+42)
    love.graphics.print('1', w/2-4*w/10+12+6, h/2+42+8, 0, 0.65, 0.65)
end
