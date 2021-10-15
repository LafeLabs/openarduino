//KnobSean.ino
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
#define LED_COUNT 16

int r = 0;
int g = 100;
int b = 200;
int pixel = 0;//0 through 15
int pixel2 = 15;

int knob = 0;
int BUTTON_PIN = 2;
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

  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}



// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Get current button state.
  boolean buttonState = digitalRead(BUTTON_PIN);
  // Check if state changed from high to low (button press).
  if(buttonState == LOW){
    // Short delay to debounce button.
      uint32_t color = strip.Color(r,g,b);
    knob = analogRead(A2);
    if(knob > 0 && knob < 64){
      pixel = 0;
      pixel2 = 15;
    }
    if(knob > 64 && knob < 2*64){
      pixel = 1;
      pixel2 = 14;
    }
    if(knob > 2*64 && knob < 3*64){
      pixel = 2;
      pixel2 = 13;
    }
    if(knob > 3*64 && knob < 4*64){
      pixel = 3;
      pixel2 = 12;
    }
    if(knob > 4*64 && knob < 5*64){
      pixel = 4;
      pixel2 = 11;
    }
    if(knob > 5*64 && knob < 6*64){
      pixel = 5;
      pixel2 = 10;
    }
    if(knob > 6*64 && knob < 7*64){
      pixel = 6;
      pixel2 = 9;
    }
    if(knob > 7*64 && knob < 8*64){
      pixel = 7;
      pixel2 = 8;
    }
    if(knob > 8*64 && knob < 9*64){
      pixel = 8;
      pixel2 = 7;
    }
    if(knob > 9*64 && knob < 10*64){
      pixel = 9;
      pixel2 = 6;
    }
    if(knob > 10*64 && knob < 11*64){
      pixel = 10;
      pixel2 = 5;
    }
    if(knob > 11*64 && knob < 12*64){
      pixel = 11;
      pixel2 = 4;
    }
    if(knob > 12*64 && knob < 13*64){
      pixel = 12;
      pixel2 = 3;
    }
    if(knob > 13*64 && knob < 14*64){
      pixel = 13;
      pixel2 = 2;
    }
    if(knob > 14*64 && knob < 15*64){
      pixel = 14;
      pixel2 = 1;
    }
    if(knob > 15*64){
      pixel = 15;
      pixel2 = 0;
    }

    Serial.println(pixel);
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      if(i == pixel){
        strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      }
      else{
        strip.setPixelColor(i, strip.Color(0,0,0));         //  Set pixel's color (in RAM) 
      }
      strip.show();                          //  Update strip to match
    }
  
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
        if(i == pixel2){
          strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        }
        else{
          strip.setPixelColor(i, strip.Color(0,0,0));         //  Set pixel's color (in RAM) 
        }
        strip.show();                          //  Update strip to match
      }
    }
  else{
    Serial.println("Else statement");
  }
}
  
