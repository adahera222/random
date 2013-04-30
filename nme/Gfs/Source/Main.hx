import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;
import nme.text.TextField;
import nme.text.TextFieldAutoSize;
import nme.text.TextFormat;

class Main extends Sprite {

	public function new() {
		super();
        var stage = Lib.current.stage;

        var textFormat = new TextFormat();
        textFormat.font = "Courier";
        textFormat.color = 0xff0000;
        textFormat.size = 42;

        var text = new TextField();
        text.text = "Hello World!";
        text.x = Lib.current.stage.stageWidth/2 - 145;
        text.y = Lib.current.stage.stageHeight/2 - 21;
        text.width = 290;

        text.setTextFormat(textFormat);
        Lib.current.stage.addChild(text);
	}

    public static function main() {
        Lib.current.addChild(new Main());
    }
}
