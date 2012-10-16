require 'middleclass'

button = class('button')

function button:initialize(id, type, x, y, w, h, text, value, action)
    self.id = id
    self.type = type
    self.x = x
    self.y = y
    self.w = w
    self.h = h
    self.text = text
    self.action = action
    
    self.hot = false

    -- slider
    self.value = value 

    -- normal
    self.delay = 1
    self.d_i = 0
    self.flag = true
end

function button:update(dt, value) 
    if value then self.value = value end

    self.d_i = self.d_i + dt
    if self.d_i > self.delay then self.flag = true end

    if self:hit() then
        self.hot = true
        uistate.hot = self.id
        if uistate.mousedown then 

            if self.type == 'slider' then
                ba[self.text].value = round((uistate.mousex - self.x)/100, 2)
                if ba[self.text].value > 1 then ba[self.text].value = 1 end
                self.action(ba[self.text].value) 
                self.value = ba[self.text].value
            end

            if self.type == 'wave' then
                self.action()
            end

            if self.type == 'normal' then
                if self.flag then
                    print(self.id)
                    self.action()
                    self.d_i = 0                        
                    self.flag = false
                end
            end
        end
    else self.hot = false end
end

function button:draw()
    love.graphics.setColor(unpack(button_outl))
    if uistate.hot == self.id then love.graphics.setColor(unpack(button_high)) end
    love.graphics.setLineWidth(2)
    love.graphics.rectangle('line', self.x, self.y, self.w, self.h)
    love.graphics.setColor(unpack(button_fill))

    if self.type == 'slider' then
        love.graphics.rectangle('fill', self.x+1, self.y+1, self.value*100-1, 
        self.h-3)
    end

    if self.type == 'wave' then
        if wave == self.text then
            love.graphics.rectangle('fill', self.x+1, self.y+1, self.w-3,
            self.h-3)
        end
    end

    if self.type == 'normal' then
        if self.hot and uistate.mousedown then
            love.graphics.rectangle('fill', self.x+1, self.y+1, self.w-3,
            self.h-3)
        end
    end

    love.graphics.setColor(unpack(button_text))
    love.graphics.printf(self.text, self.x+5, self.y+font:getHeight()/2,
    self.w, 'center')
end

function button:hit()
    local outside_button =
        uistate.mousex < self.x or uistate.mousex >= self.x+self.w or
        uistate.mousey < self.y or uistate.mousey >= self.y+self.h

    if outside_button then return false
    else return true end
end
