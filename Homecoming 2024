#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    400

int lights[NUM_LEDS + 1];

int colorSelect = 0;

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);

  
}

void loop() {

  Sequence5();
  Sequence1();
  Sequence3();
  Sequence2();

}

void Sequence1() {

  int wait = 2500;
  int pulse = 2.5;
  int repeat = 2;

  for (int i = 0; i < repeat; i++) {
    SetColor(255, 0, 0);
    delay(wait);
    ColorClimbUp(pulse, 255,100,0);
    delay(wait);
    ColorClimbDown(pulse, 255,0,0);
  }

}

void Sequence2() {

  int wait = 2500;
  int pulse = 1.0;
  int repeat = 2;

  for (int i = 0; i < repeat; i++) {
      
    SetColor(255,0,0);

    //Sparkle to yellow
    SparkleColorChange(pulse, 255, 100, 0);
    delay(wait);

    //Sparkle to red
    SparkleColorChange(pulse, 255, 0, 0);
    delay(wait);

  }
}

void Sequence3() {

  //TODO: add yellow

  int wait = 100;
  int repeatRed = 10;
  int repeatYellow = 10;
  int repeatBoth = 2;

  for(int bothLoopVar = 0; bothLoopVar <  repeatBoth; bothLoopVar++) {

    for(int redLoopVar = 0; redLoopVar < repeatRed; redLoopVar++) {

      MixedLights2(50,0,0, 100,0,0, 150,0,0, 200,0,0, 250,0,0);
      delay(wait);
      MixedLights2(250,0,0, 50,0,0, 100,0,0, 150,0,0, 200,0,0);
      delay(wait);
      MixedLights2(200,0,0, 250,0,0, 50,0,0, 100,0,0, 150,0,0);
      delay(wait);
      MixedLights2(150,0,0, 200,0,0, 250,0,0, 50,0,0, 100,0,0);
      delay(wait);
      MixedLights2(100,0,0, 150,0,0, 200,0,0, 250,0,0, 50,0,0);
      delay(wait);

    }

    for(int yellowLoopVar = 0; yellowLoopVar < repeatYellow; yellowLoopVar++) {

      MixedLights2(50,20,0, 100,40,0, 150,60,0, 200,80,0, 250,100,0);
      delay(wait);
      MixedLights2(250,100,0, 50,20,0, 100,40,0, 150,60,0, 200,80,0);
      delay(wait);
      MixedLights2(200,80,0, 250,100,0, 50,20,0, 100,40,0, 150,60,0);
      delay(wait);
      MixedLights2(150,60,0, 200,80,0, 250,100,0, 50,20,0, 100,40,0);
      delay(wait);
      MixedLights2(100,40,0, 150,60,0, 200,80,0, 250,100,0, 50,20,0);
      delay(wait);

    }
  }
}

void Sequence4() {

  int wait = 250;
  int repeat = 10;

  for(int i = 0; i < repeat; i++) {

    MixedLights3(255,0,0, 225,100,0);
    delay(wait);
    MixedLights3(255,100,0, 255,0,0);
    delay(wait);

  }
}

void Sequence5() {
  int wait = 100; // Speed of movement
  int barWidth = 10; // Width of the color bars
  int repeat = 250; // NOTE: NUM_LEDS + barWidth; = Total movements needed to wrap around

  for (int i = 0; i < repeat; i++) {


    // Set the LEDs with alternating red and yellow bars
    for (int j = 0; j < NUM_LEDS; j++) {
      // Determine the current position in relation to the bar width
      int currentPosition = (j + i) % (2 * barWidth);

      // If the current position is in the range of the red bar
      if (currentPosition < barWidth) {
        leds[j] = CRGB(0,255,0); // Set red
      } else {
        leds[j] = CRGB(100,255,0); // Set yellow
      }
    }

    FastLED.show();
    delay(wait);
  }
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

void MixedLights4(
  int red1, int green1, int blue1,
  int red2, int green2, int blue2,
  int red3, int green3, int blue3,
  int red4, int green4, int blue4,
  int red5, int green5, int blue5,
  int red6, int green6, int blue6) {

  for (int place = 0; place < NUM_LEDS; place = place+6) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);
    leds[place+2] = CRGB(green3, red3, blue3);
    leds[place+3] = CRGB(green4, red4, blue4);
    leds[place+4] = CRGB(green5, red5, blue5);
    leds[place+5] = CRGB(green6, red6, blue6);

  }
  FastLED.show();
}

void MixedLights1(int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3) {

  for (int place = 0; place <= NUM_LEDS; place = place+3) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);
    leds[place+2] = CRGB(green3, red3, blue3);

  }
  FastLED.show();
}

void MixedLights3(int red1, int green1, int blue1, int red2, int green2, int blue2) {

  for (int place = 0; place <= NUM_LEDS; place = place+3) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);

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
  for(int place = 0; place <= NUM_LEDS; place++) {

    leds[place] = CRGB(green, red, blue);
    
  }
  FastLED.show();
}

void ColorSwitch(int initialRed, int initialGreen, int initialBlue, int newRed, int newGreen, int newBlue) {

  //fill
  for(int place = 0; place <= NUM_LEDS; place++) {

    leds[place] = CRGB(initialGreen, initialRed, initialBlue);
    
  }
  FastLED.show();

  //newColor
  for(int place = 0; place <= NUM_LEDS; place++) {

    leds[place] = CRGB(newGreen, newRed, newBlue);
    
  }
  FastLED.show();

}

void ColorClimbUp(int pulse, int red, int green, int blue) {


  for(int place = 0; place <= NUM_LEDS; place++) {

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
  for (int i = 0; i <= NUM_LEDS + 1; i++) {
    lights[i] = i;

  }

  size_t n = sizeof(lights) / sizeof(lights[0]);

  for (size_t i = 0; i < n - 1; i++) {
    size_t j = random(0, n - i);
    int t = lights[i];
    lights[i] = lights[j];
    lights[j] = t;
  }

  
  for(int i = 0; i <= NUM_LEDS-1; i++) {

    int place = lights[i];
    Serial.println(place);
    leds[place] = CRGB(green, red, blue);
    delay(pulse);
    FastLED.show();

  }
  
}
