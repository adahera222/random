-- bad code
-- deal with it

math.randomseed(os.time());
math.random(); math.random(); math.random(); -- pro santo

require 'button'
require 'note'
require 'midi_f'

function love.load()
    --[[
    keys = {
        {'q', 1}, {'2', 1.08333}, {'w', 1.16666}, {'3', 1.25},
        {'e', 1.33333}, {'r', 1.41666}, {'5', 1.5}, {'t', 1.58333},
        {'6', 1.66666}, {'y', 1.75}, {'7', 1.83333}, {'u', 1.91666}, 
        {'i', 2}
    }

    kb = keyboard:new('square', 440, keys)
    --]]

    -- screen width/height
    SW = love.graphics.getWidth()
    SH = love.graphics.getHeight()

    -- button w/h
    BW = 102
    BH = 35

    -- button offset w/h
    BOW = 40 
    BOH = 40

    -- button spacing w/h
    BSW = 10
    BSH = 10

    -- colors
    bg = {16, 16, 16}
    button_bg = {102, 102, 102}
    button_outl = {123, 134, 144}
    button_high = {146, 195, 220}
    button_text = {190, 202, 182}
    button_fill = {135, 144, 125}
    
    love.graphics.setBackgroundColor(unpack(bg))
    font = love.graphics.newFont('visitor1.ttf', BH/2 - 2)
    love.graphics.setFont(font)

    -- paramaters
    attack = 0
    decay = 0
    sustain = 1
    sustainl = 1
    release = 0.5
    frequency = 0
    freqchange = 0.5 -- [0, 1] -> 
    -- (0.5, 1] = (freq, freq+1000], [0, 0.5) = [freq-1000, freq)
    freqdelay = 1
    maxlfofreq = 1 -- [0, 1] -> [0Hz, 20Hz]
    vibratos = 0
    vibratod = 0
    tremolos = 0
    tremolod = 0
    max_slide = 1
    bitcrusher = 1
    slide = 0.5
    duty = 0.5
    volume = 0.5
    wave = 'square'

    -- value table
    ba = {
        attack = {value = attack},
        decay = {value = decay},
        sustain = {value = sustain},
        sustainl = {value = sustainl},
        release = {value = release},
        freqchange = {value = freqchange},
        freqdelay = {value = freqdelay},
        maxlfofreq = {value = maxlfofreq},
        vibratos = {value = vibratos},
        vibratod = {value = vibratod},
        tremolos = {value = tremolos},
        tremolod = {value = tremolod},
        slide = {value = slide},
        duty = {value = duty},
        bitcrusher = {value = bitcrusher},
        frequency = {value = frequency},
        volume = {value = volume}
    }

    uistate = {
        mousex = 0,
        mousey = 0,
        mousedown = false,
        hot = 0
    }
    
    buttons = {
        button:new(1, 'wave', 5*BOW+0*BW+BSW*0, BOH+0*BH+BSH*0, BW, BH,
        'square', nil, function() wave = 'square' end),

        button:new(2, 'wave', 5*BOW+1*BW+BSW*1, BOH+0*BH+BSH*0, BW, BH,
        'sawtooth', nil, function() wave = 'sawtooth' end),

        button:new(3, 'wave', 5*BOW+2*BW+BSW*2, BOH+0*BH+BSH*0, BW, BH,
        'sine', nil, function() wave = 'sine' end),

        button:new(4, 'wave', 5*BOW+3*BW+BSW*3, BOH+0*BH+BSH*0, BW, BH,
        'triangle', nil, function() wave = 'triangle' end),

        button:new(5, 'wave', 5*BOW+4*BW+BSW*4, BOH+0*BH+BSH*0, BW, BH,
        'noise', nil, function() wave = 'noise' end),

        button:new(6, 'slider', 5*BOW+0*BW+BSW*0, BOH+1*BH+BSH*3, BW, BH, 
        'attack', attack, function(v) attack = v end),

        button:new(7, 'slider', 5*BOW+0*BW+BSW*0, BOH+2*BH+BSH*4, BW, BH,
        'decay', decay, function(v) decay = v end),

        button:new(8, 'slider', 5*BOW+0*BW+BSW*0, BOH+3*BH+BSH*5, BW, BH,
        'sustain', sustain, function(v) sustain = v end),

        button:new(30, 'slider', 5*BOW+0*BW+BSW*0, BOH+4*BH+BSH*6, BW, BH,
        'sustainl', sustainl, function(v) sustainl = v end),
        
        button:new(9, 'slider', 5*BOW+0*BW+BSW*0, BOH+5*BH+BSH*7, BW, BH,
        'release', release, function(v) release = v end),

        button:new(12, 'slider', 5*BOW+0*BW+BSW*0, BOH+6*BH+BSH*8, BW, BH,
        'frequency', frequency, function(v) frequency = v end),

        button:new(13, 'slider', 5*BOW+0*BW+BSW*0, BOH+7*BH+BSH*9, BW, BH,
        'duty', duty, function(v) duty = v end),

        button:new(19, 'slider', 5*BOW+0*BW+BSW*0, BOH+8*BH+BSH*10, BW, BH,
        'slide', slide, function(v) slide = v end),

        button:new(20, 'slider', 5*BOW+0*BW+BSW*0, BOH+9*BH+BSH*11, BW, BH,
        'freqchange', freqchange, function(v) freqchange = v end),

        button:new(21, 'slider', 5*BOW+0*BW+BSW*0, BOH+10*BH+BSH*12, BW, BH,
        'freqdelay', freqdelay, function(v) freqdelay = v end),

        button:new(14, 'slider', 5*BOW+1*BW+BSW*1, BOH+1*BH+BSH*3, BW, BH,
        'maxlfofreq', maxlfofreq, function(v) maxlfofreq = v end),

        button:new(15, 'slider', 5*BOW+1*BW+BSW*1, BOH+2*BH+BSH*4, BW, BH,
        'vibratos', vibratos, function(v) vibratos = v end),

        button:new(16, 'slider', 5*BOW+1*BW+BSW*1, BOH+3*BH+BSH*5, BW, BH,
        'vibratod', vibratod, function(v) vibratod = v end),

        button:new(17, 'slider', 5*BOW+1*BW+BSW*1, BOH+4*BH+BSH*6, BW, BH,
        'tremolos', tremolos, function(v) tremolos = v end),

        button:new(18, 'slider', 5*BOW+1*BW+BSW*1, BOH+5*BH+BSH*7, BW, BH,
        'tremolod', tremolod, function(v) tremolod = v end),

        button:new(32, 'slider', 5*BOW+1*BW+BSW*1, BOH+6*BH+BSH*8, BW, BH,
        'bitcrusher', bitcrusher, function(v) bitcrusher = v end),

        button:new(10, 'normal', BOW+0*BW+BSW*0, BOH+11*BH+BSH*10, BW, BH,
        'play', nil, play),

        button:new(11, 'slider', BOW+0*BW+BSW*0, BOH+10*BH+BSH*9, BW, BH,
        'volume', volume, function(v) volume = v end),

        button:new(22, 'normal', BOW+0*BW+BSW*0, BOH+0*BH+BSH*0, BW, BH,
        'coin', nil, coin),

        button:new(23, 'normal', BOW+0*BW+BSW*0, BOH+1*BH+BSH*1, BW, BH,
        'jump', nil, jump),

        button:new(24, 'normal', BOW+0*BW+BSW*0, BOH+2*BH+BSH*2, BW, BH,
        'laser', nil, laser),

        button:new(25, 'normal', BOW+0*BW+BSW*0, BOH+3*BH+BSH*3, BW, BH,
        'death', nil, death),

        button:new(26, 'normal', BOW+0*BW+BSW*0, BOH+4*BH+BSH*4, BW, BH,
        'explosion', nil, explosion),

        button:new(27, 'normal', BOW+0*BW+BSW*0, BOH+5*BH+BSH*5, BW, BH,
        'hit', nil, hit),

        button:new(28, 'normal', BOW+0*BW+BSW*0, BOH+6*BH+BSH*6, BW, BH,
        'powerup', nil, powerup),

        button:new(29, 'normal', BOW+0*BW+BSW*0, BOH+7*BH+BSH*7, BW, BH,
        'select', nil, select),

        button:new(31, 'normal', BOW+0*BW+BSW*0, BOH+8*BH+BSH*8, BW, BH,
        'randomize', nil, randomize)
    }

    song = midi_f:new()
    song:load('C:/Users/Waffles/Desktop/code/love/ss/2.mid')
    song:normalize()
    print(song)

    play_midi = false
    midi_t = 0

    notef = {}
    notef[55] = 196.00; notef[64] = 329.63; notef[67] = 392.00;
    notef[69] = 440.00; notef[70] = 466.16; notef[71] = 493.88;
    notef[72] = 523.25; notef[74] = 587.33; notef[76] = 659.26;
    notef[77] = 698.46; notef[79] = 783.99; notef[81] = 880.00;
    notef[43] = 98.00; notef[60] = 261.23; notef[52] = 164.81;
    notef[57] = 220.00; notef[59] = 246.94; notef[58] = 233.08;
    notef[65] = 349.23; notef[62] = 293.66; notef[78] = 739.99;
    notef[48] = 130.81; notef[75] = 622.25; notef[56] = 207.65;
    notef[68] = 415.30; notef[53] = 174.61; notef[84] = 1046.50;
    notef[50] = 146.83; notef[63] = 311.13; notef[44] = 103.83;
    notef[51] = 155.56; notef[54] = 185.00; 
    
    notes = {}
    for _, n in ipairs(song.score[3]) do
        if n[1] == 'note' then

            -- this makes this code VERY specific
            -- it (probably) wont work with other midi files lol  
            local bugss = n[3]/song.ticks
            if bugss <= 0.25 then bugss = 0.3 end
            if bugss >= 0.75 then bugss = 0.8 end

            local new_note = note:new(#notes+1, 'square', notef[n[5]], 0, 0,
            bugss, 1, 0, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 0, 0, 0, 0, 44100) 
            print(n[2])
            new_note:generate()
            table.insert(notes, {time = n[2], note = new_note, played = false})
        end
    end
end

function love.update(dt)
    local hot = {} -- {true, false, false} -> 1 button is hot
    uistate.mousex, uistate.mousey = love.mouse.getPosition()

    for _, b in ipairs(buttons) do 
        if b.type == 'slider' then b:update(dt, ba[b.text].value)
        else b:update(dt) end

        table.insert(hot, b.hot)
    end

    if not l(hot) then uistate.hot = 0 end

    if play_midi then
        midi_t = midi_t + 1.7*dt

        for _, n in ipairs(notes) do
            if n.time <= midi_t then
                if not n.played then
                    print(n.note.frequency)
                    n.played = true
                    n.note:play()
                end
            end
        end
    end
end

function love.draw()
    love.graphics.setLineWidth(1)
    love.graphics.setColor(unpack(button_text))
    love.graphics.rectangle('line', 20, 20, BW+2*20, SH-40)
    love.graphics.rectangle('line', 2*BOW+BW, 20, BOW+5*BW+BSW*4, SH-40)
    for _, b in ipairs(buttons) do b:draw() end
end

function love.keypressed(key)
    if key == ' ' then play() end
    if key == 'm' then play_midi = true end
end

function love.mousepressed(x, y, button)
    if button == 'l' then uistate.mousedown = true end
end

function love.mousereleased(x, y, button)
    if button == 'l' then uistate.mousedown = false end
end

-- overtone
function l(list)
    local head = table.remove(list, 1)
    if head == nil then return false end
    local tail = list
    return head or l(tail)
end

function play()
    local note = note:new(0, wave, ba.frequency.value*4169.66, ba.attack.value,
    ba.decay.value, ba.sustain.value, ba.sustainl.value,
    ba.release.value, ba.volume.value, ba.duty.value, max_slide, 
    ba.slide.value, ba.freqchange.value, ba.freqdelay.value,
    ba.maxlfofreq.value*20, ba.vibratos.value, ba.vibratod.value, 
    ba.tremolos.value, ba.tremolod.value, ba.bitcrusher.value*44100)
    note:generate()
    note:play()
end

function coin() 
    local coin_wave = {'square', 'sine', 'triangle'}

    ba.attack.value = 0
    ba.decay.value = 0
    ba.sustain.value = random(0.05, 0.3) 
    ba.release.value = random(0.3, 0.6)
    ba.freqchange.value = either(0.5, random(0.55, 0.9))
    ba.freqdelay.value = random(0.2, 0.5)
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = 0.5
    ba.duty.value = random(0.3, 0.7)
    ba.frequency.value = random(0.3, 0.5)
    wave = coin_wave[math.random(1, #coin_wave)]
end

function jump() 
    local jump_wave = {'square', 'sawtooth'} 

    ba.attack.value = 0
    ba.decay.value = 0 
    ba.sustain.value = random(0.4, 1)
    ba.release.value = random(0.05, 0.2)
    ba.freqchange.value = 0.5
    ba.freqdelay.value = 1
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = random(0.5, 1)
    ba.duty.value = either(0.5, random(0.1, 0.9))
    ba.frequency.value = random(0.1, 0.5)
    wave = jump_wave[math.random(1, #jump_wave)]
end

function laser() 
    local laser_wave = {'square', 'sine', 'triangle'}

    ba.attack.value = 0
    ba.decay.value = 0
    ba.sustain.value = random(0.05, 0.6)
    ba.release.value = random(0.05, 0.3)
    ba.freqchange.value = 0.5
    ba.freqdelay.value = 1
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = random(0.05, 0.5)
    ba.duty.value = either(0.5, random(0.1, 0.9))
    ba.frequency.value = random(0.1, 0.5)
    wave = laser_wave[math.random(1, #laser_wave)]
end

function death() end
function explosion() 
    ba.attack.value = 0
    ba.decay.value = random(0.05, 0.4)
    ba.sustain.value = random(0.05, 0.4)
    ba.release.value = random(0.05, 0.4)
    ba.freqchange.value = either(0.5, random(0.3, 0.7))
    ba.freqdelay.value = random(0.1, 0.3)
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = either(0.5, random(0.3, 0.7))
    ba.duty.value = 0.5
    ba.frequency.value = random(0.05, 0.2)
    wave = 'noise'
end

function hit() 
    local hit_wave = {'square', 'sawtooth'} 

    ba.attack.value = 0
    ba.decay.value = random(0.01, 0.1)
    ba.sustain.value = random(0.01, 0.1)
    ba.release.value = random(0.01, 0.1)
    ba.freqchange.value = 0.5 
    ba.freqdelay.value = 1
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = random(0.1, 0.5)
    ba.duty.value = either(0.5, random(0.1, 0.9))
    ba.frequency.value = random(0.01, 0.1)
    wave = hit_wave[math.random(1, #hit_wave)]
end

function powerup() 
    local powerup_wave = {'square', 'sawtooth'} 

    ba.attack.value = 0
    ba.decay.value = 0 
    ba.sustain.value = random(0.4, 1)
    ba.release.value = random(0.05, 0.2)
    ba.freqchange.value = 0.5
    ba.freqdelay.value = 1
    ba.vibratos.value = random(0.05, 0.45)
    ba.vibratod.value = 1
    ba.tremolos.value = random(0.05, 0.45)
    ba.tremolod.value = 1
    ba.slide.value = random(0.5, 1)
    ba.duty.value = either(0.5, random(0.1, 0.9))
    ba.frequency.value = random(0.1, 0.5)
    wave = powerup_wave[math.random(1, #powerup_wave)]
end

function select() 
    local select_wave = {'sine', 'triangle'}
    
    ba.attack.value = 0
    ba.decay.value = 0
    ba.sustain.value = random(0.05, 0.1) 
    ba.release.value = random(0.05, 0.1)
    ba.freqchange.value = 0.5
    ba.freqdelay.value = 1 
    ba.vibratos.value = 0
    ba.vibratod.value = 0
    ba.tremolos.value = 0
    ba.tremolod.value = 0
    ba.slide.value = 0.5
    ba.duty.value = 0.5 
    ba.frequency.value = random(0.1, 0.5)
    wave = select_wave[math.random(1, #select_wave)]
end

function randomize()
    local random_wave = {'square', 'sawtooth', 'sine', 'triangle'}

    ba.attack.value = random(0, 1)
    ba.decay.value = random(0, 1)
    ba.sustain.value = random(0, 1) 
    ba.release.value = random(0, 1)
    ba.freqchange.value = random(0, 1)
    ba.freqdelay.value = random(0, 1) 
    ba.vibratos.value = random(0, 1)
    ba.vibratod.value = random(0, 1)
    ba.tremolos.value = random(0, 1)
    ba.tremolod.value = random(0, 1)
    ba.slide.value = random(0, 1)
    ba.duty.value = random(0, 1)
    ba.frequency.value = random(0, 0.5)
    wave = random_wave[math.random(1, #random_wave)]
end
