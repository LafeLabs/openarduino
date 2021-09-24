/*
Lafe Spietz 2021, PUBLIC DOMAIN CC0 code

open arduino class

 SOS 
 4 LEDs, pins 8 through 11
 
 one unit is a dit
 three units is a dah
 spaces between are one unit
 letter breaks are 3 units
 word breaks are 7 units
 
 S = dit dit dit
 
 O = dah dah dah
 
 dit and dah are both defined as functions

*/

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;
int interval = 80;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);

}

// the loop function runs over and over again forever
void loop() {

  dit();
  dit();
  dit();
  delay(interval*3);
  dah();
  dah();
  dah();
  delay(interval*3);
  dit();
  dit();
  dit();
  delay(interval*3);
  delay(interval*7);

}

void dit(){
  
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
  delay(interval);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  delay(interval);
    
}

void dah(){
  
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
  delay(3*interval);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  delay(interval);    
}