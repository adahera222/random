require 'schedius'

function love.load()
    schedius.load(arg[2])
    schedius.configure()
end

function love.draw()
    schedius.draw()
end
