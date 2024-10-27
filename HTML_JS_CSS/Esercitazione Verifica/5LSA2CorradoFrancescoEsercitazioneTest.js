var sketchProc1 = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(30);
		draw= function() {
			background(0, 0, 139);
			fill(255, 255, 255);
			rect(mouseX, mouseY, 175, 230);
			fill(0, 0, 0);
			text("biglietto d'auguri", mouseX+50, mouseY+80);
	};
}
};


var X = 0;
var Y = 0;
var sketchProc2 = function(processingInstance) {
    with (processingInstance) {
		size(400, 400); 
		frameRate(30);
		draw= function() {
			background(89, 216, 255);
			fill(255, 255, 255);
			rect(0, 0, 175+X, 230+Y);
			X=X+1;
			Y=Y+1;
			fill(0, 0, 0);
			text("biglietto d'auguri", 30+X, 100+Y);
	};
}
};

var canvas1=document.getElementById("mycanvas1");
if(canvas1!==null){
    var processingInstance = new Processing(canvas1, sketchProc1);
}

var canvas2=document.getElementById("mycanvas2");
if(canvas2!==null){
    var processingInstance =new Processing(canvas2, sketchProc2);
}
