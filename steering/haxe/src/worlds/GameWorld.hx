package worlds;

import com.haxepunk.World;

class GameWorld extends World {

    public function new() {
        super();
    }

    override public function begin() {
        super.begin();
        add(new entities.Boid(304, 226, 20, 3, 0.4));
    }

    override public function update() {
        super.update();
    }
}
