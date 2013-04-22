message_system = require 'message'

message_system.add("PRINT N", function(n) print(n) end)
message_system.trigger("PRINT N", 2, 3)
message_system.remove("PRINT N")
