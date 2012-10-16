require 'middleclass'
require 'utils'

note = class('note')

-- id, frequency, attack, decay, sustain, sustain_level, release: number
-- type: string
--
-- This class describes a single note that can be played by the user.
-- id is it's identifier number so that when we create a new note (when the user
-- presses a key) we can constantly check to see if that key was released or not
-- and then finish playing it.
-- type is it's wave identifier: square, sine, triangle or sawtooth. Maybe more 
-- different types can be added later (if I find any).
-- frequency is the note's frequency... ~
--
-- attack -> [0, m] in seconds
-- decay -> [0, n] in seconds
-- sustain -> [0, o] in seconds
-- sustain_level -> [0, 1]
-- release -> [0, p] in seconds
-- Linear curve for attack, decay and release.
--
-- More parameters should be added as I find out about them.
--
--
--

-- 50 years later
-- I FOUND OUT ABOUT THEM:
--
-- duty: square's duty cycle -> [0, 1]
-- slide: frequency change over time -> [0, 1], =0.5 doesn't change, >up, <down
-- max_lfo_freq: LFO's maximum frequency... ~ when vibrato/tremolo_speed = 1
-- vibrato_speed: LFO's frequency modulating frequency -> [0, 1]
-- vibrato_depth: LFO's amplitude modulating frequency -> [0, 1]
-- tremolo_speed: LFO's frequency modulating volume -> [0, 1]
-- tremolo_depth: LFO's amplitude modulating volume -> [0, 1]
--
function note:initialize(id, type, frequency, attack, decay, sustain,
    sustain_level, release, volume, duty, max_slide, slide, change_amount,
    change_delay, max_lfo_freq, vibrato_speed, vibrato_depth, tremolo_speed, 
    tremolo_depth, bitcrusher)

    self.id = id
    self.type = type
    self.frequency = frequency
    self.period = math.floor(bitcrusher/frequency)

    -- control
    self.t = 0 -- [0, 1], sample control
    self.playing = false

    -- envelope
    self.attack = attack
    self.decay = decay
    self.sustain = sustain
    self.sustain_level = sustain_level
    self.release = release

    -- samples
    self.n_samples =
    (self.attack+self.decay+self.sustain+self.release)*bitcrusher
    self.data = love.sound.newSoundData(self.n_samples, bitcrusher, 16, 2)

    -- playable
    self.audio = nil

    -- other parameters
    self.volume = volume
    self.duty = duty
    self.max_slide = max_slide
    self.slide = slide
    self.change_amount = change_amount
    self.change_delay = change_delay
    self.max_lfo_freq = max_lfo_freq
    self.vibrato_speed = vibrato_speed
    self.vibrato_depth = vibrato_depth
    self.tremolo_speed = tremolo_speed
    self.tremolo_depth = tremolo_depth
    self.bitcrusher = bitcrusher
end


-- Generates sound according to this note's attributes.
-- Modifies self.data with the appropriate samples and then passes this data
-- to self.audio to be played.
function note:generate()

    -- basic volume envelope to remove the annoying popping sound
    local volume_envelope_pop = adsr(self.n_samples, 0.1, 0, 1, 1, 0.1)

    -- user input volume envelope
    local volume_envelope_input = adsr(self.n_samples, self.attack, self.decay,
    self.sustain, self.sustain_level, self.release)

    -- lfo volume envelope (tremolo)
    local volume_envelope_lfo = lfo(self.n_samples, 'sine',
    self.tremolo_speed*self.max_lfo_freq, self.tremolo_depth)

    -- lfo frequency envelope (vibrato)
    local frequency_envelope_lfo = lfo(self.n_samples, 'sine',
    self.vibrato_speed*self.max_lfo_freq, self.vibrato_depth)

    -- frequency jump
    local new_freq = 0
    if self.change_amount == 0.5 then new_freq = self.frequency
    elseif self.change_amount > 0.5 then 
        new_freq = self.frequency + 2000*(self.change_amount - 0.5)
    else new_freq = self.frequency - (1000 - 2000*self.change_amount) end

    for i = 1, self.n_samples do

        -- volume envelopes
        local v = volume_envelope_pop:getSample(i)
        local v_i = volume_envelope_input:getSample(i)
        local v_l = volume_envelope_lfo:getSample(i)
        local s = (v+v_i+v_l)/3 -- (volume) envelope magic (!!)

        -- frequency envelopes

        -- vibrato
        local vib_inc = frequency_envelope_lfo:getSample(i)
        
        -- slide
        local slide_inc = 1
        if self.slide == 0.5 then slide_inc = 1 
        elseif self.slide > 0.5 then
            slide_inc = 1 + i*(2*self.slide-1)/self.n_samples
        else slide_inc = 1 - i*(1-2*self.slide)/self.n_samples end

        -- frequency jump
        if i >= self.n_samples*self.change_delay then
            self.period = math.floor(self.bitcrusher/new_freq) 
        end

        if self.t >= 1 then self.t = 0 end
        self.t = self.t + 1/self.period*slide_inc + 
        1/math.floor(self.bitcrusher/self.max_lfo_freq)*vib_inc

        if self.type == 'square' then
            if self.t <= self.duty then self.data:setSample(i, s*0.5)
            else self.data:setSample(i, -s*0.5) end

        elseif self.type == 'sine' then
            self.data:setSample(i, s*math.sin(2*self.t*math.pi))

        elseif self.type == 'triangle' then
            if self.t <= 0.5 then self.data:setSample(i, s*(0.5-self.t*2))
            else self.data:setSample(i, s*(0.5-(1-self.t)*2)) end

        elseif self.type == 'sawtooth' then
            self.data:setSample(i, s*(-0.5+self.t))

        else self.data:setSample(i, s*((math.random(0, 10000)*2 - 10000)/10000)) end
    end

    self.audio = love.audio.newSource(self.data)
    self.audio:setVolume(self.volume)
end

-- Plays this note (self.audio).
function note:play()
    love.audio.play(self.audio)
end

-- Stops playing this note.
function note:stop()
    love.audio.stop(self.audio)
end
