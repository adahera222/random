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

simple_blur = love.graphics.newPixelEffect[[
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

simple_sobel = love.graphics.newPixelEffect[[
    extern vec2 image_size;
    extern number intensity = 1.0;

    float lookup(Image tex, vec2 p, float dx, float dy) {
        vec4 color = Texel(tex, p + vec2(intensity*dx, intensity*dy)/image_size);
        return 0.2126*color.r + 0.7152*color.g + 0.0722*color.b;
    }

    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        float gx = 0.0;
        gx += -1.0*lookup(tex, tc, -1.0, -1.0);
        gx += -2.0*lookup(tex, tc, -1.0,  0.0);
        gx += -1.0*lookup(tex, tc, -1.0,  1.0);
        gx +=  1.0*lookup(tex, tc,  1.0, -1.0);
        gx +=  2.0*lookup(tex, tc,  1.0,  0.0);
        gx +=  1.0*lookup(tex, tc,  1.0,  1.0);

        float gy = 0.0;
        gy += -1.0*lookup(tex, tc, -1.0, -1.0);
        gy += -2.0*lookup(tex, tc,  0.0, -1.0);
        gy += -1.0*lookup(tex, tc,  1.0, -1.0);
        gy +=  1.0*lookup(tex, tc, -1.0,  1.0);
        gy +=  2.0*lookup(tex, tc,  0.0,  1.0);
        gy +=  1.0*lookup(tex, tc,  1.0,  1.0);

        float g = gx*gx + gy*gy;
        color = Texel(tex, tc);
        color += vec4(g, 0.0, g, 1.0);
        return color;
    }
]]

glassy_pixely = love.graphics.newPixelEffect[[
    vec4 effect(vec4 color, Image tex, vec2 tc, vec2 pc) {
        color = Texel(tex, tc);
        if (mod(pc.x, 3.0) == 0.5 && mod(pc.y, 3.0) == 0.5) { // mid mid 
        } else if (mod(pc.x+1, 3.0) == 0.5 && mod(pc.y-1, 3.0) == 0.5) { // left up
            color = vec4(color.r-0.039, color.g-0.039, color.b-0.039, 1.0); 
        } else if (mod(pc.x+1, 3.0) == 0.5 && mod(pc.y, 3.0) == 0.5) { // left mid
        } else if (mod(pc.x+1, 3.0) == 0.5 && mod(pc.y+1, 3.0) == 0.5) { // left down
        } else if (mod(pc.x, 3.0) == 0.5 && mod(pc.y-1, 3.0) == 0.5) { // mid up
            color = vec4(color.r-0.039, color.g-0.039, color.b-0.039, 1.0); 
        } else if (mod(pc.x, 3.0) == 0.5 && mod(pc.y+1, 3.0) == 0.5) { // mid down
            color = vec4(color.r-0.1568, color.g-0.1568, color.b-0.1568, 1.0); 
        } else if (mod(pc.x-1, 3.0) == 0.5 && mod(pc.y-1, 3.0) == 0.5) { // right up
        } else if (mod(pc.x-1, 3.0) == 0.5 && mod(pc.y, 3.0) == 0.5) { // right mid
            color = vec4(color.r-0.1568, color.g-0.1568, color.b-0.1568, 1.0);  
        } else if (mod(pc.x-1, 3.0) == 0.5 && mod(pc.y+1, 3.0) == 0.5) { // right down
            color = vec4(color.r-0.1568, color.g-0.1568, color.b-0.1568, 1.0); 
        }
        return color;
    }
]]

function love.load()
    local w, h = love.graphics.getWidth(), love.graphics.getHeight()
    gaben = love.graphics.newImage('gaben.jpg')
    --[[
    simple_blur:send("image_size", {gaben:getWidth(), gaben:getHeight()})
    simple_blur:send("intensity", 3)
    ]]--
end

function love.update(dt)

end

function love.draw()
    love.graphics.setPixelEffect(glassy_pixely)
    love.graphics.draw(gaben, 0, 0)
end

function love.keypressed(key)
    if key == 'q' then love.event.push('quit') end
end

