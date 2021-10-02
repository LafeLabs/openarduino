
int knob = 0;
int blinktime = 0;

int button1pin = 3;
int button2pin = 2;
int redled = 10;
int greenled = 11;

boolean button1 = false;
boolean button2 = false;

void setup() {
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 
    pinMode(redled,OUTPUT);
    pinMode(greenled,OUTPUT);
    digitalWrite(redled,LOW);
    digitalWrite(greenled,LOW);
    knob = analogRead(A2);
    Serial.begin(9600);

}

void loop() {

  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  
  knob = analogRead(A2);
  blinktime = knob;
  if(!button1 && button2){
    digitalWrite(redled,HIGH);
    delay(blinktime);
    digitalWrite(redled,LOW);
    delay(blinktime);    
    Serial.println("button 1");
  }  
  if(!button2 && button1){
    digitalWrite(greenled,HIGH);
    delay(blinktime);
    digitalWrite(greenled,LOW);
    delay(blinktime);    
    Serial.println("button 2");
  }
  if(button2 && button1){
    digitalWrite(greenled,LOW);
    digitalWrite(redled,LOW);
  }
  if(!button2 && !button1){
    digitalWrite(greenled,LOW);
    digitalWrite(redled,LOW);
  }

  Serial.println(knob); 

}