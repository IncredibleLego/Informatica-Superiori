var sketchProc1 = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(30);
		draw= function() {
			background(0, 0, 139);
			textSize(50);
			text("Musica", mouseX, mouseY);
	};
	}
};
var banconotaY=0;
var soldiY=0;
var sketchProc2 = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(5);
		draw= function() {
			background(211,211,211);
			fill(47, 172, 93)
			if(banconotaY % 2 === 0){
				rect(20, banconotaY, 70, 30);
				rect(300, banconotaY, 70, 30);
				rect(600, banconotaY, 70, 30);
			}
			else{
				rect(40, banconotaY, 30, 70);
				rect(320, banconotaY, 30, 70);
				rect(620, banconotaY, 30, 70);
			}
			fill(228, 195, 21)
			ellipse(140, soldiY, 15, 15);
			ellipse(190, soldiY, 15, 15);
			ellipse(240, soldiY, 15, 15);
			ellipse(400, soldiY, 15, 15);
			ellipse(440, soldiY, 15, 15);
			ellipse(480, soldiY, 15, 15);
			ellipse(520, soldiY, 15, 15);
			ellipse(560, soldiY, 15, 15);
			ellipse(690, soldiY, 15, 15);
			ellipse(730, soldiY, 15, 15);
			ellipse(770, soldiY, 15, 15);
			soldiY=soldiY+4;
			banconotaY=banconotaY+3;
			if(soldiY==400){
					soldiY=soldiY-400;
			}
			if(banconotaY==399){
				banconotaY=banconotaY-399;
			}
	};
}
};

var sketchProc3 = function(processingInstance) {
    with (processingInstance) {
		size(800, 400); 
		frameRate(30);
		draw= function() {
			background(255, 255, 255);
			fill(0, 0, 0);
			rect(300, 200, 30, 100);
			ellipse(315, 200, 50, 50);
			textSize(40);
			text("POP OSSI", 500, 200);
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

