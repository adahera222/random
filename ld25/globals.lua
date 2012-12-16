gl = {}

gl.normal_block = love.graphics.newImage('gfx/normal_block.png')
gl.d_blue_block = love.graphics.newImage('gfx/d_blue_block.png')
gl.d_brown_block = love.graphics.newImage('gfx/d_brown_block.png')
gl.bg_block = love.graphics.newImage('gfx/bg_block.png')
gl.default_image = love.graphics.newImage('gfx/default_image.png')
gl.player_normal = love.graphics.newImage('gfx/player_normal.png')
gl.child = love.graphics.newImage('gfx/child.png')
gl.person_normal = love.graphics.newImage('gfx/person_normal.png')
gl.spaceenter = love.graphics.newImage('gfx/spaceenter.png')
gl.projectile = love.graphics.newImage('gfx/projectile.png')
gl.spawner = love.graphics.newImage('gfx/spawner.png')

gl.play = love.graphics.newImage('gfx/play.png')
gl.killeveryone = love.graphics.newImage('gfx/killeveryone.png')
gl.lmbshoot = love.graphics.newImage('gfx/lmbshoot.png')
gl.goodjob = love.graphics.newImage('gfx/goodjob.png')
gl.mommy = love.graphics.newImage('gfx/mommy.png')
gl.talktomom = love.graphics.newImage('gfx/talktomom.png')
gl.himom = love.graphics.newImage('gfx/himom.png')
gl.sorry = love.graphics.newImage('gfx/sorry.png')
gl.try = love.graphics.newImage('gfx/try.png')
gl.really_sorry = love.graphics.newImage('gfx/really_sorry.png')
gl.dots = love.graphics.newImage('gfx/dots.png')

gl.happy = {
    {love.graphics.newImage('gfx/yay.png'), 1}
}

gl.flee = {
    {love.graphics.newImage('gfx/plsdontkill.png'), 1.5},
    {love.graphics.newImage('gfx/xx.png'), 1},
    {love.graphics.newImage('gfx/mercy.png'), 1.5},
    {love.graphics.newImage('gfx/christmas.png'), 2.5},
    {love.graphics.newImage('gfx/no.png'), 1},
    {love.graphics.newImage('gfx/money.png'), 1.5}
}

gl.mom_speak = {
    {love.graphics.newImage('gfx/useless.png'), 2},
    {love.graphics.newImage('gfx/videogames.png'), 4},
    {love.graphics.newImage('gfx/birth.png'), 2},
    {love.graphics.newImage('gfx/brother.png'), 3}
}

gl.hurts = {
    love.audio.newSource('sounds/hurt_1.wav', 'static'),
    love.audio.newSource('sounds/hurt_2.wav', 'static'),
    love.audio.newSource('sounds/hurt_3.wav', 'static'),
    love.audio.newSource('sounds/hurt_4.wav', 'static')
}

gl.jumps = {
    love.audio.newSource('sounds/jump_1.wav', 'static'),
    love.audio.newSource('sounds/jump_2.wav', 'static'),
    love.audio.newSource('sounds/jump_3.wav', 'static'),
    love.audio.newSource('sounds/jump_4.wav', 'static')
}

gl.shot = love.audio.newSource('sounds/shot.wav', 'static')

gl.entity_counter = 0
gl.entity_id = 
    function() 
        gl.entity_counter = gl.entity_counter + 1
        return gl.entity_counter
    end

gl.gravity = 500 -- in pixels per second

return gl
