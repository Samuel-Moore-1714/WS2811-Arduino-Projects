#include <FastLED.h>
#include <vector>

#define LED_PIN     7
#define NUM_LEDS    351

int lights[NUM_LEDS + 1];

int colorSelect = 0;

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);

  
}

void loop() {


}

void SetColor(int red, int green, int blue) {

  //fill
  for(int place = 0; place <= NUM_LEDS; place++) {

    leds[place] = CRGB(green, red, blue);
    
  }
  FastLED.show();
}

void ColorClimbUp(uint16_t pulse, const CRGB colors[], uint8_t numColors) {
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        CRGB color = colors[i % numColors];

        leds[i] = color;
        FastLED.show();

        delay(pulse);  // milliseconds
    }
}

void ColorClimbDown(uint16_t pulse, const CRGB colors[], uint8_t numColors) {
    for (uint16_t i = NUM_LEDS; i > 0; i--) {
        CRGB color = colors[i % numColors];

        leds[i] = color;
        FastLED.show();

        delay(pulse);  // milliseconds
    }
}