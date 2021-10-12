let x = 100;
let y = 100;
let imgx = 0;
let imgy = 0;
let delta = 10;
let img;
let img2;

let stack = [];


function preload() {
  img = loadImage('https://i.imgur.com/0tmNy74.png');
  img2 = loadImage('https://i.imgur.com/No1wukK.png');
}

function setup() {
  if(innerWidth > innerHeight){
      createCanvas(innerHeight,innerHeight);
  }
  else{
      createCanvas(innerWidth,innerWidth);
  }
    image(img, 0, 0);

  //fill(255, 0, 0);
}

function draw() {
  if (keyIsDown(LEFT_ARROW)) {
    if(keyIsDown(CONTROL)){
        imgx -= delta;
    }
    else{
        x -= delta;
    }

  }
  if (keyIsDown(RIGHT_ARROW)) {
    if(keyIsDown(CONTROL)){
        imgx += delta;
    }
    else{
      x += delta;
    }
  }

  if (keyIsDown(UP_ARROW)) {
    if(keyIsDown(CONTROL)){
        imgy -= delta;
    }
    else{
        y -= delta;
    }
  }

  if (keyIsDown(DOWN_ARROW)) {
    if(keyIsDown(CONTROL)){
        imgy += delta;
    }
    else{
        y += delta;
    }
  }

  if(keyIsDown(32)){

      var element = {};
      element.dx = x - imgx;
      element.dy = y - imgy;
      stack.push(element);
      
  }

  clear();
  //http://vineotron.net/images/uploadimages/image1.PNG
  image(img,imgx,imgy);

//  rect(x, y, 50, 50);
  for(var index = 0;index < stack.length;index++){
      image(img2, imgx + stack[index].dx,imgy + stack[index].dy, 50, 50);
  }
  image(img2, x, y, 50, 50);

}
