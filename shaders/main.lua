function love.load()
    b = love.graphics.newImage('gaben.jpg')

    red = love.graphics.newPixelEffect[[
        vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
            vec4 c = Texel(tex, tc);
            return vec4(c.r, 0, 0, c.a);
        }
    ]]
end

function love.update(dt)
    
end

function love.draw()
    love.graphics.setPixelEffect(red)
    love.graphics.draw(b, 0, 0, 0, 0.5, 0.5)
end

