#include <FastLED.h>

#define DATA_PIN 9
#define NUM_LEDS 380
CRGB leds[NUM_LEDS];

#define YELLOW_COLOR CRGB::Yellow
#define GREEN_COLOR CRGB::Green
#define RED_COLOR CRGB::Red

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  fill_gradient_RGB(leds, 0, GREEN_COLOR, NUM_LEDS, RED_COLOR);
  FastLED.show();
}

void loop() {
  int delay_ms = 40; // Adjust this to change the speed of the running effect
  int brightness = 255; // Adjust this to change the brightness (0-255)

  // Move three LEDs along the strip
  for (int i = 0; i < NUM_LEDS; i++) {
    fill_gradient_RGB(leds, 0, GREEN_COLOR, NUM_LEDS, RED_COLOR);
    leds[i % NUM_LEDS] = YELLOW_COLOR;

    for (int j = 0; j < NUM_LEDS; j += 4) {
      leds[(i + j) % NUM_LEDS].fadeLightBy(brightness);
    }

    FastLED.show();
    delay(delay_ms);
  }
}
