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

int r2 = 200;
int g2= 100;
int b2 = 0;

int pixel = 0;//0 through 7
int pixel2 = 7; 

int knob = 0;
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
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  uint32_t color1 = strip.Color(r,g,b);
  uint32_t color2 = strip.Color(r2,g2,b2);

  knob = analogRead(A2);
  if(knob > 0 && knob < 128){
    pixel = 0;
    pixel2 = 7; 
  }
  if(knob > 128 && knob < 2*128){
    pixel = 1;
    pixel2 = 6;
  }
  if(knob > 2*128 && knob < 3*128){
    pixel = 2;
    pixel2 = 5;
  }
  if(knob > 3*128 && knob < 4*128){
    pixel = 3;
    pixel2 = 4;
  }
  if(knob > 4*128 && knob < 5*128){
    pixel = 4;
    pixel2 = 3;
  }
  if(knob > 5*128 && knob < 6*128){
    pixel = 5;
    pixel2 = 2;
  }
  if(knob > 6*128 && knob < 7*128){
    pixel = 6;
    pixel2 = 1;
  }
  if(knob > 7*128){
    pixel = 7;
    pixel2 = 0;
  }

  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    if(i == pixel){
      strip.setPixelColor(i, color1);         //  Set pixel's color (in RAM)
    }
    else{
      strip.setPixelColor(i, strip.Color(0,0,0));         //  Set pixel's color (in RAM) 
    }
    strip.show();                          //  Update strip to match
  }

  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    if(i == pixel2){
      strip.setPixelColor(i, color2);         //  Set pixel's color (in RAM)
    }
    else{
      strip.setPixelColor(i, strip.Color(0,0,0));         //  Set pixel's color (in RAM) 
    }
    strip.show();                          //  Update strip to match
  }
  
    r++;
    g++;
    b++;
  if(r > 255){
    r = 0;
  }
  if(g > 255){
    g = 0;
  }
  if(b > 255){
    b = 0;
  }
  
    r2++;
    g2++;
    b2++;
  if(r2 > 255){
    r2 = 0;
  }
  if(g2 > 255){
    g2 = 0;
  }
  if(b2 > 255){
    b2 = 0;
  }
//  delay(10);
}