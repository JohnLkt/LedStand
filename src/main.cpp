#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100); // Adjust brightness if needed
}

// Rainbow effect function
void rainbowEffect()
{
  static uint8_t hue = 0;

  // Fill the entire strip with a rainbow
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(hue + i * 255 / NUM_LEDS, 255, 255);
  }

  FastLED.show();   // Display the updated LEDs
  FastLED.delay(5); // Adjust the delay to control the speed of the rainbow
  hue++;            // Increment the hue for the next iteration
}

// Main loop
void loop()
{
  rainbowEffect();
}
