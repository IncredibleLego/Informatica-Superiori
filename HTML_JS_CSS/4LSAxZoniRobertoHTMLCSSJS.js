var sketchProc = function(processingInstance) {
    with (processingInstance) {
		size(400, 400); 
		frameRate(30);
		// ProgramCodeGoesHere
		background(89, 216, 255);
		var Fish = function (x, y, a, b, c){
			var centerX = x;
			var centerY = y;
			var bodyLength = 118;
			var bodyHeight = 74;
			var bodyColor = color(a, b, c);
			noStroke();
			fill(bodyColor);
			// body
			ellipse(centerX, centerY, bodyLength, bodyHeight);
			// tail
			var tailWidth = bodyLength/4;
			var tailHeight = bodyHeight/2;
			triangle(centerX-bodyLength/2, centerY,
			centerX-bodyLength/2-tailWidth, centerY-tailHeight,
			centerX-bodyLength/2-tailWidth, centerY+tailHeight);
			// eye
			fill(33, 33, 33);
			ellipse(centerX+bodyLength/4, centerY, bodyHeight/5, 
			bodyHeight/5);
		};
		Fish (200, 50, 20, 100, 120);
		Fish (100, 150, 30, 110, 140);
		Fish (150, 200, 40, 50, 70);
		Fish (300, 300, 20, 30, 110);
		Fish (100, 300, 140, 50, 70);
		Fish (150, 380, 40, 150, 70);
		Fish (330, 100, 40, 50, 70);
		Fish (300, 161, 40, 100, 170);
		Fish (330, 390, 40, 50, 170);
	};
};
// Get the canvas that Processing-js will use
var canvas1 = document.getElementById("mycanvas1"); 
// Pass the function sketchProc (defined in myCode.js) to Processing's constructor.
var processingInstance = new Processing(canvas1, sketchProc); 

var sketchProc = function(processingInstance) {
     with (processingInstance) {
        size(400, 400); 
        frameRate(30);
        // ProgramCodeGoesHere
        draw = function() {
			background(219, 255, 255);
			fill(255, 235, 107);
			textSize(25);
			var d = day(); 
			var m = month();
			var y = year();
			text(d + "/" + m + "/" + y, 10, 30);
			fill(255, 35, 10);
			text("JavaScript", 250, 30);
			//tetto
			fill(174, 180, 214);
			triangle(200, 28, 350, 150, 50, 150);
			//muro
			fill(255, 240, 90);
			rect(60, 150, 280, 207);
			for(var i = 7; i < 17; i++){ 
				stroke(122, 122, 122);
					var lineY = 20 + (i * 20);
					line(60, lineY, 340, lineY);
			}
			for ( var j=2; j <17; j++){
					var lineX = 20 + (j * 20);
					line(lineX, 150, lineX, 357);
			}
			//porta
			fill(120, 80, 19);
			rect(180, 280, 40, 77);
			for(var x=90; x<290; x++){
				fill(255, 156, 253);
				rect(x, 200, 30, 50);
				x+=60;
			}
			image(getImage("cute/CharacterBoy"), 83, 193, 45, 70);
			image(getImage("space/girl5"), 126, 189, 100, 100);
			image(getImage("cute/CharacterCatGirl"), 207, 194, 40, 70);
			image(getImage("cute/CharacterPrincessGirl"), 268, 194, 40, 70);
			for(var x=-20; x<400; x++){
				image(getImage("cute/TreeTall"), x, 263);
				x+=43;
			}
			var nuvolaX1=100;
			var nuvolaY1= 80;
			fill(255, 255, 255);
			noStroke();
			ellipse(nuvolaX1, nuvolaY1, 126, 97);
			ellipse(nuvolaX1+62, nuvolaY1, 70, 60);
			ellipse(nuvolaX1-62, nuvolaY1, 70, 60);
			var nuvolaX2=370; 
			var nuvolaY2=130;
			ellipse(nuvolaX2, nuvolaY2, 126, 97);
			ellipse(nuvolaX2+62, nuvolaY2, 70, 60);
			ellipse(nuvolaX2-62, nuvolaY2, 70, 60);
			fill(66, 66, 66);
			text("JavaScript", 10, 30);
			image(getImage("avatars/mr-pants-with-hat"), mouseX, 316, 80, 90);
		};
	}
};
// Get the canvas that Processing-js will use
var canvas2 = document.getElementById("mycanvas2"); 
// Pass the function sketchProc (defined in myCode.js) to Processing's constructor.
var processingInstance = new Processing(canvas2, sketchProc);
var sketchProc = function(processingInstance) {
	with (processingInstance) {
		size(200, 200); 
		frameRate(30);
		// ProgramCodeGoesHere
		noStroke();
		var faceSize = 42;
		var eyesSize = faceSize/8;
		draw= function() {
			background(93, 252, 141);
			// ears
			var earSize=faceSize*1/2;
			fill(89, 52, 17);
			ellipse(mouseX-15, mouseY-20, earSize, earSize);
			ellipse(mouseX+15, mouseY-20, earSize, earSize);
			 //body
			stroke(0, 0, 0);
			var bodySize = faceSize *2;
			fill(163, 113, 5);
			ellipse (mouseX, mouseY+55, bodySize, bodySize);
			line(mouseX-28, mouseY+40, mouseX-80, mouseY+10);
			line (mouseX+28, mouseY+40, mouseX+80, mouseY+10);
			 // face
			fill(163, 113, 5);
			ellipse(mouseX, mouseY, faceSize, faceSize);
			 //eyes 
			fill(0, 0, 0);
			ellipse(mouseX- (1/4*faceSize), mouseY- (1/8 *faceSize), eyesSize, eyesSize); 
			ellipse(mouseX+ (1/4 *faceSize), mouseY- (1/8 * faceSize), eyesSize, eyesSize);
			 //nose
			fill(89, 52, 20);
			ellipse(mouseX, mouseY+faceSize/8, faceSize*4/15, faceSize/5);
		};
	}
};
// Get the canvas that Processing-js will use
var canvas3 = document.getElementById("mycanvas3"); 
// Pass the function sketchProc (defined in myCode.js) to Processing's constructor.
var processingInstance = new Processing(canvas3, sketchProc);
