var sketchProc1 = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(30);
		draw= function() {
			background(0, 0, 139);
			text("Francesco.Corrado", mouseX, mouseY);
	};
	}
};
var X=0;
var sketchProc2 = function(processingInstance) {
    with (processingInstance) {
		size(400, 400); 
		frameRate(30);
		draw= function() {
			background(173, 216, 230);
			fill(124, 252, 0);
			rect(0, 300, 400, 400);
			fill(0, 0, 0);
			rect(300, 300, 10, -90);
			fill(255, 255, 255);
			ellipse(X, 250, 15, 15);
			X=X+4;
			if(X==300){
				text("GOOOOAL",200, 100);
				X=X-300;
			}
	};
}
};
var sketchProc3 = function(processingInstance) {
    with (processingInstance) {
		size(400, 400); 
		frameRate(30);
		draw= function() {
			background(173, 216, 230);
			fill(240, 248, 255);
			rect(0, 300, 400, 400);
			
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
var canvas3=document.getElementById("mycanvas3");
if(canvas3!==null){
    var processingInstance =new Processing(canvas3, sketchProc3);
}
