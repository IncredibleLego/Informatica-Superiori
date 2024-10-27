var sketchProc = function(processingInstance) {
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
var canvas1 = document.getElementById("mycanvas1"); 
var processingInstance = new Processing(canvas1, sketchProc);

var bigliettoX = 30;
var bigliettoY = 60;
var sketchProc = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(30);
		draw= function() {
			background(0, 0, 139);
			fill(255, 255, 255);
			rect(bigliettoX, bigliettoY , 175, 230);
			bigliettoX=bigliettoX+3;
			bigliettoY=bigliettoY-1;
			fill(0, 0, 0);
			text("biglietto d'auguri", bigliettoX+50, bigliettoY+80);
	};
}
};
var canvas2 = document.getElementById("mycanvas2"); 
var processingInstance = new Processing(canvas2, sketchProc); 

