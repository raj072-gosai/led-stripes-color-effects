#include <Adafruit_NeoPixel.h>

#define PIN            8 // Define the pin where the data line is connected to
#define NUMPIXELS      30 // Define the number of pixels in your LED strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Run the white color wipe effect
  colorWipe(strip.Color(255, 255, 255), 20);  // White
  delay(100);
  // Turn off all LEDs
  colorWipe(strip.Color(0, 0, 0), 0);  // Off

  // Delay for 5 seconds before rerunning the loop
  delay(5000);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t color, int wait) {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
