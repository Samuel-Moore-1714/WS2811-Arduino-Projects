#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    430

int lights[NUM_LEDS + 1];

int colorSelect = 0;

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);

  
}

void loop() {
  
  Sequence1();
  Sequence2();
  Sequence3();

}

void Sequence1() {
  int pulse = 10;
  int wait = 0;
  int repeat = 1;

  SetColor(255,0,0);

  for (int i = 0; i < repeat; i++) {

    ColorClimbUp(pulse, 255,0,0);
    delay(wait);
    ColorClimbUp(pulse, 255,255,255);
    delay(wait);
    ColorClimbUp(pulse, 0,0,255);
    delay(wait);
  };

  ColorClimbUp(pulse, 255,0,0);
}

void Sequence2() {
  int pulse = 5;
  int wait = 0;
  int repeat = 1;

  SetColor(255,0,0);

  for (int i = 0; i < repeat; i++) {

    SparkleColorChange(pulse, 255,0,0);
    delay(wait);
    SparkleColorChange(pulse, 255,255,255);
    delay(wait);
    SparkleColorChange(pulse, 0,0,255);
    delay(wait);
  };

  SparkleColorChange(pulse, 255,0,0);
}

void Sequence3() {
  int pulse = 50;
  int barWidth = 40;
  int numColors = 3;
  int repeat = (NUM_LEDS + 1);

  CRGB colors[] = {
    CRGB(0,255,0),
    CRGB(255,255,255),
    CRGB(0,0,255)
  };

  BarShift(pulse, barWidth, repeat, numColors, colors);
}


void MixedLights2(int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3, int red4, int green4, int blue4, int red5, int green5, int blue5) {

  for (int place = 0; place < NUM_LEDS; place = place+5) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);
    leds[place+2] = CRGB(green3, red3, blue3);
    leds[place+3] = CRGB(green4, red4, blue4);
    leds[place+4] = CRGB(green5, red5, blue5);

  }
  FastLED.show();
}

void MixedLights1(int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3) {

  for (int place = 0; place < NUM_LEDS; place = place+3) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);
    leds[place+2] = CRGB(green3, red3, blue3);

  }
  FastLED.show();
}

void ChristmasFade() {

  int green = 0;
  int red = 0;
  int blue = 0;

  int pulse = 2.5;

  int wait = 1000;

  SetColor(255, 0, 0);
  delay(wait);

  for (int i = 0; i < 255; i++) {

    red--;
    green++;
    SetColor(red, green, blue);
    delay(pulse);

  }

  SetColor(0, 255, 0);
  delay(wait);

  red = 0;
  blue = 0;
  green = 255;

  for (int i = 0; i < 255; i++) {

    red++;
    blue++;
    SetColor(red, green, blue);
    delay(pulse);

  }

  SetColor(255, 255, 255);
  delay(wait);

  red = 255;
  green = 255;
  blue = 255;

  for (int i = 0; i < 255; i++) {

    green--;
    blue--;
    SetColor(red, green, blue);
    delay(pulse);

  }

  delay(wait);
  
}


void SetThreeColors(int topRed, int topGreen, int topBlue, int midRed, int midGreen, int midBlue, int bottomRed, int bottomGreen, int bottomBlue) {

  int sectionDivider = NUM_LEDS / 3;

  //bottom
  for(int place = 0; place <= sectionDivider; place++) {

    leds[place] = CRGB(bottomGreen, bottomRed, bottomBlue);
    
  }
  FastLED.show();

  //middle
  for(int place = sectionDivider; place <= sectionDivider * 2; place++) {

    leds[place] = CRGB(midGreen, midRed, midBlue);
    
  }
  FastLED.show();

  //top
  for(int place = sectionDivider * 2; place <= (sectionDivider * 3); place++) {

    leds[place] = CRGB(topGreen, topRed, topBlue);
    
  }
  FastLED.show();
}


void SetColor(int red, int green, int blue) {

  //fill
  for(int place = 0; place < NUM_LEDS; place++) {

    leds[place] = CRGB(green, red, blue);
    
  }
  FastLED.show();
}

void ColorSwitch(int initialRed, int initialGreen, int initialBlue, int newRed, int newGreen, int newBlue) {

  //fill
  for(int place = 0; place < NUM_LEDS; place++) {

    leds[place] = CRGB(initialGreen, initialRed, initialBlue);
    
  }
  FastLED.show();

  //newColor
  for(int place = 0; place < NUM_LEDS; place++) {

    leds[place] = CRGB(newGreen, newRed, newBlue);
    
  }
  FastLED.show();

}

void ColorClimbUp(int pulse, int red, int green, int blue) {


  for(int place = 0; place < NUM_LEDS; place++) {

    leds[place] = CRGB(green, red, blue);
    FastLED.show();
    delay(pulse);
  }

}

void ColorClimbDown(int pulse, int red, int green, int blue) {

  for(int place = NUM_LEDS; place >= 0; place--) {

    leds[place] = CRGB(green, red, blue);
    FastLED.show();
    delay(pulse);
  }
}

void SparkleColorChange(int pulse, int red, int green, int blue) {


  //sparkle
  for (int i = 0; i < NUM_LEDS; i++) {
    lights[i] = i;

  }

  size_t n = sizeof(lights) / sizeof(lights[0]);

  for (size_t i = 0; i < n - 1; i++) {
    size_t j = random(0, n - i);
    int t = lights[i];
    lights[i] = lights[j];
    lights[j] = t;
  }

  
  for(int i = 0; i < NUM_LEDS; i++) {

    int place = lights[i];
    Serial.println(place);
    leds[place] = CRGB(green, red, blue);
    delay(pulse);
    FastLED.show();

  }
  
}

void BarShift(
  int pulse, int barWidth, int repeat, 
  int numColors, CRGB colors[]) {

  // Ensure numColors is greater than 0
  if (numColors < 1) return;

  // Repeat x amount of times
  for (int i = 0; i < repeat; i++) {
    
    // Set the LEDs with alternating bars
    for (int j = 0; j < NUM_LEDS; j++) {
      // Use floor division for color index calculation
      int colorIndex = (int)floor((float)(j - i) / barWidth) % numColors;

      // Handle negative mod correctly
      if (colorIndex < 0) {
        colorIndex += numColors;
      }

      // Set the corresponding color
      leds[j] = colors[colorIndex];
    }

    // Show the result and delay for pulse timing
    FastLED.show();
    delay(pulse);
  }
}
