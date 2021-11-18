// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 8

int r = 0;
int g = 100;
int b = 200;
int pixel = 0;//0 through 7

int wait= 50;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


int button1pin = 2;
int button2pin = 3;

int inpin = 12;

int outpin = 9;//output to next stage in sequence of arduinos

boolean button1 = false;
boolean button2 = false;
boolean trigger = false;


// setup() function -- runs once at startup --------------------------------

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  
  
  //stuff from comms program
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 

    pinMode(inpin,INPUT_PULLUP);
    

    pinMode(outpin,OUTPUT);
    pinMode(13,OUTPUT);

    digitalWrite(outpin,HIGH);//simulate button behavior by being high until trigger, which goes low
    digitalWrite(13,LOW);

    Serial.begin(9600);


}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  button1 = !digitalRead(button1pin);  
  button2 = !digitalRead(button2pin);  
  trigger = !digitalRead(inpin);

  if(button1 || button2 || trigger){    
    Serial.println("start");
    event();
    Serial.println("finish");
    //trigger output:
    digitalWrite(outpin,LOW);
    delay(100);//pull the output pin low for a tenth of a second to trigger the next arduino
    digitalWrite(outpin,HIGH);
  }  
  trigger = false;
  button1 = false;
}


void event(){


  uint32_t color = strip.Color(r,g,b);

  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
  }
  digitalWrite(13,HIGH);
  delay(1000);
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(0,0,0));         //  Set pixel's color (in RAM) 
    strip.show();                          //  Update strip to match
  }

  digitalWrite(13,LOW);
  delay(100);
 
}
