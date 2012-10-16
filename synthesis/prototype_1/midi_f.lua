require 'middleclass'
require 'utils'
local MIDI = require 'MIDI'

midi_f = class('midi_f')

function midi_f:initialize()
    self.ticks = 0
    self.score = nil
    self.initial_time = 0
    self.current_time = 0
    self.last_note = 1
    self.next_notes = {}
end

function midi_f:__tostring()
    local s = self.ticks .. '\n'

    for t = 2,#self.score do
        for i,e in ipairs(self.score[t]) do
            if e[1] == 'note' then
                s = s .. '[' .. e[1] .. ', ' .. e[2] .. ', ' .. e[3] .. ', '
                .. e[4] .. ', ' .. e[5] .. ', ' .. e[6] .. ', ' .. i .. ']\n'
            end
        end
    end

    return s
end

function midi_f:load(filename)
    local file = assert(io.open(filename, 'rb'))
    local data = file:read('*all')
    self.score = MIDI.midi2score(data)
    self.ticks = self.score[1]
end

function midi_f:normalize()
    local ln = true
    self.initial_time = love.timer.getTime()
    for t = 2,#self.score do
        for i,e in ipairs(self.score[t]) do
            if e[1] == 'note' then
                if ln then self.last_note = i; ln = false end
                e[2] = e[2]/self.ticks
            end
        end
    end
end

function midi_f:update(dt)
    self.current_time = love.timer.getTime() - self.initial_time

    while math.between(self.score[3][self.last_note][2],
        self.current_time-0.02, self.current_time+0.02) do
        table.insert(self.next_notes, self.score[3][self.last_note])
        self.last_note = self.last_note + 1
    end
end

