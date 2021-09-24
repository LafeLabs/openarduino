/*
  

*/

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;

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
  digitalWrite(pin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(pin1, LOW);    // turn the LED off by making the voltage LOW
 // delay(200);                       // wait for a second
  digitalWrite(pin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(pin2, LOW);    // turn the LED off by making the voltage LOW
 // delay(200);      
  // wait for a second 
  digitalWrite(pin3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(pin3, LOW);    // turn the LED off by making the voltage LOW
 // delay(200);                       // wait for a second
    digitalWrite(pin4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(pin4, LOW);    // turn the LED off by making the voltage LOW
 // delay(200);                       // wait for a second

   
}