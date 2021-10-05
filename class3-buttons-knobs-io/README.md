[../](../)

#  Class 3: buttons, knobs, digital IO

Goals: 

1. Learn to use analog inputs for knobs
2. learn to use digital inputs for buttons
3. learn to use Serial monitor and plot to see analog signals(knob)
4. put it all together with a turn signal
5. if there is time, social coding with digital output/input connecting pairs of Arduinos to make simple games

Things to learn:

1. digital logic: "not", "and", if/then
2. input modes: INPUT, OUTPUT, INPUT_PULLUP, analog
3. Serial.begin([baud rate]), Serial.println(), Serial.print()


## Analog input.  

Labeled as names: A0 through A5.  Measures the voltage on the pin as a number between 0 and 1023, where 0 is 0 volts and 1023 is the power supply voltage of 5 V.

Read from an analog pin with the command

```
analogRead([pin name])
```
The connection between your computer and the Arduino is over a serial line via USB. You can read characters sent down this line by the Arduino by programming the Arduino to print characters, and using built in monitoring tools in the Arduino IDE to see the response.

If you want to use the Serial functions on the Arduino you want to start a serial stream with the command

```
Serial.begin([baud rate])
```

And the baud rate is a standard rate for data transmission such as 9600 or 115200(two of the most common choices.)  While there are other choices, in this class we will set speed to 9600 if we don't care about speed and if we're looking to get data faster to 115200.

Once a serial port is being used by the Arduino, we can send characters down the line with `Serial.print()` and `Serial.println()`.  `print()` refers to just a character without a new line, and `println()` refers to printing with a newline.  

To see how the knob works, plug the Arduino shield onto the UNO, and upload the following code to the board: 

```
int knob = 0;

void setup() {

    Serial.begin(9600);

}

void loop() {

  knob = analogRead(A2);
  Serial.println(knob); 

}
```

With that uploaded, open the Serial monitor.  Make sure the monitor is set to the same baud rate, of 9600.  Turn the knob.  You should see a response in the numbers from 0 to 1023.  That knob is a "potentiometer", or variable resistor, which has the two ends connected to 0 volts(ground) and 5 volts(Vcc) and which has a center pin which varies from all the way connected to one end to the other, continuously.



![](https://i.imgur.com/8rirPUA.png)

![](https://i.imgur.com/C4plXHa.png)

![](https://i.imgur.com/RmQ5hPS.png)

![](https://i.imgur.com/RgDLnvM.png)

![](https://i.imgur.com/ZMPhfZH.jpg)

![](https://i.imgur.com/3H762Wf.jpg)

![](https://i.imgur.com/n3C267w.jpg)

![](https://i.imgur.com/JF9ELIP.jpg)

![](https://i.imgur.com/XqkX90B.png)

![](https://i.imgur.com/aP3L8Oi.png)

![](https://i.imgur.com/8aV6qk3.jpg)

[turn signal code](codeserver/code/turnsignal.ino)

[communication game code](codeserver/code/comms.ino)

[codeserver/](codeserver/)



