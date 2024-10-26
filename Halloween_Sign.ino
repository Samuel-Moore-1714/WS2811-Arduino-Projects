#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    100

int allLights[NUM_LEDS + 1];

int colorSelect = 0;

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);

  
}

void loop() {

  SetColor(0, 11, 255, 50, 0);
}


void SetColor(int startPlace, int endPlace, int red, int green, int blue) {
  //fill
  for(int place = startPlace; place < endPlace; place++) {
    leds[place] = CRGB(green, red, blue); 
  }
  FastLED.show();
}

void FillColor(int red, int green, int blue) {
  //fill
  for(int place = 0; place < NUM_LEDS; place++) {
    leds[place] = CRGB(green, red, blue); 
  }
  FastLED.show();
}

void SparkleColorChange(int pulse, int red, int green, int blue) {
  //sparkle
  for (int i = 0; i < NUM_LEDS; i++) {
    allLights[i] = i;

  }

  size_t n = sizeof(lights) / sizeof(lights[0]);

  for (size_t i = 0; i < n - 1; i++) {
    size_t j = random(0, n - i);
    int t = allLights[i];
    allLights[i] = allLights[j];
    allLights[j] = t;
  }

  for(int i = 0; i < NUM_LEDS; i++) {

    int place = allLights[i];
    Serial.println(place);
    leds[place] = CRGB(green, red, blue);
    delay(pulse);
    FastLED.show();
  } 
}