local newImage = love.graphics.newImage
local newImageData = love.image.newImageData

-- Images
rock_1 = newImage('resources/particles/rock_1.png')
rock_2 = newImage('resources/particles/rock_2.png')
rock_3 = newImage('resources/particles/rock_3.png')
rock_4 = newImage('resources/particles/rock_4.png')
rock_1_dark = newImage('resources/particles/rock_1_dark.png')
rock_2_dark = newImage('resources/particles/rock_2_dark.png')
rock_3_dark = newImage('resources/particles/rock_3_dark.png')
rock_4_dark = newImage('resources/particles/rock_4_dark.png')
rock_1_red = newImage('resources/particles/rock_1_red.png')
rock_2_red = newImage('resources/particles/rock_2_red.png')
rock_3_red = newImage('resources/particles/rock_3_red.png')
rock_4_red = newImage('resources/particles/rock_4_red.png')
scrap_1 = newImage('resources/particles/scrap_4.png')
scrap_2 = newImage('resources/particles/scrap_5.png')
scrap_3 = newImage('resources/particles/scrap_6.png')
scrap_4 = newImage('resources/particles/scrap_7.png')
spiked_ball = newImage('resources/traps/spiked_ball.png')
spiked_ball_c = newImage('resources/traps/spiked_ball_c.png')
spikes = newImage('resources/traps/spikes.png')
ladder_mid = newImage('resources/tiles/ladder_mid.png')
ladder_top = newImage('resources/tiles/ladder_top.png')
hmwall_left = newImage('resources/tiles/hmwall_left.png')
hmwall_mid = newImage('resources/tiles/hmwall_mid.png')
hmwall_right = newImage('resources/tiles/hmwall_right.png')
vmwall_top = newImage('resources/tiles/vmwall_top.png')
vmwall_mid = newImage('resources/tiles/vmwall_mid.png')
vmwall_bot = newImage('resources/tiles/vmwall_bot.png')
button_up = newImage('resources/tiles/button_up.png')
button_down = newImage('resources/tiles/button_down.png')
button_base_up = newImage('resources/tiles/button_base_up.png')
button_base_down = newImage('resources/tiles/button_base_down.png')
chain = newImage('resources/traps/chain.png')
chain_link = newImage('resources/traps/chain_link.png')
chain_circle = newImage('resources/traps/chain_circle.png')
chain_base = newImage('resources/tiles/chain_base.png')
tnt = newImage('resources/tiles/tnt.png')
b_solid_1 = newImage('resources/tiles/b_solid_1.png')
b_solid_2 = newImage('resources/tiles/b_solid_2.png')
b_solid_3 = newImage('resources/tiles/b_solid_3.png')
b_solid_dark_1 = newImage('resources/tiles/b_solid_dark_1.png')
b_solid_dark_2 = newImage('resources/tiles/b_solid_dark_2.png')
b_solid_dark_3 = newImage('resources/tiles/b_solid_dark_3.png')
b_solid_red_1 = newImage('resources/tiles/b_solid_red_1.png')
b_solid_red_2 = newImage('resources/tiles/b_solid_red_2.png')
b_solid_red_3 = newImage('resources/tiles/b_solid_red_3.png')
grass_1 = newImage('resources/tiles/grass_1.png')
grass_2 = newImage('resources/tiles/grass_2.png')
mushroom_1 = newImage('resources/tiles/mushroom_1.png')
mushroom_2 = newImage('resources/tiles/mushroom_2.png')
mushroom_3 = newImage('resources/tiles/mushroom_3.png')
rail_left = newImage('resources/tiles/rail_left.png')
rail_mid = newImage('resources/tiles/rail_mid.png')
rail_right = newImage('resources/tiles/rail_right.png')
mine_cart = newImage('resources/items/mine_cart.png')
mine_cart_damaged = newImage('resources/items/mine_cart_damaged.png')
boulder = newImage('resources/traps/boulder.png')
background_back = newImage('resources/backgrounds/background_back.png')
background_middle = newImage('resources/backgrounds/background_middle.png')
background_front = newImage('resources/backgrounds/background_front.png')
background_backb = newImage('resources/backgrounds/background_backb.png')
background_midb = newImage('resources/backgrounds/background_midb.png')
background_frontb = newImage('resources/backgrounds/background_frontb.png')
hammer = newImage('resources/items/hammer.png')

-- Particle System
main_pso = 'resources/Zytokine.pso'

-- Animations
animations = {}
local animation = struct('source', 'w', 'h', 'delay', 'mode')
-- Creates character animation from path resources/characters/name/....
local function getCharacterAnimation(name)
    local path = 'resources/characters/' .. name .. '/' .. name
    return {
        name = name,
        run = animation(newImage(path .. '_run.png'), 32, 32, 0.12),
        idle = animation(newImage(path .. '_idle.png'), 32, 32, 0.25),
        jump = animation(newImage(path .. '_jump.png'), 32, 32, 0.25),
        fall = animation(newImage(path .. '_fall.png'), 32, 32, 0.25),
        hurt = animation(newImage(path .. '_hurt.png'), 32, 32, 0.25),
        climb = animation(newImage(path .. '_climb.png'), 32, 36, 0.1),
        attack_1 = animation(newImage(path .. '_hammer_throw.png'), 76, 42, data.Player.attack_1_frame_duration),
        attack_2 = animation(newImage(path .. '_attack_2.png'), 76, 42, data.Player.attack_2_frame_duration),
        death = animation(newImage(path .. '_death.png'), 48, 32, 0.1, 'once'),
        block = animation(newImage(path.. '_block.png'), 32, 32, 0.25)
    }
end
-- Set animations
animations['player'] = getCharacterAnimation('player')
animations['blaster'] = {
    move = animation(newImage('resources/characters/blaster/blaster_move.png'), 32, 40, data.Blaster.move_frame_duration),
    hurt = animation(newImage('resources/characters/blaster/blaster_hurt.png'), 32, 40, data.Blaster.move_frame_duration),
    attack = animation(newImage('resources/characters/blaster/blaster_attack.png'), 32, 40, data.Blaster.move_frame_duration)
}
animations['roller'] = {
    move = animation(newImage('resources/characters/roller/roller_move.png'), 32, 32, data.Roller.move_frame_duration),
    hurt = animation(newImage('resources/characters/roller/roller_hurt.png'), 32, 32, data.Roller.move_frame_duration)
}
animations['pumper'] = {
    idle = animation(newImage('resources/characters/pumper/pumper_idle.png'), 32, 32, data.Pumper.attack_frame_duration),
    attack = animation(newImage('resources/characters/pumper/pumper_attack.png'), 32, 32, data.Pumper.attack_frame_duration),
    hurt = animation(newImage('resources/characters/pumper/pumper_hurt.png'), 32, 32, data.Pumper.hurt_frame_duration)
}
animations['pumper_projectile'] = animation(newImage('resources/characters/pumper/pumper_projectile.png'), 12, 14, data.PumperProjectile.frame_duration)
animations['explosion_1_big'] = animation(newImage('resources/effects/explosion_1_big.png'), 48, 40, data.Explosion.frame_duration)
animations['explosion_2_big'] = animation(newImage('resources/effects/explosion_2_big.png'), 48, 48, data.Explosion.frame_duration)
animations['explosion_3_big'] = animation(newImage('resources/effects/explosion_3_big.png'), 48, 80, data.Explosion.frame_duration)
animations['explosion_1_small'] = animation(newImage('resources/effects/explosion_1_small.png'), 32, 32, data.Explosion.frame_duration)
animations['hit_1'] = animation(newImage('resources/effects/hit_1.png'), 19, 19, data.Hit.frame_duration)
animations['hit_2'] = animation(newImage('resources/effects/hit_2.png'), 19, 19, data.Hit.frame_duration)
animations['hit_3'] = animation(newImage('resources/effects/hit_3.png'), 19, 19, data.Hit.frame_duration)
animations['shine_1_blue'] = animation(newImage('resources/effects/shine_1_blue.png'), 13, 13, data.Hit.frame_duration)
animations['shine_1_light_blue'] = animation(newImage('resources/effects/shine_1_light_blue.png'), 13, 13, data.Hit.frame_duration)
animations['shine_1_purple'] = animation(newImage('resources/effects/shine_1_purple.png'), 13, 13, data.Hit.frame_duration)
animations['shine_1_red'] = animation(newImage('resources/effects/shine_1_red.png'), 13, 13, data.Hit.frame_duration)
animations['shine_1_dark_green'] = animation(newImage('resources/effects/shine_1_dark_green.png'), 13, 13, data.Hit.frame_duration)
animations['shine_1_light_green'] = animation(newImage('resources/effects/shine_1_light_green.png'), 13, 13, data.Hit.frame_duration)
animations['smoke_1'] = animation(newImage('resources/effects/smoke_1.png'), 12, 12, data.Smoke.frame_duration)
animations['smoke_2'] = animation(newImage('resources/effects/smoke_2.png'), 12, 12, data.Smoke.frame_duration)
animations['smoke_3'] = animation(newImage('resources/effects/smoke_3.png'), 12, 12, data.Smoke.frame_duration)
animations['dust_1'] = animation(newImage('resources/effects/dust_1.png'), 18, 18, data.Dust.frame_duration)
animations['battery'] = {idle = animation(newImage('resources/items/battery.png'), 12, 20, data.Battery.frame_duration)}
animations['jumping_pad'] = animation(newImage('resources/tiles/jumping_pad.png'), 32, 32, data.JumpingPad.frame_duration)

-- Tiles
tiles_data = {}
-- Returns a table of images from tile sheet = name, with tile width = tile_w and height = tile_h.
-- Reads left->right, top->down: first image: x = 1, y = 1; 
-- wth image: x = tile_w, y = 1, last image: x = tile_w, y = tile_h.
local function getImagesFromTileSheet(name, tile_w, tile_h)
    local tiles = {}
    local data = newImageData('resources/tiles/' .. name .. '.png')
    local n_w, n_h = data:getWidth()/tile_w, data:getHeight()/tile_h
    for j = 1, n_h do
        for i = 1, n_w do
            local tile = newImageData(tile_w, tile_h)
            local m, n = 0, 0
            for k = tile_w*(i-1), tile_w*i-1 do
                n = 0
                for l = tile_h*(j-1), tile_h*j-1 do
                    local r, g, b, a = data:getPixel(k, l)
                    tile:setPixel(m, n, r, g, b, a)
                    n = n + 1
                end
                m = m + 1
            end
            table.insert(tiles, newImage(tile))
        end
    end
    return tiles
end
-- Set tile data
tiles_data['temple_tiles'] = getImagesFromTileSheet('temple_tiles', 32, 32)
