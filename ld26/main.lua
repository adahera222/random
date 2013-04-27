require 'lib/middleclass/middleclass'
require 'lib/chrono/chrono'
beholder = require 'lib/beholder/beholder'
Vector = require 'lib/hump/vector'
Camera = require 'lib/hump/camera'
tween = require 'lib/tween/tween'
anim8 = require 'lib/anim8/anim8'

require 'Level'

UID = 0
function getID() UID = UID + 1; return UID end

function love.load()
    chrono = Chrono()
    camera = Camera()

    level = Level()
end

function love.update(dt)
    tween.update(dt)
    chrono:update(dt)

    level:update(dt)
end

function love.draw()
    camera:attach()
    level:draw()
    camera:detach()
end

function love.keypressed(key)
    level:keypressed(key)  
end
