import com.haxepunk.HXP;
import com.haxepunk.World;
import com.haxepunk.utils.Draw;
import com.haxepunk.utils.Input;

// Taken from Real Time Collision Detection by Christen Ericson,
// Chapter 5, sections 5.1.2, 5.1.3 and 5.1.4.

class AABBWorld extends World {
    private var min:Vector;
    private var max:Vector;
    private var center:Vector;
    private var p:Vector;
    private var q:Vector;
    private var dragging:Bool = false;
    private var diff:Vector;
    private var width:Int;
    private var height:Int;

    public function new() {
        super();    
        min = new Vector(200, 200);
        max = new Vector(400, 280);
        width = Std.int(max.x - min.x);
        height = Std.int(max.y - min.y);
        center = new Vector(300, 240);
        p = new Vector();
        q = new Vector();
        diff = new Vector();
    }

    override public function begin() {
        super.begin();
        Draw.setTarget(HXP.buffer);
    }

    override public function update() {
        p.x = HXP.stage.mouseX;
        p.y = HXP.stage.mouseY;
        q = closestPointToAABB(p, min, max);
        input();
        min.x = center.x - width/2;
        min.y = center.y - height/2;
        max.x = center.x + width/2;
        max.y = center.y + height/2;
    }

    override public function render() {
        Draw.linePlus(Std.int(min.x), Std.int(min.y), Std.int(min.x), 
                      Std.int(max.y), 0x000000, 255);
        Draw.linePlus(Std.int(min.x), Std.int(min.y), Std.int(max.x), 
                      Std.int(min.y), 0x000000, 255);
        Draw.linePlus(Std.int(max.x), Std.int(max.y), Std.int(min.x), 
                      Std.int(max.y), 0x000000, 255);
        Draw.linePlus(Std.int(max.x), Std.int(max.y), Std.int(max.x), 
                      Std.int(min.y), 0x000000, 255);
        Draw.linePlus(Std.int(p.x), Std.int(p.y), Std.int(q.x), Std.int(q.y),
                      0x000000, 255);
        Draw.circlePlus(Std.int(center.x), Std.int(center.y), 6.5, 0x163264, 255, true);
        Draw.circlePlus(Std.int(center.x), Std.int(center.y), 5, 0x3264C8, 255, true);
        Draw.circlePlus(Std.int(p.x), Std.int(p.y), 5, 0x000000, 255, true);
        Draw.circlePlus(Std.int(q.x), Std.int(q.y), 8.5, 0x640808, 255, true);
        Draw.circlePlus(Std.int(q.x), Std.int(q.y), 7, 0xC81616, 255, true);
    }

    public function input() {
        if (p.x >= HXP.engine.width || p.x <= 0) { dragging = false; }
        if (p.y >= HXP.engine.height || p.y <= 0) { dragging = false; }
        

        if (dragging) {
            center.x = p.x - diff.x;
            center.y = p.y - diff.y;
        }

        if (Input.mousePressed && pointInsideCircle(p, center, 10)) {
            dragging = true;
            diff.x = p.x - center.x;
            diff.y = p.y - center.y;
        }

        if (Input.mouseReleased) {
            dragging = false;
        }
    }

    public function onEntry() {
        p = new Vector(-10, -10);
        q = new Vector(-10, -10);
        diff = new Vector();
    }

    private function pointInsideCircle(point:Vector, circle:Vector, radius:Float):Bool {
        if ((point.x <= circle.x + radius) && (point.x >= circle.x - radius) &&
            (point.y <= circle.y + radius) && (point.y >= circle.y - radius)) {
            return true;
        } else { return false; }
    }

    // Given point p, return the point q on or in AABB (min, max) that is closest to p
    private function closestPointToAABB(p:Vector, min:Vector, max:Vector):Vector {
        // For each coordinate axis, if the point coordinate value is
        // outside box, clamp it to the box, else keep it as is
        var v = new Vector();
        var q = new Vector();
        // x axis
        v.x = p.x;
        if (v.x < min.x) { v.x = min.x; }
        if (v.x > max.x) { v.x = max.x; }
        q.x = v.x;
        // y axis
        v.y = p.y;
        if (v.y < min.y) { v.y = min.y; }
        if (v.y > max.y) { v.y = max.y; }
        q.y = v.y;
        return q;
    }
}
