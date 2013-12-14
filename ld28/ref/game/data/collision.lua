local collision_mask = struct('categories', 'masks')
collision_masks = {}

local group3 = {'BreakableSolid', 'EnemyWall', 'BreakableParticle', 'FaderParticle', 'TNT'}
local group4 = {'PhysicsParticle', 'FaderParticle', 'BreakableParticle', 'Blaster', 'Roller', 'Pumper', 'Item', 'SpikedBall', 'Spikes', 'Ladder', 'ChainedSpikedBallBall'}
collision_ignores = {}
collision_ignores['Player'] = {}
collision_ignores['Solid'] = {}
collision_ignores['BreakableSolid'] = {}
collision_ignores['EnemyWall'] = {'All', except = {'Blaster', 'Roller', 'MineCart'}}
collision_ignores['MeleeArea'] = {'All'}
collision_ignores['PhysicsParticle'] = {'Player', unpack(group4)}
collision_ignores['FaderParticle'] = {'Player', 'Boulder', unpack(group3)}
collision_ignores['BreakableParticle'] = {'Player', 'Boulder', unpack(group3)}
collision_ignores['BreakableParticleMW'] = {'Player', 'Boulder', unpack(group3)}
collision_ignores['Blaster'] = {'Player', unpack(group4)}
collision_ignores['Roller'] = {'Player', unpack(group4)}
collision_ignores['Pumper'] = {'Player', unpack(group4)}
collision_ignores['Item'] = {'Player', unpack(group4)}
collision_ignores['SpikedBall'] = {'Player', unpack(group4)}
collision_ignores['Spikes'] = {'Player', unpack(group4)}
collision_ignores['Ladder'] = {'Player', unpack(group4)}
collision_ignores['JumpingPad'] = {}
collision_ignores['ChainedSpikedBall'] = {}
collision_ignores['ChainedSpikedBallBall'] = {'All'}
collision_ignores['TNT'] = {}
collision_ignores['Boulder'] = {except = {'PhysicsParticle'}, unpack(group4)}
collision_ignores['PumperProjectile'] = {'All'}
collision_ignores['PumperProjectileDisarmed'] = {'All', except = {'Solid', 'JumpingPad', 'Button', 'MovingWall'}}
collision_ignores['Hammer'] = {'All', except = {'Solid', 'BreakableSolid', 'TNT', 'Boulder', 'MovingWall', 'Button'}}
collision_ignores['HammerStuck'] = {'All'}
collision_ignores['HomingHammer'] = {'All'}
collision_ignores['AntigravityRock'] = {'All'}
collision_ignores['AntigravityParticle'] = {'EnemyWall'}
collision_ignores['SeekerParticle'] = {'All', except = {'SeekerParticle'}}
collision_ignores['MovingWall'] = {'Solid', 'BreakableParticleMW'}
collision_ignores['Button'] = {}
collision_ignores['Trigger'] = {'All'}
collision_ignores['MovingEffect'] = {'All'}
collision_ignores['MineCart'] = {'All', except = {'Solid', 'Player', 'EnemyWall'}}

function generateCategoriesMasks()
    local incoming = {}
    local expanded = {}
    local all = {}
    for object_type, _ in pairs(collision_ignores) do
        incoming[object_type] = {}
        expanded[object_type] = {}
        table.insert(all, object_type)
    end
    for object_type, ignore_list in pairs(collision_ignores) do
        for key, ignored_type in pairs(ignore_list) do
            if ignored_type == 'All' then
                for _, all_object_type in ipairs(all) do
                    table.insert(incoming[all_object_type], object_type)
                    table.insert(expanded[object_type], all_object_type)
                end
            elseif type(ignored_type) == 'string' then
                if ignored_type ~= 'All' then
                    table.insert(incoming[ignored_type], object_type)
                    table.insert(expanded[object_type], ignored_type)
                end
            end
            if key == 'except' then
                for _, except_ignored_type in ipairs(ignored_type) do
                    for i, v in ipairs(incoming[except_ignored_type]) do
                        if v == object_type then
                            table.remove(incoming[except_ignored_type], i)
                            break
                        end
                    end
                end
                for _, except_ignored_type in ipairs(ignored_type) do
                    for i, v in ipairs(expanded[object_type]) do
                        if v == except_ignored_type then
                            table.remove(expanded[object_type], i)
                            break
                        end
                    end
                end
            end
        end
    end
    local edge_groups = {}
    for k, v in pairs(incoming) do
        table.sort(v, function(a, b) return string.lower(a) < string.lower(b) end)
    end
    local i = 0
    for k, v in pairs(incoming) do
        local str = ""
        for _, c in ipairs(v) do
            str = str .. c
        end
        if not edge_groups[str] then i = i + 1; edge_groups[str] = {n = i} end
        table.insert(edge_groups[str], k)
    end
    local categories = {}
    for k, _ in pairs(collision_ignores) do
        categories[k] = {}
    end
    for k, v in pairs(edge_groups) do
        for i, c in ipairs(v) do
            categories[c] = v.n
        end
    end
    for k, v in pairs(expanded) do
        local category = {categories[k]}
        local masks = {}
        for _, c in ipairs(v) do
            table.insert(masks, categories[c])
        end
        collision_masks[k] = collision_mask(category, masks)
    end
end

generateCategoriesMasks()
