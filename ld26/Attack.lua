Attack = class('Attack')

function Attack:initialize(modifiers)
    self.modifiers = modifiers
end

function Attack:attack(x, y, angle)
    if self.modifiers.multiple then
        local n = self.modifiers.multiple
        local xf = x + math.cos(angle)*16
        if n % 2 == 0 then
            for i = 1, n/2 do
                beholder.trigger('CREATE PROJECTILE', xf, y, angle-i*math.pi/24, self.modifiers)
                beholder.trigger('CREATE PROJECTILE', xf, y, angle+i*math.pi/24, self.modifiers)
            end

        else
            beholder.trigger('CREATE PROJECTILE', xf, y, angle, self.modifiers)
            for i = 1, math.floor(n/2) do
                beholder.trigger('CREATE PROJECTILE', xf, y, angle-i*math.pi/24, self.modifiers)
                beholder.trigger('CREATE PROJECTILE', xf, y, angle+i*math.pi/24, self.modifiers)
            end
        end
    end

    if self.modifiers.back then
        local xf = x + math.cos(angle-math.pi)*16 
        beholder.trigger('CREATE PROJECTILE', xf, y, angle-math.pi, self.modifiers)
    end
end



