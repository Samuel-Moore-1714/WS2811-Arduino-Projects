#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    500

int lights[NUM_LEDS + 1];

int colorDelay;
int pulse;

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
  
  Sequence1();
  Sequence2();
  Sequence3();
  Sequence4();
  Sequence5();
  Sequence6();
  Sequence8();

}

void Sequence1() {

  colorDelay = 5000;
  pulse = 20;

  SetColor(255, 0, 0);
  delay(colorDelay);
  ColorClimbUp(pulse, 0, 255, 0);
  delay(colorDelay);
  ColorClimbDown(pulse, 255, 255, 255);
  delay(colorDelay);
  ColorClimbUp(pulse, 255, 0, 0);
  delay(colorDelay);

}

void Sequence2() {

  pulse = 2500;

  SetColor(255, 0, 0);
  delay(pulse);
  SetColor(0, 255, 0);
  delay(pulse);
  SetColor(255, 255, 255);
  delay(pulse);
  SetColor(255, 0, 0);
  delay(pulse);
  SetColor(0, 255, 0);
  delay(pulse);
  SetColor(255, 255, 255);
  delay(pulse);
  SetColor(255, 0, 0);
  delay(pulse);

}

void Sequence3() {

  pulse = 20;

  SetColor(255,0,0);

  //Sparkle to green
  SparkleColorChange(pulse, 0, 255, 0);
  delay(5000);

  //Sparkle to white
  SparkleColorChange(pulse, 255, 255, 255);
  delay(5000);

  //Sparkle to red
  SparkleColorChange(pulse, 255, 0, 0);
  delay(5000);


}

void Sequence4() {

  colorDelay = 1000;

  for(int i = 0; i <= 5; i++) {
    SetThreeColors(0, 255, 0, 255, 255, 255, 255, 0, 0);
    delay(colorDelay);
    SetThreeColors(255, 255, 255, 255, 0, 0, 0, 255, 0);
    delay(colorDelay);
    SetThreeColors(255, 0, 0, 0, 255, 0, 255, 255, 255);
    delay(colorDelay);
  }

}

void Sequence5() {

  ChristmasFade();
}

void Sequence6() {

  colorDelay = 1000;

  for(int i = 0; i <= 10; i++) {

    MixedLights1(255,0,0, 0,255,0, 255,255,255);
    delay(colorDelay);
    MixedLights1(255,255,255, 255,0,0, 0,255,0);
    delay(colorDelay);
    MixedLights1(0,255,0, 255,255,255, 255,0,0);
    delay(colorDelay);

  }

}

//red = 255,0,0
//yellow = 255, 150, 0
//green = 0,255,0
//orange = 255,50,0
//blue = 0,0,255

//FIXME: Colors are off at the end
void Sequence7() {

  colorDelay = 1000;

  for(int i = 0; i <= 10; i++) {

    MixedLights2(255,0,0, 255,250,0, 0,255,0, 255,50,0, 0,0,255);
    delay(colorDelay);
    MixedLights2(0,0,255, 255,0,0, 255,250,0, 0,255,0, 255,50,0);
    delay(colorDelay);
    MixedLights2(255,50,0, 0,0,255, 255,0,0, 255,250,0, 0,255,0);
    delay(colorDelay);
    MixedLights2(0,255,0, 255,50,0, 0,0,255, 255,0,0, 255,250,0);
    delay(colorDelay);
    MixedLights2(255,250,0, 0,255,0, 255,50,0, 0,0,255, 255,0,0);
    delay(colorDelay);

  }

}

void Sequence8() {

  for(int i = 0; i <= 5; i++) {
    ChristmasBrightnessFade(100, 10);
  }

}

void ChristmasBrightnessFade(int colorDelay, int colorRepeat) {

  for(int i = 0; i <= colorRepeat; i++) {

    MixedLights2(50,0,0, 100,0,0, 150,0,0, 200,0,0, 250,0,0);
    delay(colorDelay);
    MixedLights2(250,0,0, 50,0,0, 100,0,0, 150,0,0, 200,0,0);
    delay(colorDelay);
    MixedLights2(200,0,0, 250,0,0, 50,0,0, 100,0,0, 150,0,0);
    delay(colorDelay);
    MixedLights2(150,0,0, 200,0,0, 250,0,0, 50,0,0, 100,0,0);
    delay(colorDelay);
    MixedLights2(100,0,0, 150,0,0, 200,0,0, 250,0,0, 50,0,0);
    delay(colorDelay);

  }

  for(int i = 0; i <= colorRepeat; i++) {

    MixedLights2(0,50,0, 0,100,0, 0,150,0, 0,100,0, 0,250,0);
    delay(colorDelay);
    MixedLights2(0,250,0, 0,50,0, 0,100,0, 0,150,0, 0,200,0);
    delay(colorDelay);
    MixedLights2(0,200,0, 0,250,0, 0,50,0, 0,100,0, 0,150,0);
    delay(colorDelay);
    MixedLights2(0,150,0, 0,200,0, 0,250,0, 0,50,0, 0,100,0);
    delay(colorDelay);
    MixedLights2(0,100,0, 0,150,0, 0,200,0, 0,250,0, 0,50,0);
    delay(colorDelay);

  }

  for(int i = 0; i <= colorRepeat; i++) {

    MixedLights2(50,50,50, 100,100,100, 150,150,150, 100,100,100, 100,100,100);
    delay(colorDelay);
    MixedLights2(250,250,250, 50,50,50, 100,100,100, 150,150,150, 200,200,200);
    delay(colorDelay);
    MixedLights2(200,200,200, 250,250,250, 50,50,50, 100,100,100, 150,150,150);
    delay(colorDelay);
    MixedLights2(150,150,150, 200,200,200, 250,250,250, 50,50,50, 100,100,100);
    delay(colorDelay);
    MixedLights2(100,100,100, 100,100,100, 200,200,200, 250,250,250, 50,50,50);
    delay(colorDelay);

  }
}

void MixedLights2(int red1, int green1, int blue1, int red2, int green2, int blue2, int red3, int green3, int blue3, int red4, int green4, int blue4, int red5, int green5, int blue5) {

  for (int place = 0; place <= NUM_LEDS; place = place+5) {

    leds[place] = CRGB(green1, red1, blue1);
    leds[place+1] = CRGB(green2, red2, blue2);
    leds[place+2] = CRGB(green3, red3, blue3);
    leds[place+3] = CRGB(green4, red4, blue4);
    leds[place+4] = CRGB(green5, red5, blue5);

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

void ChristmasFade() {

  int green = 0;
  int red = 0;
  int blue = 0;

  pulse = 20;

  colorDelay = 5000;

  SetColor(255, 0, 0);
  delay(colorDelay);

  for (int i = 0; i < 255; i++) {

    red--;
    green++;
    SetColor(red, green, blue);
    delay(pulse);

  }

  SetColor(0, 255, 0);
  delay(colorDelay);

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
  delay(colorDelay);

  red = 255;
  green = 255;
  blue = 255;

  for (int i = 0; i < 255; i++) {

    green--;
    blue--;
    SetColor(red, green, blue);
    delay(pulse);

  }

  delay(colorDelay);
  
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
