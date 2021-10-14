## [../](../)

## [codeserver/](codeserver/)

[Lafe's Home Raspberry Pi code server(temporary link)](http://vineotron.net/neopixel/)

Programs to copy:

 - [codeserver/code/strandtest.ino](codeserver/code/strandtest.ino)
 - [codeserver/code/redcycle.ino](codeserver/code/redcycle.ino)
 - [codeserver/code/rgbcycle.ino](codeserver/code/rgbcycle.ino)
 - [codeserver/code/pixel.ino](codeserver/code/pixel.ino)
 - [codeserver/code/pixelknob.ino](codeserver/code/pixelknob.ino)
 - [codeserver/code/serialpixel.ino](codeserver/code/serialpixel.ino)

#  [Class 4: Neopixels](https://github.com/LafeLabs/openarduino/blob/main/class4-neopixels/README.md)

Neopixels are programmable LED chips with full red/green/blue control of color.  They come in strips in all shapes and sizes, and can be programmed from Arduino using a collection of libraries from Adafruit.  They are a generic chip, the WS2812, packaged and made easy to use by Adafruit.  

[For more information, THE reference is the Adafruit website(link to guide).](https://learn.adafruit.com/adafruit-neopixel-uberguide)

The Neopixel strip:

![](https://i.imgur.com/ocrBbo7.jpg)  

These come in many lengths, with various pixel densities and in various shapes.  They can be meters long or just a single pixel. They can be stiff or flexible, and there are some which are designed to be sewn into clothes.  They are all based on the WS2812 chip, which can also be used in your own circuit board designs.

Important! Neopixels consume enough power that you should never drive them from the USB from your laptop.  Always have some other power source! For this class we have wall plug 9 volt supplies which can power the Arduino, and that has enough power to also power the lights. You can plug the power in and the USB cable at the same time.  

9 V supply:

![](https://i.imgur.com/J4nDk1c.jpg)


In order to set this up with the Trash Robot shield boards, connect the 5 volt power to the Vin spring clip with a jumper as shown:

![](https://i.imgur.com/MAoonCE.jpg)

Then connect the strip on the ribbon cable as shown:

![](https://i.imgur.com/dYTbQDx.jpg)

you can also chain these together like this:

![](https://i.imgur.com/I88c0XE.jpg)

Remember to plug in the 9 V power *BEFORE* you connect the USB along with the jumper!

Open the Arduino IDE and open the Adafruit Neopixel example code, changing "LED_COUNT" from 60 to 8.  Once this is changed, upload it to the board.  You should see a flashing light display!

Now for the rest of the class we will collectively modify the examples to make things, and share those things with each other, making a whole library of things.

Some things we might make:

 - just a slow cycle through solid rainbow colors(all 8 pixels the same, color rotation through rainbow)
 - turn the knob to set the position of a single pixel, which you can move up and down
 - the knob determines the speed of cycling
 - split the example behavior up into different modes, use the buttons to toggle between modes
 - stopwatch where a button starts and stops a timer which counts up using color bars, so rising red, then green, then blue or vice versa, flashes a signal when done
 - serial commands sent over the serial terminal to set the pixel position and color of a single pixel

