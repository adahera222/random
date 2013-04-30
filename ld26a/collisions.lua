local collision_mask = struct('categories', 'masks')

collision_masks = {}
collision_masks['Player'] = collision_mask({1}, {})
collision_masks['EntityRect'] = collision_mask({2}, {})
collision_masks['Projectile'] = collision_mask({3}, {1, 3})
collision_masks['Enemy'] = collision_mask({4}, {1, 3, 4})
collision_masks['Area'] = collision_mask({3}, {1, 2, 3})

function collisionOnEnter(fa, fb, c)
    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()

    if fa:isSensor() and fb:isSensor() then
        if collIf('Enemy', 'Projectile', a, b) then
            a, b = collEnsure('Enemy', a, 'Projectile', b)
            a:collisionProjectile(b)
            b:collisionEnemy()
        end

        if collIf('Player', 'Enemy', a, b) then
            a, b = collEnsure('Player', a, 'Enemy', b)
            a:collisionEnemy()
        end

    elseif not (fa:isSensor() or fb:isSensor()) then
        if collIf('Player', 'EntityRect', a, b) then
            a, b = collEnsure('Player', a, 'EntityRect', b)
            a:collisionSolid('enter', nx, ny)
        end

        if collIf('Projectile', 'EntityRect', a, b) then
            a, b = collEnsure('Projectile', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end

        if collIf('Enemy', 'EntityRect', a, b) then
            a, b = collEnsure('Enemy', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end

        if collIf('Area', 'EntityRect', a, b) then
            a, b = collEnsure('Area', a, 'EntityRect', b)
            a:collisionSolid(nx, ny)
        end
    end
end

function collisionOnExit(fa, fb, c)
    collectgarbage()

    local a, b = fa:getUserData(), fb:getUserData()
    local nx, ny = c:getNormal()
    
    if fa:isSensor() and fb:isSensor() then
        if collIf('Area', 'Enemy', a, b) then
            a, b = collEnsure('Area', a, 'Enemy', b)
            a:collisionEnemy(b)
        end
    
    elseif not (fa:isSensor() or fb:isSensor()) then
        if collIf('Player', 'EntityRect', a, b) then
            a, b = collEnsure('Player', a, 'EntityRect', b)
            a:collisionSolid('exit', nx, ny)
        end
    end
end

function collEnsure(class_name1, a, class_name2, b)
    if a.class.name == class_name2 and b.class.name == class_name1 then return b, a
    else return a, b end
end

function collIf(class_name1, class_name2, a, b)
    if (a.class.name == class_name1 and b.class.name == class_name2) or
       (a.class.name == class_name2 and b.class.name == class_name1) then
       return true
    else return false end
end
