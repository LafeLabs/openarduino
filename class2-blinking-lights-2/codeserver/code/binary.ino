/*
  
  
  count in binary from 0 to 15
  
  4 pins for 4 bits
  
  pins 1 through 4 are pins 8 through 11 on arduino
  

*/

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;
int interval = 250;

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

  for(int index = 0;index < 16;index++){
     displaybinary(index);
     delay(interval);
  }

}

void displaybinary(int number){
  if(number&1){
    digitalWrite(pin1,HIGH);
  }
  else{
    digitalWrite(pin1,LOW);
  }
  if(number&2){
    digitalWrite(pin2,HIGH);
  }
  else{
    digitalWrite(pin2,LOW); 
  }
   if(number&4){
    digitalWrite(pin3,HIGH);
  }
  else{
    digitalWrite(pin3,LOW);
  }
  if(number&8){
    digitalWrite(pin4,HIGH);
  }
  else{
    digitalWrite(pin4,LOW); 
  }
 
}
