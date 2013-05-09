-- Get red channel
red = love.graphics.newPixelEffect[[
    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        vec4 c = Texel(tex, tc);
        return vec4(c.r, 0, 0, c.a);
    }
]]

-- Get green channel
green = love.graphics.newPixelEffect[[
    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        vec4 c = Texel(tex, tc);
        return vec4(0, c.g, 0, c.a);
    }
]]

-- Get blue channel
blue = love.graphics.newPixelEffect[[
    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        vec4 c = Texel(tex, tc);
        return vec4(0, 0, c.b, c.a);
    }
]]

-- Screen mode blending
screen = love.graphics.newPixelEffect[[
    extern Image img;
    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        vec4 base = Texel(tex, tc);
        vec4 blend = Texel(img, tc);
        return vec4(1-((1-base)*(1-blend)));
    }
]]

-- Simple 3x3 box blur
blur = love.graphics.newPixelEffect[[
    extern vec2 image_size;
    extern number intensity = 1.0;

    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        vec2 offset = vec2(1.0)/image_size;
        color = Texel(tex, tc);

        color += Texel(tex, tc + intensity*vec2(-offset.x, offset.y));
        color += Texel(tex, tc + intensity*vec2(0.0, offset.y));
        color += Texel(tex, tc + intensity*vec2(offset.x, offset.y));

        color += Texel(tex, tc + intensity*vec2(-offset.x, 0.0));
        color += Texel(tex, tc + intensity*vec2(0.0, 0.0));
        color += Texel(tex, tc + intensity*vec2(offset.x, 0.0));

        color += Texel(tex, tc + intensity*vec2(-offset.x, -offset.y));
        color += Texel(tex, tc + intensity*vec2(0.0, -offset.y));
        color += Texel(tex, tc + intensity*vec2(offset.x, -offset.y));

        return color/9.0;
    }
]]

function love.load()
    local w, h = love.graphics.getWidth(), love.graphics.getHeight()
    gaben = love.graphics.newImage('gaben.jpg')
end

function love.update(dt)

end

function love.draw()

end
