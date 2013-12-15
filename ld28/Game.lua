Game = class('Game')

function Game:init()
    self.planet = Planet(game_width/2, game_height/2, {radius = 2345, line_width = 16})
    self.ref = Resource(game_width/2, game_height/2, {size = 80})
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

    camerat.moving.left = false
    camerat.moving.right = false
    camerat.moving.up = false
    camerat.moving.down = false
end

function Game:draw()
    self.planet:draw()
    self.ref:draw()
end

function Game:mousepressed(x, y, button)
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

function Game:mousereleased(x, y, button)
    
end
