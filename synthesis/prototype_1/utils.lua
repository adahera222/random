-- id: number
-- table: note
--
-- Finds a note in a table by its id attribute.
-- Returns its position or 0 if it isn't found.
function findByID(id, table)
    for i, n in ipairs(table) do
        if n.id == id then return i end 
    end

    return 0
end

-- n_samples, attack, decay, sustain, sustain_level, release: number
-- returns data: SoundData
--
-- Creates an ADSR envelope/wave. Follows a linear curve.
function adsr(n_samples, attack, decay, sustain, sustain_level, release)
    local data = love.sound.newSoundData(n_samples, 44100, 16, 2)

    -- s_... is the number of the last sample from the ... stage.
    local s_attack = 44100*attack 
    local s_decay = 44100*decay+s_attack
    local s_sustain = 44100*sustain+s_decay 
    local s_release = 44100*release+s_sustain

    for i = 1, n_samples do
        if i > 0 and i <= s_attack then
            data:setSample(i, i/s_attack) 
        end
        
        if i > s_attack and i <= s_decay then
            data:setSample(i, (i + sustain_level*(s_attack - i) -
            s_decay)/(s_attack - s_decay))
        end

        if i > s_decay and i <= s_sustain then
            data:setSample(i, sustain_level) 
        end

        if i > s_sustain and i <= s_release then
            data:setSample(i, sustain_level*(i - s_release)/(s_sustain -
            s_release))
        end
    end

    return data
end

-- Creates an LFO envelope/wave. 
function lfo(n_samples, type, frequency, depth)
    local data = love.sound.newSoundData(n_samples, 44100, 16, 2)
    local period = math.floor(44100/frequency)
    local t = 0

    for i = 1, n_samples do
        if t >= 1 then t = 0 end
        t = t + 1/period

        if type == 'sine' then
            data:setSample(i, depth*math.sin(2*math.pi*t)) 
        end
    end

    return data
end

function round(n, precision)
    return math.floor(n*math.pow(10, precision))/math.pow(10, precision)
end

-- min, max: number (up to 3 decimal places)
function random(min, max)
    if min >= 0 then return math.random(min*1000, max*1000)/1000 end
    if max <= 0 then return -math.random(-max*1000, -min*1000)/1000 end
    if min <= 0 and max >= 0 then 
        return (math.random(0, -min*1000+max*1000)-max*1000)/1000
    end
end

function either(choice1, choice2)
    local p = math.random(1, 2)
    if p == 1 then return choice1
    else return choice2 end
end
