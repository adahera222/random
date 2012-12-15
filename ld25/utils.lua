function math.clamp(x, min, max)
    if x < min then return min
    elseif x > max then return max
    else return x end
end

function radToDeg(rad)
    return 180*rad/math.pi
end
