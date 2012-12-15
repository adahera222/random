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
