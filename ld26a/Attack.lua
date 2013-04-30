Attack = class('Attack')

function Attack:initialize(modifiers)
    self.modifiers = modifiers
    self.can_attack = true
end

function Attack:attack(x, y, angle, activation_type)
    if self.modifiers.activation == activation_type then
        if self.can_attack then
            self.can_attack = false
            chrono:after(self.modifiers.cooldown, function() self.can_attack = true end)

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
    end
end



