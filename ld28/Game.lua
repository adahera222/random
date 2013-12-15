Game = class('Game')

function Game:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 2345, line_width = 16})
end

function Game:update(dt)
    self.planet:update(dt)
end

function Game:draw()
    self.planet:draw()
end

function Game:mousepressed(x, y, button)
    
end

function Game:mousereleased(x, y, button)
    
end
