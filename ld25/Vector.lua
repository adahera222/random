require 'middleclass'

Vector = class('Vector')

function Vector:initialize(x, y)
    self.x = x or 0
    self.y = y or 0
end

function Vector:__tostring()
    return "(" .. tostring(self.x) .. ", " .. tostring(self.y) .. ")"
end

function Vector:__add(a)
    return Vector(self.x + a.x, self.y + a.y)
end

function Vector:__sub(a)
    return Vector(self.x - a.x, self.y - a.y)
end

function Vector:__mul(a)
    return Vector(self.x*a, self.y*a)
end

function Vector:__div(a)
    return Vector(self.x/a, self.y/a)
end

function Vector:len()
    return math.sqrt(self.x*self.x + self.y*self.y)
end

function Vector:clone()
    return Vector(self.x, self.y)
end

function Vector:normalize()
    local l = self:len()
    if l > 0 then self.x, self.y = self.x/l, self.y/l end
    return self
end

function Vector:normalized()
    return self:clone():normalize()    
end

function Vector:min(max_length)
    local s = max_length/self:len()
    if s >= 1 then s = 1 end
    return Vector(self.x*s, self.y*s)
end
