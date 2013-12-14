Intro = class('Intro')

function Intro:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 360, line_width = 8})
end

function Intro:update(dt)
    self.planet:update(dt)
end

function Intro:draw()
    self.planet:draw()
end
