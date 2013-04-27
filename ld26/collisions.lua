local collision_mask = struct('categories', 'masks')

collision_masks = {}
collision_masks['Player'] = collision_mask({1}, {})
collision_masks['EntityRect'] = collision_mask({2}, {})
collision_masks['Projectile'] = collision_mask({3}, {1, 3})
