Game = class('Game')

function Game:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 2345, line_width = 8})
    self.ref = Resource(game_width/2, game_height/2, {size = 80})

    self.intro_text_alpha = 0
    timer:after(4, function()
        timer:tween(2, self, {intro_text_alpha = 255}, 'in-out-cubic')
        timer:after(6, function()
            timer:tween(2, self, {intro_text_alpha = 0}, 'in-out-cubic')
        end)
    end)

    self.people = {}
    self.resources = {}

    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
    self:spawnIsolatedResource()
end

function Game:update(dt)
    camera:zoomTo(camerat.zoom)
    local x, y = camera:pos()
    if mouse.x < 200 then 
        camerat.moving.left = true
        camerat.a.x = -(200-mouse.x)*camerat.actual_zoom 
    end
    if mouse.x > game_width-200 then 
        camerat.moving.right = true
        camerat.a.x = (mouse.x-(game_width-200))*camerat.actual_zoom 
    end
    if mouse.y < 150 then 
        camerat.moving.up = true
        camerat.a.y = -(150-mouse.y)*camerat.actual_zoom 
    end
    if mouse.y > game_height-150 then 
        camerat.moving.down = true
        camerat.a.y = (mouse.y-(game_height-150))*camerat.actual_zoom 
    end
    camerat.v.x = math.min(camerat.v.x + camerat.a.x*dt, 200)
    camerat.v.y = math.min(camerat.v.y + camerat.a.y*dt, 200)
    camera:move(camerat.v.x*camerat.v_multiplier, camerat.v.y*camerat.v_multiplier)
    if not camerat.moving.left and not camerat.moving.right then camerat.v.x = camerat.v.x*camerat.damping end
    if not camerat.moving.up and not camerat.moving.down then camerat.v.y = camerat.v.y*camerat.damping end
        

    self.planet:update(dt)
    self.ref:update(dt)
    for _, resource in ipairs(self.resources) do resource:update(dt) end

    camerat.moving.left = false
    camerat.moving.right = false
    camerat.moving.up = false
    camerat.moving.down = false
end

function Game:spawnIsolatedResource()
    local x, y = randomInCircle(self.planet.radius - 200)
    table.insert(self.resources, Resource(game_width/2 + x, game_height/2 + y, {size = math.prandom(20, 60)}))

    for _, person in ipairs(self.people) do

    end

    for _, resource in ipairs(self.resources) do

    end
end

function Game:spawnResourceGroup()
    
end

function Game:spawnPerson()
    
end

function Game:spawnPeople()
    
end

function Game:draw()
    love.graphics.setFont(main_font_big)
    love.graphics.setColor(32, 32, 32, self.intro_text_alpha)
    local w = main_font_big:getWidth("(MOUSE WHEEL TO ZOOM IN/OUT)")
    love.graphics.print("(MOUSE WHEEL TO ZOOM IN/OUT)", game_width/2 - w/2, game_height/2 + game_height/8 + main_font_big:getHeight()/2)
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.setFont(main_font_huge)

    self.planet:draw()
    self.ref:draw()
    for _, resource in ipairs(self.resources) do resource:draw() end
end

function Game:mousepressed(x, y, button)
    if camerat.can_zoom then 
        if button == 'wu' then 
            if camerat.actual_zoom <= 1.4 then
                camerat.actual_zoom = camerat.actual_zoom + 0.1
                timer:tween(0.35, camerat, {zoom = camerat.zoom + 0.1}, 'in-out-cubic') 
            end
        end
        if button == 'wd' then 
            if camerat.actual_zoom >= 0.2 then 
                camerat.actual_zoom = camerat.actual_zoom - 0.1
                timer:tween(0.35, camerat, {zoom = camerat.zoom - 0.1}, 'in-out-cubic') 
            end
        end
    end
end

function Game:mousereleased(x, y, button)
    
end
