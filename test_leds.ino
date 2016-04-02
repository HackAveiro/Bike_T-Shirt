#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 4

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
int sensorPin = A0; 

void setup() { 
  Serial.begin(9600);
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 
  static int a=0;
  int sensorValue, sensorValue_norm;

  sensorValue = analogRead(sensorPin);
  sensorValue_norm = map(sensorValue, 0, 800, 0, 255);
  //Serial.println(sensorValue);
  Serial.println(sensorValue_norm);
  FastLED.setBrightness(sensorValue_norm); 
  //FastLED.setBrightness(254); 
  // Turn the LED on, then pause
  for(int i=0; i<4; i++){
    leds[i].setHSV(20,20,a);
  }
  
  if(a<255){
  a++;
    }else{
  a=0;    
  }
  /*
  leds[0] = CRGB::Red;
  
  leds[1] = CRGB::Purple;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Green;
  */
  
  FastLED.show();
  delay(20);
  // Now turn the LED off, then pause
  /*for(int i=0; i<4; i++){
    leds[i].setHSV(0,0,0);
  }*/
  /*leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;*/
  //FastLED.show();
  //delay(50);
}
