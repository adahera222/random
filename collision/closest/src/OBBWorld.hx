import com.haxepunk.World;
import com.haxepunk.HXP;
import com.haxepunk.utils.Draw;
import com.haxepunk.utils.Input;

// Taken from Real Time Collision Detection by Christen Ericson,
// Chapter 5, sections 5.1.2, 5.1.3 and 5.1.4.

class OBBWorld extends World {
    private var center:Vector;
    private var e:Vector;
    private var u:Array<Vector>;
    private var p:Vector;
    private var q:Vector;
    private var a:Vector;
    private var b:Vector;
    private var c:Vector;
    private var d:Vector;
    private var dp:Vector;
    private var ul:Int = 20;
    private var angle:Float;
    private var dragging:Bool;

    public function new() {
       super(); 
       center = new Vector(300, 240);
       e = new Vector(100, 40);
       u = [new Vector(1, 0), new Vector(0, -1)];
       angle = u[0].angle();
       p = new Vector();
       q = new Vector();
       a = new Vector();
       b = new Vector();
       c = new Vector();
       d = new Vector();
       dp = new Vector(center.x + ul*u[0].x, center.x + ul*u[0].y);
    }

    override public function begin() {
        super.begin();
        Draw.setTarget(HXP.buffer); 
    }

    override public function update() {
        p.x = HXP.stage.mouseX;
        p.y = HXP.stage.mouseY;
        q = closestPointToOBB(p, center, u[0], u[1], e);
        input();
        u[0].x = Math.cos(-angle);
        u[0].y = -Math.sin(-angle);
        u[1] = u[0].perp();
        a = center.sub(u[0].mul(e.x)).sub(u[1].mul(e.y));
        b = center.sub(u[0].mul(e.x)).add(u[1].mul(e.y));
        c = center.add(u[0].mul(e.x)).sub(u[1].mul(e.y));
        d = center.add(u[0].mul(e.x)).add(u[1].mul(e.y));
        dp.x = center.x + ul*u[0].x;
        dp.y = center.y + ul*u[0].y;
    }

    override public function render() {
        Draw.linePlus(Std.int(center.x), Std.int(center.y),
                      Std.int(center.x + ul*u[0].x), 
                      Std.int(center.y + ul*u[0].y), 
                      0x000000, 255);
        Draw.linePlus(Std.int(center.x), Std.int(center.y),
                      Std.int(center.x + ul*u[1].x),
                      Std.int(center.y + ul*u[1].y),
                      0x000000, 255);
        Draw.linePlus(Std.int(a.x), Std.int(a.y), Std.int(b.x), Std.int(b.y),
                      0x000000, 255);
        Draw.linePlus(Std.int(a.x), Std.int(a.y), Std.int(c.x), Std.int(c.y),
                      0x000000, 255);
        Draw.linePlus(Std.int(b.x), Std.int(b.y), Std.int(d.x), Std.int(d.y),
                      0x000000, 255);
        Draw.linePlus(Std.int(c.x), Std.int(c.y), Std.int(d.x), Std.int(d.y),
                      0x000000, 255);
        Draw.linePlus(Std.int(p.x), Std.int(p.y), Std.int(q.x), Std.int(q.y),
                      0x000000, 255);
        Draw.circlePlus(Std.int(p.x), Std.int(p.y), 5, 0x000000, 255, true);
        Draw.circlePlus(Std.int(center.x + ul*u[0].x),
                        Std.int(center.y + ul*u[0].y), 6.5, 0x163264, 255, true);
        Draw.circlePlus(Std.int(center.x + ul*u[0].x),
                        Std.int(center.y + ul*u[0].y), 5, 0x3264C8, 255, true);
        Draw.circlePlus(Std.int(center.x + ul*u[1].x),
                        Std.int(center.y + ul*u[1].y), 5, 0x000000, 255, true);
        Draw.circlePlus(Std.int(q.x), Std.int(q.y), 8.5, 0x640808, 255, true);
        Draw.circlePlus(Std.int(q.x), Std.int(q.y), 7, 0xC81616, 255, true);
    }

    // Refactor all this drawing bs -- one dayyyyyy ----
    // function drawLine(x, y, color) {
    //      Draw.linePlus(Std.int(x.x), Std.int(x.y), Std.int(y.x), Std.int(y.y),
    //                    color, 255);
    // }

    public function input() {
        if (p.x >= HXP.engine.width || p.x <= 0) { dragging = false; }
        if (p.y >= HXP.engine.height || p.y <= 0) { dragging = false; }

        if (dragging) {
            angle = p.sub(center).angle();
        }

        if (Input.mousePressed && pointInsideCircle(p, dp, 10)) {
            dragging = true;
        }

        if (Input.mouseReleased) {
            dragging = false;        
        }
    }

    public function onEntry() {
       p = new Vector(-10, -10);
       q = new Vector(-10, -10);
    }

    private function pointInsideCircle(point:Vector, circle:Vector, radius:Float):Bool {
        if ((point.x <= circle.x + radius) && (point.x >= circle.x - radius) &&
            (point.y <= circle.y + radius) && (point.y >= circle.y - radius)) {
            return true;
        } else { return false; }
    }

    // Given point p, return point q on or in OBB (center, u0, u1), closest to p
    private function closestPointToOBB(p:Vector, center:Vector, 
                                       u0:Vector, u1:Vector, e:Vector):Vector {
        var d = p.sub(center);
        // Start result at center of box; make steps from there
        var q = center;
        // Project d onto that axis to get the distance
        // along the axis of d from the box center
        // u0 axis
        var dist = d.dot(u0);
        // If distance farther than the box extends, clamp to the box
        if (dist > e.x) { dist = e.x; }
        if (dist < -e.x) { dist = -e.x; }
        // Step that distance along the axis to get the world coordinate
        q = q.add(u0.mul(dist));
        // u1 axis
        dist = d.dot(u1);
        if (dist > e.y) { dist = e.y; }
        if (dist < -e.y) { dist = -e.y; }
        q = q.add(u1.mul(dist));
        return q; 
    }
}
