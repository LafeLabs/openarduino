
/* button signal game with two arduinos
 * 
 * look for trigger input or button. on button, do a thing and put out trigger signal
 * 
 * on button do a different thing and put out trigger signal
 * 
 */


int button1pin = 2;
int redled = 7;
int greenled = 8;
int outpin = 9;
int inpin = 3;

boolean button1 = false;
boolean trigger = false;

void setup() {

    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(inpin,INPUT_PULLUP);
    
    pinMode(redled,OUTPUT);
    pinMode(greenled,OUTPUT);
    
    pinMode(outpin,OUTPUT);

    digitalWrite(outpin,HIGH);//simulate button behavior by being high until trigger, which goes low
    digitalWrite(redled,LOW);
    digitalWrite(greenled,LOW);


    Serial.begin(9600);

}

void loop() {

  button1 = !digitalRead(button1pin);  
  trigger = !digitalRead(inpin);

  if(button1){    
    Serial.println("button");
    buttonEvent();
    triggerOutput();
  }  
  if(trigger){
    Serial.println("trigger");  
    triggerEvent();
    triggerOutput();
  }
  
}


void buttonEvent(){

    digitalWrite(greenled,HIGH);
    delay(500);
    digitalWrite(greenled,LOW);
    delay(500);    
    digitalWrite(greenled,HIGH);
    delay(500);
    digitalWrite(greenled,LOW);
    delay(500);    
    digitalWrite(greenled,HIGH);
    delay(500);
    digitalWrite(greenled,LOW);
    delay(500);    
   
 
}

void triggerEvent(){
        
    digitalWrite(redled,HIGH);
    delay(200);
    digitalWrite(redled,LOW);
    delay(200);    
    digitalWrite(redled,HIGH);
    delay(200);
    digitalWrite(redled,LOW);
    delay(200);    

}

void triggerOutput(){
    
    //trigger output:
    digitalWrite(outpin,LOW);
    delay(500);
    digitalWrite(outpin,HIGH);

}
