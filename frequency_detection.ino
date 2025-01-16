//FHT
#define FHT_N 256 // set to 256 point fht : there are 8 bins in fht_log_out[]
#define OCTAVE 1  //octave output
#define OCT_NORM 1 // artificially boosts the higher frequencies
#include <FHT.h> // include the library

const int numBINS = 8;
//{123,  108, 51,  33,  29 ,  25,  23,  15};
//solid 4 lights - {130, 123,  108, 51,  33,  29 ,  25};
byte binFloor[numBINS] = {115, 103, 40, 37, 35,  31 ,  22, 17}; // floor for subtraction -> higher frequencies

// NeoPixels
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN             6   // output pin on Arduino
#define numPIXELS       8   // number of NeoPixels per strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte rgbValues[numPIXELS][3];  // pixelN : R,G,B
bool colorIncreasing[numPIXELS][3]; 

byte gradientStrength = 17; // 1, 3, 5, 15, 17, 51, 85, 255

const int N_TIME = 10; // number of frames to store in history
int idx_t = -1;
int idx_end = -1;
byte fDataHistory[N_TIME][LOG_N];
byte runningMin[LOG_N];
byte runningMax[LOG_N];
byte peakToPeak[LOG_N];

float m[LOG_N]; // FHT multiplier

byte mergeIdx[LOG_N] = {0, 0, 1, 1, 2, 2, 3, 3};
byte mergedData[4];

void setup() {
  pixels.begin();
  Serial.begin(9600); // use the serial port
  TIMSK0 = 0; // turn off timer0 for lower jitter
  DIDR0 = 0x01; // turn off the digital input for adc0

  Serial.println();
  for (int i = 0; i < LOG_N; i++) {
    runningMin[i] = 255;
    runningMax[i] = 0;
    m[i] = 1;
  }

  for (byte i = 0; i < numPIXELS; i++) {  // pick pixel
    // rgbValues[i][0] = 100;
    // rgbValues[i][1] = 100;
    // rgbValues[i][2] = 100;

    rgbValues[i][0] = 255 - i * gradientStrength;
    rgbValues[i][1] = 0 + i * gradientStrength;
    rgbValues[i][2] = 0;

    colorIncreasing[i][0] = false;
    colorIncreasing[i][1] = true;
    colorIncreasing[i][2] = false;
  }
}

void loop() {
  colorShiftA();
  runFHT();
  mergeBins(peakToPeak, mergeIdx, mergedData);
  pixelAssign();
  pixels.show();
}

void colorShiftA() {
  for (byte j = 0; j < numPIXELS; j++) {  // pick pixel
    for (int k = 0; k < 3; k++) { // pick RGB color
        if (rgbValues[j][k] == 255) {
          colorIncreasing[j][k] = false;
          if (k == 2) {  // blue
            colorIncreasing[j][0] = true;
            rgbValues[j][0] = gradientStrength;
          }
          else colorIncreasing[j][k+1] = true;
        }
        if (colorIncreasing[j][k]) rgbValues[j][k] += gradientStrength;
        else if (rgbValues[j][k] > 0) rgbValues[j][k] -= gradientStrength;
    }
  }
}

void runFHT() {
  for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
    fht_input[i] = analogRead(0); // put real data into bins
  }
  fht_window(); // window the data for better frequency response
  fht_reorder(); // reorder the data before doing the fht
  fht_run(); // process the data in the fht
  fht_mag_octave(); // take the output of the fht
  

  idx_t = (idx_t + 1) % N_TIME;
  if (idx_end < N_TIME) idx_end++;
  
  for (int i = 0; i < LOG_N; i++) {
    byte x_new = fht_oct_out[i];
    byte x_old = fDataHistory[idx_t][i];
    fDataHistory[idx_t][i] = x_new;

    if (x_new > runningMax[i]) runningMax[i] = x_new;
    if (x_new < runningMin[i]) runningMin[i] = x_new;

    // if data to be overwritten is min or max, find new min and max
    if (x_old >= runningMax[i]){
      runningMax[i] = 0;
      for (int j = 0; j < idx_end; j++) {
        int val = fDataHistory[j][i];
        if (val > runningMax[i]) runningMax[i] = val;
      }
    }
    else if(x_old <= runningMin[i]){
      runningMin[i] = 255;
      for (int j = 0; j < idx_end; j++) {
        int val = fDataHistory[j][i];
        if (val < runningMin[i]) runningMin[i] = val;
      }
    }

    // smooth over previous 3 values
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      int idx = idx_t - j;
      if (idx < 0) idx += N_TIME;
      sum += fDataHistory[idx][i];
    }
    int x_avg = sum/3;
    int x_scaled = map(x_avg, binFloor[i], runningMax[i], 0, runningMax[i]);

    // suppress low values
    int p0 = binFloor[i] + 3;  // suppress  values below this to 0
    int p1 = binFloor[i] + 6; // suppress values below this
    if (x_avg < p0) x_scaled = 0;
    if (x_avg < p1) x_scaled *= map(x_avg, p0, p1, 0, 100)/100.0;

    // Serial.print(x_new); 
    // Serial.print(x_avg); 
    peakToPeak[i] = x_scaled;
    // Serial.print(x_scaled); 
    // Serial.print('\t');
  }
  // Serial.print(0);
  // Serial.print('\t');
  // Serial.print(128);
  // Serial.println();
}

void setColor(int* pixelNums, int numPixels, int lightOn, int* rgbValues){
  for (int i = 0; i < numPixels; i++) {
    // Access the current pixel number
    int pixelNum = pixelNums[i];

    // Set the color of the current pixel using the RGB values and lightOn factor
    pixels.setPixelColor(pixelNum, pixels.Color(
      lightOn * rgbValues[0], 
      lightOn * rgbValues[1], 
      lightOn * rgbValues[2]
    ));
  }
}

//yields the maximum value 
void mergeBins(byte dataIn[], byte targetIdx[], byte dataOut[]){
  for (int i = 0; i < 4; i++) {
    dataOut[i] = 0;
  }
  for (int i = 0; i < LOG_N; i++) {
    Serial.print(dataIn[i]); 
    Serial.print('\t');
    dataOut[targetIdx[i]] += dataIn[i];
  }

  // Serial.print("\t :: \t");

  // for (int i = 0; i < 4; i++) {
  //   Serial.print(dataOut[i]); 
  //   Serial.print('\t');
  // }
  Serial.println();
  
}

void pixelAssign() {
  // for (int j = 1; j < 7; j+=2){
  //   int lightOn = 0;
  //   int binOne = (int)f_data[j] - (int)a[j];
  //   int binTwo = (int)f_data[j+1] - (int)a[j+1];
  //   if (binOne > 0 || binTwo > 0) lightOn = 1;
  //   pixels.setPixelColor(j, pixels.Color(
  //     lightOn*rgbValues[j][0], 
  //     lightOn*rgbValues[j][1], 
  //     lightOn*rgbValues[j][2]
  //   ));
  //   pixels.setPixelColor(j+1, pixels.Color(
  //     lightOn*rgbValues[j+1][0], 
  //     lightOn*rgbValues[j+1][1], 
  //     lightOn*rgbValues[j+1][2]
  //   ));
  //   Serial.print(lightOn); Serial.print('\t'); 
  // }
  
  for (int j = 0; j < numPIXELS; j++) {
    if (peakToPeak[j] > 0){
      pixels.setPixelColor(j, pixels.Color(
        (int)(rgbValues[j][0]), 
        (int)(rgbValues[j][1]), 
        (int)(rgbValues[j][2])
      ));
    } else {
      pixels.setPixelColor(j, pixels.Color(0,0,0));      
    }
    
  }
}
