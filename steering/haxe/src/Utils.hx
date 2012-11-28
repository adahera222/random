class Utils {

    static public var debug_draw:Bool;

    static public function radToDeg(rad:Float):Float {
        return rad*180/Math.PI;
    }

    static public function equalsAll(value:String, args:Array<String>):Bool {
        for (i in 0...args.length) {
            if (value != args[i]) {
                return false;
            }
        }
        return true;
    }

    static public function equalsAny(value:String, args:Array<String>):Bool {
        for (i in 0...args.length) {
            if (value == args[i]) {
                return true;
            }
        }
        return false;
    }
}
