Player = class('Player', Entity)
Player.static.MV = 200

Player:include(PhysicsRectangle)
Player:include(Input)
Player:include(Collector)
Player:include(Movable)
Player:include(ActorVisual)

function Player:initialize(world, x, y)
    Entity.initialize(self, 'Player')
    self:physicsRectangleInit(world, x, y, 'dynamic', sizes.Player.w, sizes.Player.h)
    self.body:setFixedRotation(true)
    self:inputInit(player_keys)
    self:collectorInit()
    self:movableInit(Player.MV)
    self:visualInit(player_animations, sizes.Player.offset_x, sizes.Player.offset_y)
end

function Player:update(dt)
    Entity.update(self, dt)
    self:inputUpdate(dt)
    self:movableUpdate(dt)
    self:visualUpdate(dt)
end

function Player:draw()
    self:visualDraw()
    self:physicsRectangleDraw()
end
