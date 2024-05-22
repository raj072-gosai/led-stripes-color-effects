#include <FastLED.h>

#define LED_PIN     15   // Define the pin to which the LED strip is connected
#define NUM_LEDS    140  // Define the number of LEDs in your strip

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  // Define LED type and color order
}

void loop() {
  redGlowEffect(1);  // Adjust the value (10 in this case) to control the glow intensity
}

void redGlowEffect(int durationSeconds) {
  for (int i = 20; i < 256; ++i) {
    fill_solid(leds, NUM_LEDS, CRGB(i, 0, i));  // Set the color to magenta with varying intensity
    FastLED.show();
    delay(10);
  }

  for (int i = 255; i >= 20; --i) {
    fill_solid(leds, NUM_LEDS, CRGB(i, 0, i));  // Set the color to magenta with varying intensity
    FastLED.show();
    delay(10);
  }

  delay(durationSeconds * 10);  // Wait for the specified duration
}
