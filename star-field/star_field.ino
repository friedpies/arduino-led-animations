// FastLED animation that randomly flashes "stars" and fades out over time
// by Kenneth Marut

#include <FastLED.h>

#define LED_PIN     6
#define CHIPSET     WS2811
#define NUM_LEDS    22
#define FRAMES_PER_SECOND 20

CRGB leds[NUM_LEDS];
CRGB brightnessSubtractor;

float starSpeed[NUM_LEDS];
int fadeSpeed = 5;
int decayRate = 25;
int starRate = 7; // stars per second

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  brightnessSubtractor = CHSV(0, 0, fadeSpeed);
}

void loop() {
  if (millis() % (1000 / starRate) == 0) {
    leds[random(NUM_LEDS)] = CHSV(0, 0, 100); // create white stars
  }

  if (millis() % (1000 / decayRate) == 0) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] -= brightnessSubtractor;
    }
    FastLED.show();
  }
}


