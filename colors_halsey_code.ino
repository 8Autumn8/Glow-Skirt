#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL  5   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS     200  // The number of LEDs (pixels) on NeoPixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  NeoPixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  //twinkleRandomColor();
  verse();
  chorus();
  verse();
  chorus();
  refrain();
  chorus();
  closing();
  
}

void refrain(){

  twinkleRandomColor(6);
  setAllPixels(0xFF0000, 3000, 0, 255); // Set to red  
  twinkleRandomColor(2);
  setAllPixels(0x0000FF, 1000, 0, 255); // Set to blue for 2 seconds  
  spiralRandomSingleColor(2);
  NeoPixel.clear();
  delay(500);
  setAllPixels(0xC8A2C8, 2000, 0, 255); //set to lilac
  NeoPixel.clear();
  delay(1000);
  setAllPixels(0x800080, 1500, 0, 255); // Set to purple
  NeoPixel.clear();

}

void closing(){
  dechrescendo();
  delay(500);
  for (int i = 0; i < 4; i++){
    setAllPixels(0x0000FF, 2000, 100, 255); // Set to blue for 2 seconds  
  }
  // Create a fade-out effect
  NeoPixel.fill(0xFFFFFF);
  for (int i = 255; i >= 0; i -= 1) {
    NeoPixel.setBrightness(i);
    NeoPixel.setPixelColor(random(NUM_PIXELS), NeoPixel.Color(0, 0, 0)); // Set one pixels to black (off)
    NeoPixel.show();
    delay(10); // Adjust delay for fade-out speed
  }
  //NeoPixel.clear();
  //NeoPixel.show();
  delay(50000); // Pause before ending
}

uint32_t getRandomColorInHex(){
  return NeoPixel.Color(random(0, 10), random(60), random(0, 100));
  
}

uint8_t getRandomBrightness(){
  return random(100,255);
}

void verse(){
  uint32_t eigthNoteInMiliseconds = 273;
  uint32_t delayTime = 5;
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //your
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //lit
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //tle

  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //bro
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ther
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //nev
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //er
  setAllPixels((getRandomColorInHex()), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //tells
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //but
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //he

  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 2, delayTime, getRandomBrightness()); //loves
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 2, delayTime, getRandomBrightness()); //you
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 3, delayTime, getRandomBrightness()); //so
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //said
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //your


  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 2, delayTime, getRandomBrightness()); //moth
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 2, delayTime, getRandomBrightness()); //er
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds * 3, delayTime, getRandomBrightness()); //on
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ly
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*2, delayTime, getRandomBrightness()); //smiled
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //on
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //her
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //T
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //V
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds *2, delayTime, getRandomBrightness()); //Show
  
  //delay(eigthNoteInMiliseconds);

  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //You're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //On
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Ly
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Hap
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Py
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //When
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Your
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Sor
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ry
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //Head
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //is
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //filled
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //with
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*2, delayTime, getRandomBrightness()); //dope
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //I
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //hope
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //make
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //it
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //to
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //the
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*2, delayTime, getRandomBrightness()); //day
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //twenty
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds *1.5, delayTime, getRandomBrightness()); //eight
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds *1.5, delayTime, getRandomBrightness()); //years
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds *4, delayTime, getRandomBrightness()); //old

  
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //drip
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ing
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //like
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //a
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //sat
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ur
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //a
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ted
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //sun
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*5.5, delayTime, getRandomBrightness()); //rise
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //spill
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ing
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //like
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //an
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //o
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ver
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //flow
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ing
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*7, delayTime, getRandomBrightness()); //sink
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ripped
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //at
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //eve
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ry
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //edge
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //but
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //a
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //mast
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*1.5, delayTime, getRandomBrightness()); //er
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*2, delayTime, getRandomBrightness()); //piece
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //and
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //now
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //you're

  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //tear
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //ing
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //through
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //the
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //pag
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //es
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //and
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds, delayTime, getRandomBrightness()); //the
  setAllPixels(getRandomColorInHex(), eigthNoteInMiliseconds*4, delayTime, 255); //ink


  


}

void dechrescendo(){
  NeoPixel.clear(); // set all pixel colors to 'off'. It only takes effect if pixels.show() is called


  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(random(NUM_PIXELS), NeoPixel.Color(random(0, 10), random(60), random(0, 100))); // it only takes effect if pixels.show() is 
    NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
    NeoPixel.setBrightness(255-pixel);
    delay(5);
  }

}

void chrescendo(){
  NeoPixel.clear(); // set all pixel colors to 'off'. It only takes effect if pixels.show() is called


  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(random(NUM_PIXELS), NeoPixel.Color(random(0, 10), random(60), random(0, 100))); // it only takes effect if pixels.show() is 
    NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
    NeoPixel.setBrightness(pixel);
  }

}

void spiralMultiColor(uint8_t delay_time){
  NeoPixel.clear(); // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

  
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(random(0, 10), random(60), random(0, 100))); // it only takes effect if pixels.show() is 
    NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
    delay(delay_time);
  }

  //delay(5000);

}

void spiralRandomSingleColor(uint8_t delay_time){


  NeoPixel.clear(); // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
  uint32_t randomColor = NeoPixel.Color(random(0, 255), random(255), random(0, 255));

  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { // for each pixel
    NeoPixel.setPixelColor(pixel, randomColor); // it only takes effect if pixels.show() is 
    NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
    delay(delay_time);
  }
}


void twinkleRandomColor(uint8_t count){

  for (int pixel = 0; pixel < count; pixel++) { // for each pixel
    uint32_t randomColor = NeoPixel.Color(random(0, 200), random(200), random(0, 200));
    for (int i = 0; i < 70; i++){
      uint8_t pixelNum = random(NUM_PIXELS);
      NeoPixel.setPixelColor(pixelNum, randomColor); // it only takes effect if pixels.show() is 
    }    
      NeoPixel.show(); // send the updated pixel colors to the NeoPixel hardware.
      delay(random(50,100));
      NeoPixel.fill(0x000000); 
    delay(random(400,1000));
  }
}


void chorus(){ 

  dechrescendo();
  delay(500);
  
  // Timing constants (in milliseconds)
  const uint32_t blueDuration = 3000;    // Blue for 2 seconds
  const uint32_t randomColorsDuration = 1000; // Random colors for 3 seconds
  const uint32_t grayDuration = 3000;    // Gray for 3 seconds


  // "Everything is blue" section
  uint32_t blueColor = 0x0000FF; // Blue
  setAllPixels(blueColor, blueDuration, 0, 255); // Set to blue for 2 seconds

  // Delay for transition before random colors
  delay(500); // Short pause before transitioning

  
  // "His pills, his jeans, and now I'm covered in the colors" section
  spiralMultiColor(3);

  filterThroughColors(42);

  // "He is blue" section
  setAllPixels(blueColor, 1100, 0, 255); // Set to blue for 2 seconds
  dechrescendo();
  delay(1000);

  setAllPixels(blueColor, 3000, 0, 255); // Set to blue for 2 seconds

  // Delay before transitioning to gray
  chrescendo();
  delay(500);

  // Transition to Gray
  setAllPixels(0x808080, grayDuration, 0, 255); // Set to gray for 3 seconds


  spiralMultiColor(25);

  setAllPixels(blueColor, 2000, 0, 255); // Set to blue for 2 seconds

  spiralRandomSingleColor(10);

  setAllPixels(blueColor, 3000, 0, 255); // Set to blue for 2 seconds

  //spiralRandomSingleColor(10);

  //setAllPixels(blueColor, blueDuration, 0, 255); // Set to blue for 2 seconds

}

void filterThroughColors(uint8_t count){
  for (int i = 0; i < count; i++){
    uint32_t randomColor = NeoPixel.Color(random(0, 255), random(255), random(0, 255));
    setAllPixels(randomColor, 100, 0, 255);
  }
}

void setAllPixels(uint32_t color, uint32_t on_time, uint32_t off_time, uint8_t brightness){
  NeoPixel.setBrightness(brightness);
  NeoPixel.fill(color);  // Set the entire strip to the specified color
  NeoPixel.show();      // Update the LEDs
  delay(on_time);       // Keep the color for the specified duration
  
  if (off_time > 0) {
      NeoPixel.clear();  // Clear the strip
      NeoPixel.show();  // Apply the clear
      delay(off_time);  // Wait for a random off-time
  }
}
