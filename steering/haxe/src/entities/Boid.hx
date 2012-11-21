package entities;

import nme.display.BitmapData;
import com.haxepunk.utils.Input;
import com.haxepunk.Entity;
import com.haxepunk.math.Vector;
import com.haxepunk.graphics.Image;
import nme.display.BitmapData;
import nme.display.Graphics;
import nme.display.Sprite;
import com.haxepunk.HXP;
import com.haxepunk.utils.Draw;
import com.haxepunk.Engine;

class Boid extends Entity {

    public var target:Vector;
    public var position:Vector;
    public var velocity:Vector;
    public var desired:Vector;
    public var steering:Vector;
    public var mass:Float;
    public var max_velocity:Float;
    public var max_force:Float;
    public var sprite:Sprite;
    public var arrivalRadius:Float;
    public var fleeRadius:Float;
    public var inCircle:Bool;
    public var bArrival:Bool;

    public function new(x:Int, y:Int, mass_:Float, max_velocity_:Float, max_force_:Float) {
        super(x, y);
        target = new Vector(0, 0);
        position = new Vector(x, y);
        velocity = new Vector(0, 0);
        desired = new Vector(0, 0);
        steering = new Vector(0, 0);
        mass = mass_;
        max_velocity = max_velocity_;
        max_force = max_force_;
        sprite = new Sprite();
        HXP.engine.addChild(sprite);
        arrivalRadius = 200;
        fleeRadius = 100;
        inCircle = false;
        bArrival = false;
    }

    override public function update() {
        super.update();
        target.x = Input.mouseX;
        target.y = Input.mouseY;


        if (bArrival) {
            if (sub(target, position).length <= arrivalRadius) {
                inCircle = true;
            } else { 
                inCircle = false; 
            }
            steering = arrival(target);
        } else {
            if (sub(target, position).length <= fleeRadius) {
                inCircle = true;
            } else { 
                inCircle = false; 
            }
            steering = flee(target);
        }

        steering = truncate(steering, max_force);
        steering = scaleBy(steering, 1/mass);
        velocity = truncate(add(velocity, steering), max_velocity);
        position = add(position, velocity);

        x = position.x;
        y = position.y;
    }

    override public function render() {
        sprite.graphics.clear();
        sprite.graphics.beginFill(0x3264C8);
        sprite.graphics.drawRect(x - 16, y - 16, 32, 32);
        sprite.graphics.endFill();
        sprite.graphics.lineStyle(1.5, 0x0C1932);
        sprite.graphics.drawRect(x - 16, y - 16, 32, 32);
        sprite.graphics.lineStyle(1.5, 0x000000);
        sprite.graphics.moveTo(x, y);
        sprite.graphics.lineTo(x + 30*desired.x, y + 30*desired.y);
        if (inCircle) {
            sprite.graphics.lineStyle(1.5, 0xff0000);
        } else {
            sprite.graphics.lineStyle(1.5, 0x000000);
        }

        if (bArrival) {
            sprite.graphics.drawCircle(target.x, target.y, arrivalRadius);
        } else {
            sprite.graphics.drawCircle(target.x, target.y, fleeRadius);
        }

        sprite.graphics.lineStyle(1.5, 0x00ff00);
        sprite.graphics.moveTo(x, y);
        sprite.graphics.lineTo(x + 30*velocity.x, y + 30*velocity.y);
        sprite.graphics.lineStyle(1.5, 0xff00ff);
        sprite.graphics.moveTo(x, y);
        sprite.graphics.lineTo(x + 3000*steering.x, y + 3000*steering.y);

        /*
        Draw.rect(Std.int(x) - 16, Std.int(y) - 16, 32, 32, 0xff0000);

        Draw.line(Std.int(x), Std.int(y), 
                  Std.int(x + 30*desired.x), Std.int(y + 30*desired.y), 0x000000);
        Draw.line(Std.int(x), Std.int(y),
                  Std.int(x + 30*velocity.x), Std.int(y + 30*velocity.y), 0x00dd00);
        Draw.line(Std.int(x), Std.int(y),
                  Std.int(x + 3000*steering.x), Std.int(y + 3000*steering.y), 0xff00ff);
        */
    }

    public function radToDeg(rad:Float):Float {
        return rad*180/Math.PI;
    }

    public function seek(target:Vector):Vector {
        var force:Vector;
        force = new Vector(0, 0);
        desired = scaleBy(normalize(sub(target, position)), max_velocity);
        force = sub(desired, velocity);
        return force;
    }

    public function flee(target:Vector) {
        var force:Vector;
        var distance:Float;
        force = new Vector(0, 0);
        desired = sub(position, target);
        distance = desired.length;

        if (distance < fleeRadius) {
            desired = scaleBy(scaleBy(normalize(desired), max_velocity), 1-(distance/fleeRadius));
        } else {
            desired.x = 0;
            desired.y = 0;
        }
        force = sub(desired, velocity);
        return force;
    }

    public function arrival(target:Vector) {
        var force:Vector;
        var distance:Float;
        force = new Vector(0, 0);
        desired = sub(target, position);
        distance = desired.length;

        if (distance < arrivalRadius) {
            desired = scaleBy(scaleBy(normalize(desired), max_velocity), (distance/arrivalRadius));
        } else {
            desired = scaleBy(normalize(sub(target, position)), max_velocity);
        }
        force = sub(desired, velocity);
        return force;
    }

    public function truncate(vector:Vector, max:Float):Vector {
        var s:Float;
        s = max/vector.length;
        if (s >= 1) {
            s = 1;
        }
        vector.x *= s;
        vector.y *= s;
        return vector;
    }

    public function add(vector1:Vector, vector2:Vector):Vector {
        var r:Vector;
        r = new Vector(0, 0);
        r.x = vector1.x + vector2.x;
        r.y = vector1.y + vector2.y;
        return r;
    }

    public function sub(vector1:Vector, vector2:Vector):Vector {
        var r:Vector;
        r = new Vector(0, 0);
        r.x = vector1.x - vector2.x;
        r.y = vector1.y - vector2.y;
        return r;
    }

    public function normalize(vector:Vector):Vector {
        var l = vector.length;
        if (l > 0) {
            vector.x /= l;
            vector.y /= l;
        }
        return vector;
    }

    public function scaleBy(vector:Vector, n:Float):Vector {
        vector.x *= n;
        vector.y *= n;
        return vector;
    }

    public function angle(vector:Vector):Float {
        var t:Float;
        t = Math.atan2(vector.y, vector.x);
        return t;
    }
}
