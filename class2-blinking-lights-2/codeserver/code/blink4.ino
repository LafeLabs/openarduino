/*
blink, but with 4 LED's

public domain CC0
Lafe Spietz 2021

open arduino class

*/



//arduino pins mapped to arbitrary pin numbers
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;


void setup() {


  //set all pins to output, then set them all low
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  
}

void loop() {

    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    delay(500);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(500);
    
}

