local message = {}

-- name: string, action: function
function message.add(name, action)
    message[name] = action
end

-- name: string
function message.remove(name)
    message[name] = nil
end

-- name: string, ...: parameters
function message.trigger(name, ...)
    return message[name](...)
end

return message
