#ifndef SAMLIGHTLIBH
#define SAMLIGHTLIBH

#include <FastLED.h>

class LightLib{
  public:
    LightLib(int ledPin, int numLeds);

    void SetColor(int red, int green, int blue);
    void ColorClimbUp(int pulse, int red, int green, int blue);
    void ColorClimbDown(int pulse, int red, int green, int blue);
    void SparkleColorChange(int pulse, int red, int green, int blue);
    void MixedLights(int numColors, CRGB colors[]);
    void SetColors(int numColors, CRGB colors[]);
    void BarShift(
      int wait, int barWidth, int repeat, 
      int numColors, CRGB colors[]);

  private:
    int _ledPin;
    int _numLeds;
    CRGB* _leds;
};
#endif