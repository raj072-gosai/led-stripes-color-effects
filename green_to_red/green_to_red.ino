#include <FastLED.h>

#define DATA_PIN 9
#define NUM_LEDS 140
CRGB leds[NUM_LEDS];

#define GREEN_COLOR CRGB::Green
#define RED_COLOR CRGB::Red

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {
  int delay_ms = 50; // Adjust this to change the speed of the running effect
  int gradientLength = 140; // Adjust this to change the length of the gradient

  for (int offset = 0; offset < NUM_LEDS; offset++) {
    // Calculate gradient position based on the offset
    int gradientPosition = offset % gradientLength;

    // Interpolate between green and red
    CRGB color = blend(GREEN_COLOR, RED_COLOR, map(gradientPosition, 0, gradientLength - 1, 0, 255));

    // Set the color at the current position
    leds[offset % NUM_LEDS] = color;

    FastLED.show();
    delay(delay_ms);
  }
}
