/*
 * button dimmer switch
 * 
 * buttons increase and decrease variable x, read from serial
 * try plotting it!
 */

int button1pin = 3;//these are backwards on the board labels, sorry! -LFS
int button2pin = 2;

boolean button1 = false;
boolean button2 = false;

int x = 0;

void setup() {
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 
    Serial.begin(9600);

}

void loop() {

  button1 = !digitalRead(button1pin);  
  button2 = !digitalRead(button2pin);  

  if(button1){
    x += 1;
  }
  if(button2){
    x -= 1;
  }

  Serial.println(x); 

}