function loadCollisions()
    local collision_mask = struct('categories', 'masks')
    collision_masks = {}
    collision_masks['Player'] = collision_mask({1}, {})
    collision_masks['Prop'] = collision_mask({1}, {})
    collision_masks['NotCollidable'] = collision_mask({1}, {1})

    local size = struct('w', 'h', 'offset_x', 'offset_y')
    sizes = {}
    sizes['Player'] = size(40, 28, 7, 64)
    sizes['rock'] = size(52, 18, 0, 0)
    sizes['boulder'] = size(152, 67, 0, 67)
    sizes['bush'] = size(89, 20, 0, 35)
    sizes['tree'] = size(46, 46, 54, 242)
end
