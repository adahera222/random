local PS = struct('creation_time', 'name', 'id', 'x', 'y', 'ps')
Particle = {
    particleInit = function(self)
        self.particle_uid = 0
        self.templates = loadstring("return " .. love.filesystem.read(main_pso))()
        self.particle_systems = {}
        self.particle_to_be_particleRemoved = {}
    end,

    particleCreate = function(self, name, settings)
        self.particle_uid = self.particle_uid + 1
        local ps = self:createPS(self:findTemplateByName(name), settings.visual)
        table.insert(self.particle_systems, PS(love.timer.getTime(), name, self.particle_uid, nil, nil, ps))
        self:particleSet(self.particle_uid, settings)
    end,

    findTemplateByName = function(self, name)
        for k, v in ipairs(self.templates) do
            if v.name == name then return v.template end
        end
    end,

    particleSet = function(self, id, settings)
        local ps = self.particle_systems[findIndexByID(self.particle_systems, id)]
        if settings then
            for k, v in pairs(settings) do
                if k == 'position' then
                    ps.x = v.x
                    ps.y = v.y

                elseif k == 'colors' then
                    ps.ps:setColors(unpack(v))
                end
            end
        end
    end,

    createPS = function(self, template, visual)
        local ps = love.graphics.newParticleSystem(visual, template.buffer_size)
        ps:setBufferSize(template.buffer_size)
        local colors = {}
        for i = 1, 8 do
            if template.colors[i] then
                table.insert(colors, template.colors[i][1])
                table.insert(colors, template.colors[i][2])
                table.insert(colors, template.colors[i][3])
                table.insert(colors, template.colors[i][4])
            end
        end
        ps:setColors(unpack(colors))
        ps:setDirection(degToRad(template.direction))
        ps:setEmissionRate(template.emission_rate)
        ps:setGravity(template.gravity[1], template.gravity[2])
        ps:setLifetime(template.lifetime)
        ps:setOffset(template.offset[1], template.offset[2])
        ps:setParticleLife(template.particle_life[1], template.particle_life[2])
        ps:setRadialAcceleration(template.radial_acc[1], template.radial_acc[2])
        ps:setRotation(degToRad(template.rotation[1]), degToRad(template.rotation[2]))
        ps:setSizeVariation(template.size_variation)
        ps:setSizes(unpack(template.sizes))
        ps:setSpeed(template.speed[1], template.speed[2])
        ps:setSpin(degToRad(template.spin[1]), degToRad(template.spin[2]))
        ps:setSpinVariation(template.spin_variation)
        ps:setSpread(degToRad(template.spread))
        ps:setTangentialAcceleration(template.tangent_acc[1], template.tangent_acc[2])
        return ps
    end,

    particleRemove = function(self, id)
        local i = findIndexByID(self.particle_systems, id)
        if i then table.remove(self.particle_systems, i) end
    end,
    
    particleRemovePostUpdate = function(self)
        for _, id in ipairs(self.particle_to_be_particleRemoved) do self:particleRemove(id) end
        self.particle_to_be_particleRemoved = {}
    end,

    particleUpdate = function(self, dt)
        for i, p in ipairs(self.particle_systems) do
            p.ps:update(dt)
            if p.ps:isEmpty() then table.insert(self.particle_to_be_particleRemoved, p.id) end
        end
        self:particleRemovePostUpdate()
    end,

    particleDraw = function(self)
        for _, p in ipairs(self.particle_systems) do
            if p.x and p.y then
                love.graphics.draw(p.ps, p.x, p.y)
            end
        end
    end
}
