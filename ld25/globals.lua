gl = {}

gl.normal_block = love.graphics.newImage('gfx/normal_block.png')
gl.default_image = love.graphics.newImage('gfx/default_image.png')
gl.player_normal = love.graphics.newImage('gfx/player_normal.png')
gl.animal = love.graphics.newImage('gfx/animal.png')
gl.person_normal = love.graphics.newImage('gfx/person_normal.png')
gl.yay = love.graphics.newImage('gfx/yay.png')

gl.entity_counter = 0
gl.entity_id = 
    function() 
        gl.entity_counter = gl.entity_counter + 1
        return gl.entity_counter
    end

gl.gravity = 500 -- in pixels per second

return gl
