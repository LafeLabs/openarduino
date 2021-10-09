//processing sketch

function setup() {
  if(innerWidth > innerHeight){
      createCanvas(innerHeight,innerHeight);
  }
  else{
      createCanvas(innerWidth,innerWidth);
  }
    
}

function draw() {
  if (mouseIsPressed) {
    fill(0);
  } else {
    fill(255);
  }
  ellipse(mouseX, mouseY, 30, 30);
}
