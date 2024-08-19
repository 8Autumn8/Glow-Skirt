#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL  5   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS     250  // The number of LEDs (pixels) on NeoPixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(random(150, 255), random(0, 30), random(30, 100)));
    NeoPixel.show();
  }
  delay(1000); 
  NeoPixel.clear();
}

void loop() {
  NeoPixel.clear(); // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(random(NUM_PIXELS),  NeoPixel.Color(random(150, 255), random(0, 30), random(30, 100))); // it only takes effect if pixels.show() 
    NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
    
  }
}
