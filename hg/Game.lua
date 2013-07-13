require 'World'

Game = class('Game')

function Game:initialize()
    self.worlds = {}
    self.current_world = World()
    self.paused = false
end

function Game:update(dt)
    if not self.paused then self.current_world:update(dt) end
end

function Game:draw()
    self.current_world:draw()
end
