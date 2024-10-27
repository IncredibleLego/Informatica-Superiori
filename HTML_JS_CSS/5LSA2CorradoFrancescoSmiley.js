//Challenge: SmileyFace 5/5
var SmileyFace = function(centerX, centerY){
    this.centerX=centerX; 
    this.centerY=centerY;
};

SmileyFace.prototype.draw = function() {
    fill(168, 124, 70);
    strokeWeight(1);
    ellipse(this.centerX, this.centerY, 150, 150);
    fill(0, 0, 0);
    ellipse(this.centerX-30, this.centerY-30, 20, 20); 
    ellipse(this.centerX+30, this.centerY-30, 20, 20); 
    noFill(); 
    strokeWeight(1);
    arc(this.centerX, this.centerY+10, 64, 40, 0, 180);
};
SmileyFace.prototype.speak = function(messaggio) {
    text(messaggio, this.centerX+75, this.centerY-40, 15, 15);
};
var facciaA=new SmileyFace(100, 100);
var facciaB=new SmileyFace(300, 100);
facciaA.draw();
facciaB.draw();
facciaA.speak("HI");
facciaB.speak("HI2");