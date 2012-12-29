-- There are some timing related constructs that appear very often 
-- while developing games. One such construct is as follows:
--
-- function update(dt)
--   counter = counter + dt
--   if counter >= action_delay then
--     counter = 0
--     action()
--   end
-- end 
--
-- This performs action() after action_delay seconds.
-- It would be useful to have a function or set of functions that would handle 
-- all that (creating at least two control variables + if + increment) for me.
-- Such function could be defined like this: after(n, action). And so we could 
-- change the code from lines 5-11 to:
--
-- function update(dt)
--   after(action_delay, action()
-- end
--
-- There are other constructs that serve different purposes. Here's a list:
-- (time this function was called = t)
--
-- after(n, action): performs action at time t+n. 
-- every(n, c, action): performs action at times t+n, t+2n, t+3n, ..., up to c times.
--                      If c is omitted will run until cancelled.
-- do_for(n, action): performs action every frame until time t+n. 
-- cancel(id): removes timer with id = id from the timers list.
-- trigger(): triggers all stored actions and shuts down timer, for testing purposes.
--
-- It would also be useful if we could combine after, do_for and every to create
-- complex timing behaviors. For instance:
--
-- do_for(5, player.invincility).after(0, player.selfExplosion)
-- The player is invincible for 5 seconds and when that ends he explodes.
-- If it were .after(2, player.selfExplosion) the player would have a 2
-- second delay between invincibility end and self explosion.
-- 
-- every(2, enemy.chooseTarget).after(1, enemy.shoot)
-- The enemy will choose a target every 2 seconds and will shoot
-- 1 second after the every call is cancelled (or do_for it has been
-- run c times, if c were not omitted).
--
-- There's another possibility:
-- every(2, enemy.chooseTarget).'interleave'.after(1, enemy.shoot)
-- (can I even do the .'interleave'. part...?)
-- The enemy will choose a target at t = 2 and at t = 3 will shoot.
-- Then it will choose a target at t = 5 and at t = 6 will shoot...
--
-- So, after and do_for behave as you would expect. Composition makes
-- the actions happen linearly (after action1 is performed, action2
-- will be performed (using the modifiers)). With every that can be
-- the case but it can also be interleaved.

local struct = require 'struct'
local Action = struct('type', 'id', 'n', 'c', 'action', 'counter', 'parameters')

Chrono = {}
Chrono.__index = Chrono

function Chrono.new()
    return setmetatable({uid = 0, actions = {}}, Chrono)
end

function Chrono:update(dt)
    for _, action_struct in ipairs(self.actions) do
        action_struct.counter = action_struct.counter + dt

        if action_struct.type == 'after' then
            if action_struct.counter >= action_struct.n then
                action_struct.action(action_struct.parameters)
                self:remove(action_struct.id)
            end

        elseif action_struct.type == 'every' then
            if action_struct.counter >= action_struct.n then
                if not action_struct.c then
                    action_struct.action(action_struct.parameters)
                else 
                    if action_struct.c >= 1 then
                        action_struct.action(action_struct.parameters) 
                        action_struct.c = action_struct.c - 1
                    else self:remove(action_struct.id) end
                end
                action_struct.counter = 0
            end

        elseif action_struct.type == 'do_for' then
            if action_struct.counter < action_struct.n then
                action_struct.action(action_struct.parameters)
            else self:remove(action_struct.id) end
        end
    end
end

function Chrono:after(n, action, ...)
    self.uid = self.uid + 1
    return self:add(Action('after', self.uid, n, nil, action, 0, ...))
end

function Chrono:every(n, c, action, ...)
    self.uid = self.uid + 1
    return self:add(Action('every', self.uid, n, c, action, 0, ...))
end

function Chrono:do_for(n, action, ...)
    self.uid = self.uid + 1
    return self:add(Action('do_for', self.uid, n, nil, action, 0, ...))
end

function Chrono:cancel(id)
    self:remove(id)
end

function Chrono:trigger()
    
end

function Chrono:add(action_struct)
    table.insert(self.actions, action_struct)
    return self.uid
end

function Chrono:remove(id)
    for i, action_struct in ipairs(self.actions) do
        if action_struct.id == id then 
            table.remove(self.actions, i)
            return
        end
    end
end

setmetatable(Chrono, {__call = function(_, _) return Chrono.new() end})
