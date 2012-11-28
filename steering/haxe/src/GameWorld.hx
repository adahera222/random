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
    public var entity:Boid;
    private var current_behavior:String;
    private var current_radius:Int;
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
        add(new Boid("entity", 20, 20, new Vector(400, 300), 
                     new Vector(0, 0), 1, 150, 100, 200, 200));
        Utils.debug_draw = true;
        text_options = {font: "font/visitor1.ttf", size: 24, color: 0x000000};
    }

    private function input() {
        if (Input.pressed(Key.D)) { Utils.debug_draw = !Utils.debug_draw; }
        if (Input.pressed(Key.DIGIT_1)) { current_behavior = "seek"; }
        if (Input.pressed(Key.DIGIT_2)) { current_behavior = "flee"; current_radius = FLEE_RADIUS; }
        if (Input.pressed(Key.DIGIT_3)) { current_behavior = "arrival"; current_radius = ARRIVAL_RADIUS; }
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

        if (Utils.equalsAny(current_behavior, ["seek", "flee", "arrival"])) {
            entity.behavior = current_behavior;
            entity.seek_flee_arrival_target = new Vector(mX, mY);
            entity.update();
        }

        // If called before will update all entities without setting behaviors, targets, ...
        super.update();
    }

    override public function render() {
        super.render();

        // Draw mouse position
        Draw.circle(mX, mY, 5, 0x000000);

        // Print current behavior
        Draw.text(current_behavior, 10, 10, text_options);
    }
}
