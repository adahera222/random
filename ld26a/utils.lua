function chance(n, action)
    local c = math.random(1, 100)
    if c < n*100 then action() end
end

function round(n, p)
    local m = math.pow(10, p or 0)
    return math.floor(n*m+0.5)/m
end

function contains_enemy(t, v)
    for _, e in ipairs(t) do if v == e.enemy then return true end end
    return false
end

