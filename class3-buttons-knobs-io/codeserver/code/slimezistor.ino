
/*simple knob plot
 * 
 * use trashrobot5 shield
 * potentiometer is on pin A2, which goes from 5v to ground, tuning from 0 to 1023
 * x is voltage measured on input A1, which goes to one of the electrodes as well as a capacitor to ground
 * pin 9 is a digital output.
 * 
 * knob voltage is called "knob", determines xmax and xmin, which center around 512
 * 
 * turn the knob to control the range, 
 * plot the curve on the arduino serial plotter if you have the IDE with the plotter
 * 
 * this program is of limited utility without a plotter
 * 
 */

int knob = 0;
int outpin = 9;
int x = 0;
int xmin = 0;
int xmax = 1023;

void setup() {
    pinMode(outpin,OUTPUT);
    digitalWrite(outpin,LOW);
    knob = analogRead(A2);
    Serial.begin(115200);
    x = analogRead(A1);
    xmin = 512 - knob/2;
    xmax = 512 + knob/2;
    
}

void loop() {

  knob = analogRead(A2);
  x = analogRead(A1);
  xmin = 512 - knob/2;
  xmax = 512 + knob/2;
  if(x > xmax){
    digitalWrite(outpin,LOW);
  }
  if(x < xmin){
    digitalWrite(outpin,HIGH);
  }
  Serial.println(x); 
}