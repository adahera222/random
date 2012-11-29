import nme.geom.Point;
import com.haxepunk.HXP;
import com.haxepunk.Entity;
import com.haxepunk.Engine;
import com.haxepunk.utils.Draw;
import com.haxepunk.graphics.Image;
import Utils;

class Boid extends Entity {
    public var position:Vector;
    public var velocity:Vector;
    public var desired_velocity:Vector;
    public var mass:Float;
    public var acceleration:Vector;
    public var steering:Vector;
    public var steering_force:Vector;
    public var max_velocity:Float;
    public var max_force:Float;
    public var behavior:String;
    public var seek_flee_arrival_target:Vector;
    public var flee_radius:Int;
    public var arrival_radius:Int;
    public var slowing:Bool;
    public var pursue_evade_entity:Boid;
    public var pursue_evade_future_entity_position:Vector;
    public var rect:Image;
    public var rect_border:Image;

    public function new(name_:String, w:Int=32, h:Int=32, p:Vector, v:Vector, 
                        mass_:Float=1, max_v:Float, max_f:Float, 
                        flee_r:Int, arrival_r:Int) {
        super(x, y);
        name = name_;
        position = (p == null) ? new Vector():p;
        velocity = (v == null) ? new Vector():v;
        desired_velocity = new Vector();
        mass = mass_;
        acceleration = new Vector();
        steering = new Vector();
        steering_force = new Vector();
        max_velocity = max_v;
        max_force = max_f;
        width = w;
        height = h;
        behavior = "seek";
        seek_flee_arrival_target = null;
        flee_radius = flee_r;
        arrival_radius = arrival_r;
        slowing = false;
        pursue_evade_entity = null;
        pursue_evade_future_entity_position = null;
        rect = Image.createRect(w, h, 0xffffff);
        rect_border = Image.createRect(w+2, h+2, 0x0C1932);
        graphic = rect;
    }

    override public function update() {
        super.update();
        var dt = HXP.elapsed;

        if (behavior == "seek") { 
            seek(seek_flee_arrival_target);
        } else if (behavior == "flee") { 
            flee(seek_flee_arrival_target);
        } else if (behavior == "arrival") { 
            arrival(seek_flee_arrival_target); 
        } else if (behavior == "pursue") {
            pursue(pursue_evade_entity);
        } else if (behavior == "evade") {
            evade(pursue_evade_entity);
        }

        steering_force = steering.truncate(max_force);
        acceleration = steering_force.div(mass);
        velocity = velocity.add(acceleration.mul(dt)).truncate(max_velocity);
        position = position.add(velocity.mul(dt));

        // update super's (Entity) position
        x = position.x;
        y = position.y;
    }

    public function seek(target:Vector) {
        desired_velocity = target.sub(position).normalized().mul(max_velocity);
        steering = desired_velocity.sub(velocity);
    }

    public function flee(target:Vector) {
        var distance:Float;
        desired_velocity = position.sub(target);
        distance = desired_velocity.length;

        if (distance < flee_radius) {
            slowing = true;
            desired_velocity = 
            desired_velocity.normalized().mul(max_velocity).mul(1-(distance/flee_radius));
        } else {
            slowing = false;
            desired_velocity.x = 0;
            desired_velocity.y = 0;
        }

        steering = desired_velocity.sub(velocity);
    }

    public function arrival(target:Vector) {
        var distance:Float;
        desired_velocity = target.sub(position);
        distance = desired_velocity.length;

        if (distance < arrival_radius) {
            slowing = true;
            desired_velocity = 
            desired_velocity.normalize().mul(max_velocity).mul(distance/arrival_radius);
        } else {
            slowing = false;
            desired_velocity = target.sub(position).normalized().mul(max_velocity);
        }

        steering = desired_velocity.sub(velocity);
    }

    public function pursue(target:Boid) {
        var distance:Float = target.position.sub(position).length;
        var t:Float = distance*0.01;
        pursue_evade_future_entity_position = target.position.add(target.velocity.mul(t));
        arrival(pursue_evade_future_entity_position);
    }

    public function evade(target:Boid) {
        var distance:Float = target.position.sub(position).length;
        var t:Float = distance*0.01;
        pursue_evade_future_entity_position = target.position.add(target.velocity.mul(t));
        flee(pursue_evade_future_entity_position);
    }

    private function drawEntity(borderColor:Int, fillColor:Int) {
        rect_border.color = borderColor;
        rect.color = fillColor;
        rect_border.centerOrigin();
        rect.centerOrigin();
        rect_border.angle = 180 - Utils.radToDeg(velocity.angle());
        rect.angle = 180 - Utils.radToDeg(velocity.angle());
        rect_border.render(HXP.buffer, 
                           new Point(x - width/2 - 1, y - height/2 - 1), 
                           HXP.camera);
        rect.render(HXP.buffer, 
                    new Point(x - width/2, y - height/2), 
                    HXP.camera);
    }

    private function drawEntityVector(vector_name:String, color:Int) {
        if (vector_name == "velocity") {
            Draw.linePlus(Std.int(position.x), Std.int(position.y), 
                          Std.int(position.x + velocity.x), 
                          Std.int(position.y + velocity.y), color, 255, 2);
        }

        else if (vector_name == "desired_velocity") {
            Draw.linePlus(Std.int(position.x), Std.int(position.y), 
                          Std.int(position.x + desired_velocity.x), 
                          Std.int(position.y + desired_velocity.y), color, 255, 2);
        }

        else if (vector_name == "acceleration") {
            Draw.linePlus(Std.int(position.x), Std.int(position.y), 
                          Std.int(position.x + acceleration.x),
                          Std.int(position.y + acceleration.y), color, 255, 2);
        }
    }

    private function drawSlowingArea() {
        var color:Int;
        if (slowing) { color = 0xff0000; }
        else { color = 0x000000; }

        if (behavior == "flee") {
            Draw.circlePlus(Std.int(seek_flee_arrival_target.x), 
                            Std.int(seek_flee_arrival_target.y), 
                            flee_radius, color, 255, false, 2);
        } else if (behavior == "arrival") {
            Draw.circlePlus(Std.int(seek_flee_arrival_target.x), 
                            Std.int(seek_flee_arrival_target.y), 
                            arrival_radius, color, 255, false, 2);
        }
    }

    private function drawFutureEntityPosition(color:Int) {
        Draw.circlePlus(Std.int(pursue_evade_future_entity_position.x),
                        Std.int(pursue_evade_future_entity_position.y),
                        5, color, 255, false, 2);
        Draw.linePlus(Std.int(pursue_evade_future_entity_position.x - 10),
                      Std.int(pursue_evade_future_entity_position.y),
                      Std.int(pursue_evade_future_entity_position.x + 10),
                      Std.int(pursue_evade_future_entity_position.y),
                      color, 255, 2);
        Draw.linePlus(Std.int(pursue_evade_future_entity_position.x),
                      Std.int(pursue_evade_future_entity_position.y - 10),
                      Std.int(pursue_evade_future_entity_position.x),
                      Std.int(pursue_evade_future_entity_position.y + 10),
                      color, 255, 2);
    }

    override public function render() {
        if (Utils.equalsAny(behavior, ["seek", "flee", "arrival"])) {
            drawEntity(0x0c1932, 0x3264c8);
            drawSlowingArea();
        }

        else if (Utils.equalsAny(behavior, ["pursue", "evade"])) {
            drawEntity(0x320c19, 0xc83264);
            if (Utils.debug_draw) { drawFutureEntityPosition(0xc83264); }
        }

        if (Utils.debug_draw) {
            drawEntityVector("velocity", 0x00ff00);
            drawEntityVector("desired_velocity", 0x000000);
            drawEntityVector("acceleration", 0xff00ff);
        }
    }
}
