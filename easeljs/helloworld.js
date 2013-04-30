var stage;
var logo;

function init() {
    stage = new createjs.Stage(document.getElementById('canvas'));
    logo = new createjs.Bitmap('love.png');
    stage.addChild(logo);

    createjs.Ticker.setFPS(10);
    createjs.Ticker.addEventListener("tick", tick);
}

function tick() {
    logo.x += 1;
    console.log(createjs.Ticker.getTime()/1000, logo.x);
    stage.update();
}
