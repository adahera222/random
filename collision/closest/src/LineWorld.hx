import com.haxepunk.HXP;
import com.haxepunk.World;
import com.haxepunk.utils.Draw;
import com.haxepunk.utils.Input;

// Taken from Real Time Collision Detection by Christen Ericson,
// Chapter 5, sections 5.1.2, 5.1.3 and 5.1.4.

class LineWorld extends World {
    private var a:Vector;
    private var b:Vector;
    private var c:Vector;
    private var d:Vector;
    private var draggingPoints:Array<Bool>;
    private var diffPoints:Array<Vector>;

    public function new() {
        super();
        a = new Vector(200, 240);
        b = new Vector(400, 240);
        c = new Vector();
        d = new Vector();
        draggingPoints = [false, false];
        diffPoints = [new Vector(), new Vector()];
    }

    override public function begin() {
        super.begin();
        Draw.setTarget(HXP.buffer);
    }

    override public function update() {
        c.x = HXP.stage.mouseX;
        c.y = HXP.stage.mouseY;
        d = closestPointToSegment(c, a, b);
        input();
    }

    override public function render() {
        Draw.linePlus(Std.int(a.x), Std.int(a.y), Std.int(b.x), Std.int(b.y),
                      0x000000, 255);
        Draw.linePlus(Std.int(c.x), Std.int(c.y), Std.int(d.x), Std.int(d.y),
                      0x000000, 255);
        Draw.circlePlus(Std.int(a.x), Std.int(a.y), 6.5, 0x163264, 255, true);
        Draw.circlePlus(Std.int(a.x), Std.int(a.y), 5, 0x3264C8, 255, true);
        Draw.circlePlus(Std.int(b.x), Std.int(b.y), 6.5, 0x163264, 255, true);
        Draw.circlePlus(Std.int(b.x), Std.int(b.y), 5, 0x3264C8, 255, true);
        Draw.circlePlus(Std.int(c.x), Std.int(c.y), 5, 0x000000, 255, true);
        Draw.circlePlus(Std.int(d.x), Std.int(d.y), 8.5, 0x640808, 255, true);
        Draw.circlePlus(Std.int(d.x), Std.int(d.y), 7, 0xC81616, 255, true);
    }

    public function input() {
        if (c.x >= HXP.engine.width || c.x <= 0) { draggingPoints = [false, false]; }
        if (c.y >= HXP.engine.height || c.y <= 0) { draggingPoints = [false, false]; }

        if (draggingPoints[0]) {
            a.x = c.x - diffPoints[0].x;
            a.y = c.y - diffPoints[0].y;
        }

        if (draggingPoints[1]) {
            b.x = c.x - diffPoints[1].x;
            b.y = c.y - diffPoints[1].y;
        }

        if (Input.mousePressed && pointInsideCircle(c, a, 10)) {
            draggingPoints[0] = true;
            diffPoints[0].x = c.x - a.x;
            diffPoints[0].y = c.y - a.y;
        }

        if (Input.mousePressed && pointInsideCircle(c, b, 10)) {
            draggingPoints[1] = true;
            diffPoints[1].x = c.x - b.x;
            diffPoints[1].y = c.y - b.y;
        }

        if (Input.mouseReleased) {
            draggingPoints[0] = false;
            draggingPoints[1] = false;
        }
    }

    public function onEntry() {
        c = new Vector(-10, -10);
        d = new Vector(-10, -10);
        diffPoints = [new Vector(), new Vector()];
    }
    
    private function pointInsideCircle(point:Vector, circle:Vector, radius:Float):Bool {
        if ((point.x <= circle.x + radius) && (point.x >= circle.x - radius) &&
            (point.y <= circle.y + radius) && (point.y >= circle.y - radius)) {
            return true;
        } else { return false; }
    }

    // Given segment ab and point c, computes closest point d on ab.
    private function closestPointToSegment(c:Vector, a:Vector, b:Vector):Vector {
        var ab = b.sub(a);
        // Project c onto ab, computing parametrized position d(t) = a + t*(b - a)
        var t = (c.sub(a)).dot(ab)/ab.dot(ab);
        // If outside segment, clamp t (and therefore d) to the closest endpoint
        if (t < 0) { t = 0; }
        if (t > 1) { t = 1; }
        // Compute projected position from the clamped t
        var d = a.add(ab.mul(t)); // d = a + t*ab
        return d; 
    }
}
