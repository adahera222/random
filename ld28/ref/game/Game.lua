require 'game/run/Run'

Game = class('Game')

function Game:init()
    self.current_run = Run()
end

function Game:update(dt)
    if self.current_run then self.current_run:update(dt) end
end

function Game:draw()
    if self.current_run then self.current_run:draw() end
end

function Game:keypressed(key)
    if self.current_run then self.current_run:keypressed(key) end
end

function Game:keyreleased(key)
    if self.current_run then self.current_run:keyreleased(key) end
end
