#include <Servo.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

Servo myservo; 
Servo myservo2;

int pos = 90;    
int i = 0;

void setup() {
  myservo.attach(11);  
  myservo2.attach(12);  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
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
  
  //testing swction
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
