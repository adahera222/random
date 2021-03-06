import com.haxepunk.Engine;
import com.haxepunk.HXP;

class Main extends Engine
{

	public static inline var kScreenWidth:Int = 600;
	public static inline var kScreenHeight:Int = 480;
	public static inline var kFrameRate:Int = 60;
	public static inline var kClearColor:Int = 0xffffff;
	public static inline var kProjectName:String = "HaxePunk";

	public function new() {
		super(kScreenWidth, kScreenHeight, kFrameRate, false);
	}

	override public function init() {
		HXP.screen.color = kClearColor;
		HXP.screen.scale = 1;
		HXP.world = new GameWorld();
	}

    override public function focusGained() {
        HXP.world.active = true;
    }

    override public function focusLost() {
        HXP.world.active = false;
    }

	public static function main() {
		new Main();
	}

}
