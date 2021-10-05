/*
 * most basic 2 button action
 * 
 * each button connects a digital pin to ground
 * 
 * each digital input is tied to a "pull up" resisotr 
 * which is needed so that the normal state is "high" until
 */


//note! these labels are backwards on the shield! sorry! -lfs
int button1pin = 3;
int button2pin = 2;

boolean button1 = false;
boolean button2 = false;

void setup() {
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 

    Serial.begin(9600);

}

void loop() {

  button1 = !digitalRead(button1pin);  
  button2 = !digitalRead(button2pin);  

  Serial.print("button1 = ");
  Serial.print(button1);
  Serial.print(", button2 = ");
  Serial.println(button2); 

}