import com.haxepunk.HXP;
import com.haxepunk.Engine;
import com.haxepunk.utils.Key;
import com.haxepunk.utils.Draw;
import com.haxepunk.utils.Input;
import com.haxepunk.graphics.Text;

class Main extends Engine {
	public static inline var kScreenWidth:Int = 600;
	public static inline var kScreenHeight:Int = 480;
	public static inline var kFrameRate:Int = 30;
	public static inline var kClearColor:Int = 0xffffff;
	public static inline var kProjectName:String = "HaxePunk";
    public var pointLine:LineWorld;
    public var pointAABB:AABBWorld;
    public var pointOBB:OBBWorld;
    private var current_text:String = "";
    private var text_options:TextOptions;

	public function new() {
		super(kScreenWidth, kScreenHeight, kFrameRate, false);
        pointLine = new LineWorld();
        pointAABB = new AABBWorld();
        pointOBB = new OBBWorld();
        text_options = {font: "font/visitor1.ttf", size: 24, color: 0x000000};
        HXP.world = pointLine;
        current_text = "Point to Line";
	}

	override public function init() {
#if debug
	#if flash
		if (flash.system.Capabilities.isDebugger)
	#end
		{
			HXP.console.enable();
		}
#end
		HXP.screen.color = kClearColor;
		HXP.screen.scale = 1;
	}

    override public function update() {
        super.update();
        input();
    }

    override public function render() {
        super.render();
        Draw.text(current_text, 10, 10, text_options);
    }

	public static function main() {
		new Main();
	}

    public function input() {
        if (Input.check(Key.DIGIT_1)) { 
            if (!Std.is(HXP.world, LineWorld)) {
                pointLine.onEntry();
            }
            HXP.world = pointLine; 
            current_text = "Point to Line";
        }

        if (Input.check(Key.DIGIT_2)) { 
            if (!Std.is(HXP.world, AABBWorld)) {
                pointAABB.onEntry();
            }
            HXP.world = pointAABB; 
            current_text = "Point to AABB"; 
        }

        if (Input.check(Key.DIGIT_3)) {
            if (!Std.is(HXP.world, OBBWorld)) {
                pointOBB.onEntry();
            }
            HXP.world = pointOBB;
            current_text = "Point to OBB";
        }
    }
}
