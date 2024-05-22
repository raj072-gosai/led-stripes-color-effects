#include <Adafruit_NeoPixel.h>

#define PIN_STRIP1 23        // greadient 380
#define PIN_STRIP2 22        //  greadient 380
#define PIN_STRIP3 1         //  greadient 380
#define PIN_STRIP4 3         //  greadient 140
#define PIN_STRIP5 21        //  greadient 140
#define RED_PIN 19           //  strip (red color)
#define GREEN_PIN 18         //  strip (green color)
#define NUMPIXELS_STRIP1 380  // 380  give the number of greadient color
#define NUMPIXELS_STRIP2 140  // 140   give the number of greadient color
#define NUMPIXELS_RED 140     //140 statc red
#define NUMPIXELS_GREEN 140   //140 statc green

int runningPosition1 = 0;  // Variable for the running position on strip1
int brightness = 128;      // Initial brightness value (0 to 255)
int speed = 50;       // Adjust the delay to control the speed of the running effect

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS_STRIP1, PIN_STRIP1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS_STRIP1, PIN_STRIP2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS_STRIP1, PIN_STRIP3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUMPIXELS_STRIP2, PIN_STRIP4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUMPIXELS_STRIP2, PIN_STRIP5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel redStrip = Adafruit_NeoPixel(NUMPIXELS_RED, RED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel greenStrip = Adafruit_NeoPixel(NUMPIXELS_GREEN, GREEN_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  redStrip.begin();    // Initialize the first NeoPixel strip
  greenStrip.begin();  // Initialize the second NeoPixel strip


  strip1.setBrightness(brightness);
  strip2.setBrightness(brightness);
  strip3.setBrightness(brightness);
  strip4.setBrightness(brightness);
  strip5.setBrightness(brightness);
  redStrip.setBrightness(brightness);
  greenStrip.setBrightness(brightness);

  colorWipe(redStrip, 255, 0, 0);//red color static
  colorWipe(greenStrip, 0, 255, 0);// green color static


  strip1.show();  // Initialize all pixels to 'off' for the first strip
  strip2.show();  // Initialize all pixels to 'off' for the second strip
  strip3.show();
  strip4.show();  // Initialize all pixels to 'off' for the second strip
  strip5.show();
  redStrip.show();
  greenStrip.show();
}

void loop() {
  greenToRedGradient(strip1, NUMPIXELS_STRIP1, runningPosition1);
  greenToRedGradient(strip2, NUMPIXELS_STRIP1, runningPosition1);
  greenToRedGradient(strip3, NUMPIXELS_STRIP1, runningPosition1);
  greenToRedGradient(strip4, NUMPIXELS_STRIP2, runningPosition1);
  greenToRedGradient(strip5, NUMPIXELS_STRIP2, runningPosition1);


  runningPosition1 = (runningPosition1 + 1) % NUMPIXELS_STRIP1;
  //  delay(4);
}

void greenToRedGradient(Adafruit_NeoPixel& strip, int numPixels, int position) {
  for (int i = 0; i < numPixels; i++) {
    // Calculate the color value based on the position in the gradient and running position
    uint8_t green = map((i - position + numPixels) % numPixels, 0, numPixels - 1, 255, 0);
    uint8_t red = map((i - position + numPixels) % numPixels, 0, numPixels - 1, 0, 255);

    // Set the color of the current pixel
    strip.setPixelColor(i, red, green, 0);
  }

  strip.show();  // Update the LED strip with the new colors
   delay(speed);  // Adjust the delay to control the speed of the running effect
}

// Fill the dots one after the other with a color for a specific strip
void colorWipe(Adafruit_NeoPixel& strip,int red,int green , int blue) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(red,green,blue));

  }
   strip.show();
}
