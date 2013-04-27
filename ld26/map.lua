local solid = struct('x', 'y', 'w', 'h')

map = {
    -- floor bottom
    solid(142, 64+376, 284, 16),
    solid(458, 64+376, 284, 16),

    -- ceil top
    solid(134, 8, 268, 16),
    solid(466, 8, 268, 16),

    -- wall left/right
    solid(8, 16+208, 16, 416),
    solid(592, 16+208, 16, 416),

    -- first floor
    solid(300, 64+312, 344, 16),
    solid(72, 64+360, 112, 16),
    solid(528, 64+360, 112, 16),

    -- second floor
    solid(300, 64+184, 344, 16),
    solid(72, 64+248, 112, 16),
    solid(528, 64+248, 112, 16),

    -- third floor
    solid(300, 64+56, 344, 16),
    solid(72, 64+120, 112, 16),
    solid(528, 64+120, 112, 16),
}
