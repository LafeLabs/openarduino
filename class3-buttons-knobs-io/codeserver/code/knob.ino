
/*
 * knobs and the serial port
 * 
 * read the knob at analog pin 2, put it down the serial line
 * 
 * use the Arduino IDE to see the numbers in the serial monitor, then to see them in the plotter
 * 
 * 
 * no copyright, public domain
 * Lafe Spietz
 * Open Source Arduino class github.com/lafelabs/openarduino
 */

int knob = 0;

void setup() {

    Serial.begin(9600);

}

void loop() {

  knob = analogRead(A2);
  Serial.println(knob); 

}