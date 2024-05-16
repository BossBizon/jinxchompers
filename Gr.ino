/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
int i = 0;

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(12);  // attaches the servo on pin 9 to the servo object
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {

  myservo.write(90);
  myservo2.write(90);
  leds[0] = CRGB::LimeGreen;
  FastLED.setBrightness(50);
  FastLED.show();
  delay(2000);
  leds[0] = CRGB::Magenta;
  FastLED.setBrightness(50);
  FastLED.show();

  for (i = 0; i < 3; i++)
  {
    myservo.write(120);
    myservo2.write(60);
    delay(200);
    myservo.write(90);
    myservo2.write(90);
    delay(200);
  }
  /* for (pos = 90; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
     // in steps of 1 degree
     myservo.write(pos);
     myservo2.write(pos);// tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 120; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     myservo2.write(pos);
     delay(15);                       // waits 15 ms for the servo to reach the position
    }*/
}
