require 'Vector'

Entity = class('Entity')

function Entity:initialize(id, x, y, width, height, image)
    self.id = id
    self.p = Vector(x, y)
    self.w = width or 32
    self.h = height or 32
    self.image = image or gl.default_image
    self.alive = true

    self.r_aabb = {
        x1 = self.w/2, y1 = self.h/2,
        x2 = self.w/2, y2 = self.h/2
    }

    self.a_aabb = {
        x1 = self.p.x - self.r_aabb.x1, y1 = self.p.y - self.r_aabb.y1,
        x2 = self.p.x + self.r_aabb.x2, y2 = self.p.y + self.r_aabb.y2
    }
end

function Entity:update(dt)
    self:updateAABB()
end

function Entity:draw()
    love.graphics.draw(self.image, self.p.x - self.w/2 - 0.5, self.p.y - self.h/2 - 0.5)
end


function Entity:collideWith(e)
    self:updateAABB()
    e:updateAABB()
    
    if self:colliding(e) then
        if instanceOf(Player, e) and instanceOf(Enemy, self) then
            if self.type == 'boss' then
                e.dead = true
            end
        end

        if instanceOf(Projectile, self) and instanceOf(Tile, e) then
            self.alive = false

        elseif instanceOf(Enemy, self) and instanceOf(Projectile, e) then
            if self.type == 'boss' then
                self.hp = self.hp - 1
                if not gl.hurts[2]:isStopped() then
                    gl.hurts[2]:rewind()
                end
                love.audio.play(gl.hurts[2])
                if self.hp <= 0 then self.alive = false end
            else
                self.alive = false
            end
            e.alive = false

        else
            local direction, p = self:resolve(e)
            beholder:trigger('displace movable' .. self.id, direction, p)
        end
    end
end

function Entity:updateAABB()
    self.a_aabb.x1 = self.p.x - self.r_aabb.x1
    self.a_aabb.y1 = self.p.y - self.r_aabb.y1
    self.a_aabb.x2 = self.p.x + self.r_aabb.x2
    self.a_aabb.y2 = self.p.y + self.r_aabb.y2
end

function Entity:colliding(e)
    if self.a_aabb.x2 < e.a_aabb.x1 or self.a_aabb.x1 > e.a_aabb.x2 then return false end
    if self.a_aabb.y2 < e.a_aabb.y1 or self.a_aabb.y1 > e.a_aabb.y2 then return false end
    return true
end

function Entity:resolve(e)
    local direction = {}
    local dx, dy = 0, 0
    
    if self.p.x < e.p.x then
        direction.x = 'left'
        dx = math.abs(e.a_aabb.x1 - self.a_aabb.x2)
    else
        direction.x = 'right'
        dx = math.abs(self.a_aabb.x1 - e.a_aabb.x2)
    end

    if self.p.y < e.p.y then
        direction.y = 'up'
        dy = math.abs(e.a_aabb.y1 - self.a_aabb.y2)
    else
        direction.y = 'down'
        dy = math.abs(self.a_aabb.y1 - e.a_aabb.y2)
    end

    if dx < dy then return direction.x, dx
    else return direction.y, dy end
end
