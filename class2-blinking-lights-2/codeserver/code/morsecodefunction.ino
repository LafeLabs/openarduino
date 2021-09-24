/*
Morse Code function

learn about functions and strings and also morse code

public domain CC0
Lafe Spietz 2021

open arduino class
*/



//arduino pins mapped to arbitrary pin numbers
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;
int timeUnit = 100;
int messageBreak = 1500;

void setup() {
  // put your setup code here, to run once:

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
//print whatever message you want!  see below for morse code in function
  printMessage("arduino uno");
  delay(messageBreak);
}


void printMessage(String message){
  //for loop thru the String
  for(int index = 0;index < message.length();index++){
      printLetter(message.charAt(index));      
  }
}

void printLetter(char letter){
    //this function is the actual Morse code
  if(letter == 'a' || letter == 'A'){
    dit(); dah();
  }
  if(letter == 'b' || letter == 'B'){
    dah(); dit(); dit(); dit();
  }
  if(letter == 'c' || letter == 'C'){
    dah(); dit(); dah(); dit();
  }
  if(letter == 'd' || letter == 'D'){
    dah(); dit(); dit();
  }
  if(letter == 'e' || letter == 'E'){
    dit(); 
  }
  if(letter == 'f' || letter == 'F'){
    dit(); dit(); dah(); dit();
  }
  if(letter == 'g' || letter == 'G'){
    dah(); dah(); dit();
  }
  if(letter == 'h' || letter == 'H'){
    dit(); dit(); dit(); dit();
  }
  if(letter == 'i' || letter == 'I'){
    dit(); dit(); 
  }
  if(letter == 'j' || letter == 'J'){
    dit(); dah(); dah(); dah();
  }
  if(letter == 'k' || letter == 'K'){
    dah(); dit(); dah();
  }
  if(letter == 'l' || letter == 'L'){
    dit(); dah(); dit(); dit();
  }
  if(letter == 'm' || letter == 'M'){
    dah(); dah();
  }
  if(letter == 'n' || letter == 'N'){
    dah(); dit();
  }
  if(letter == 'o' || letter == 'O'){
    dah(); dah(); dah(); 
  }
  if(letter == 'p' || letter == 'P'){
    dit(); dah(); dah(); dit();
  }
  if(letter == 'q' || letter == 'Q'){
    dah(); dah(); dit(); dah();
  }
  if(letter == 'r' || letter == 'R'){
    dit(); dah(); dit();
  }
  if(letter == 's' || letter == 'S'){
    dit(); dit(); dit();
  }
  if(letter == 't' || letter == 'T'){
    dah(); 
  }
  if(letter == 'u' || letter == 'U'){
    dit(); dit(); dah(); 
  }
  if(letter == 'v' || letter == 'V'){
    dit(); dit(); dit(); dah();
  }
  if(letter == 'w' || letter == 'W'){
    dit(); dah(); dah(); 
  }
  if(letter == 'x' || letter == 'X'){
    dah(); dit(); dit(); dah();
  }
  if(letter == 'y' || letter == 'Y'){
    dah(); dit(); dah(); dah();
  }
  if(letter == 'z' || letter == 'Z'){
    dah(); dah(); dit(); dit();
  }
  if(letter == '1'){
    dit(); dah(); dah(); dah(); dah();
  }
  if(letter == '2'){
    dit(); dit(); dah(); dah(); dah();
  }
  if(letter == '3'){
    dit(); dit(); dit(); dah(); dah();
  }
  if(letter == '4'){
    dit(); dit(); dit(); dit(); dah();
  }
  if(letter == '5'){
    dit(); dit(); dit(); dit(); dit();
  }
  if(letter == '6'){
    dah(); dit(); dit(); dit(); dit();
  }
  if(letter == '7'){
    dah(); dah(); dit(); dit(); dit();
  }
  if(letter == '8'){
    dah(); dah(); dah(); dit(); dit();
  }
  if(letter == '9'){
    dah(); dah(); dah(); dah(); dit();
  }
  if(letter == '0'){
    dah(); dah(); dah(); dah(); dah();
  }

  
  if(letter == ' '){
     delay(6*timeUnit); //if a space is detected, 6 units on top of 1 unit =7 
  }
  else{
    delay(2*timeUnit);  // for anything but a space, put in a 
  }

}


void dit(){
  
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
  delay(timeUnit);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  delay(timeUnit);
    
}

void dah(){
  
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
  delay(3*timeUnit);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  delay(timeUnit);    
}