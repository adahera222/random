gl = {}

gl.normal_block = love.graphics.newImage('gfx/normal_block.png')
gl.default_image = love.graphics.newImage('gfx/default_image.png')
gl.player_image = love.graphics.newImage('gfx/player.png')

gl.entity_counter = 0
gl.entity_id = 
    function() 
        gl.entity_counter = gl.entity_counter + 1
        return gl.entity_counter
    end

gl.gravity = 90 -- in pixels per second

return gl
