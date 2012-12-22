function math.clamp(x, min, max)
    if x < min then return min
    elseif x > max then return max
    else return x end
end

function radToDeg(rad)
    return 180*rad/math.pi
end

-- only update on screen entities
function entityInFrame(entity, player_p)
    if entity.p.x >= player_p.x - gl.width and entity.p.x <= player_p.x + gl.width and
       entity.p.y >= player_p.y - gl.height and entity.p.y <= player_p.y + gl.height then
       return true
    else return false end
end
