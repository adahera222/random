import com.haxepunk.World;
import com.haxepunk.HXP;
import com.haxepunk.utils.Draw;
import com.haxepunk.utils.Key;
import com.haxepunk.utils.Input;
import com.haxepunk.graphics.Text;
import Utils;

class GameWorld extends World {
    static inline var FLEE_RADIUS = 200;
    static inline var ARRIVAL_RADIUS = 200;
    private var entity:Boid;
    private var pursue_evade_entity:Boid;
    private var current_behavior:String;
    private var current_radius:Int;
    private var current_target_entity:Boid;
    private var mX:Int;
    private var mY:Int;
    private var text_options:TextOptions;

    public function new() {
        super();
        current_behavior = "seek";
        current_radius = 200;
    }

    override public function begin() {
        super.begin();
        Draw.setTarget(HXP.buffer);
        Utils.debug_draw = true;
        text_options = {font: "font/visitor1.ttf", size: 24, color: 0x000000};

        add(new Boid("entity", 20, 20, new Vector(400, 300), 
                     new Vector(0, 0), 1, 150, 100, FLEE_RADIUS, ARRIVAL_RADIUS));
        add(new Boid("pursue_evade_entity", 10, 10, new Vector(500, 400),
                     new Vector(0, 0), 1, 300, 200, FLEE_RADIUS, ARRIVAL_RADIUS));
    }

    override public function update() {
        input();
        mX = Std.int(HXP.stage.mouseX);
        mY = Std.int(HXP.stage.mouseY);
        
        /* cast doesn't work on Windows target...
         * var entities:Array<Boid> = [];
         * getClass(Boid, entities);
         * entity = entities.pop();
         */
        
        entity = cast(getInstance("entity"), Boid);
        pursue_evade_entity = cast(getInstance("pursue_evade_entity"), Boid);

        if (Utils.equalsAny(current_behavior, ["seek", "flee", "arrival"])) {
            entity.behavior = current_behavior;
            entity.seek_flee_arrival_target = new Vector(mX, mY);
            entity.update();
        }

        else if (Utils.equalsAny(current_behavior, ["pursue", "evade"])) {
            entity.behavior = "seek";
            entity.seek_flee_arrival_target = new Vector(mX, mY);
            entity.update();
            pursue_evade_entity.behavior = current_behavior;
            pursue_evade_entity.pursue_evade_entity = current_target_entity;
            pursue_evade_entity.update();
        }
    }

    override public function render() {
        entity = cast(getInstance("entity"), Boid);
        pursue_evade_entity = cast(getInstance("pursue_evade_entity"), Boid);

        entity.render();
        if (Utils.equalsAny(current_behavior, ["pursue", "evade"])) { 
            pursue_evade_entity.render();
        }

        // Draw mouse position
        Draw.circle(mX, mY, 5, 0x000000);

        // Print current behavior
        Draw.text(current_behavior, 10, 10, text_options);
    }

    private function input() {
        if (Input.pressed(Key.D)) { Utils.debug_draw = !Utils.debug_draw; }
        if (Input.pressed(Key.DIGIT_1)) { current_behavior = "seek"; }
        if (Input.pressed(Key.DIGIT_2)) { current_behavior = "flee"; current_radius = FLEE_RADIUS; }
        if (Input.pressed(Key.DIGIT_3)) { current_behavior = "arrival"; current_radius = ARRIVAL_RADIUS; }
        if (Input.pressed(Key.DIGIT_4)) { current_behavior = "pursue"; current_target_entity = entity; }
        if (Input.pressed(Key.DIGIT_5)) { current_behavior = "evade"; current_target_entity = entity; }
    }
}
