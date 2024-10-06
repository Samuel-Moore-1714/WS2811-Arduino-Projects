#include "SamLightLib.h"
#include <FastLED.h>

// Constructor
LightLib::LightLib(int ledPin, int numLeds) {
  _ledPin = ledPin;
  _numLeds = numLeds;

  // Allocate memory for the LEDs array
  _leds = new CRGB[_numLeds];

  // Initialize the LED strip
  FastLED.addLeds<WS2811, GRB>(_leds, _numLeds);
}


/*
  This method will set all lights to a desired color.

  parameters:
  red (int): red RGB value
  green (int): green RGB value
  blue (int): blue RGB value

  returns:
  void
*/
void LightLib::SetColor(int red, int green, int blue) {
  fill_solid(_leds, _numLeds, CRGB(red, green, blue));
  FastLED.show();
}

/*
  This method will loop though the string of lights and change the color

  parameters:
  pulse (int): delay between changing each LED color
  red (int): red RGB value
  green (int): green RGB value
  blue (int): blue RGB value

  returns:
  void
*/
void LightLib::ColorClimbUp(int pulse, int red, int green, int blue) {
  // loop through leds
  for(int place = 0; place <= _numLeds; place++) {
    // change led color
    _leds[place] = CRGB(green, red, blue);
    FastLED.show();
    // wait before moving onto the next light
    delay(pulse);
  }
}

/*
  This method will loop backwards though the string of lights and change the color

  parameters:
  pulse (int): delay between changing each LED color
  red (int): red RGB value
  green (int): green RGB value
  blue (int): blue RGB value

  returns:
  void
*/
void LightLib::ColorClimbDown(int pulse, int red, int green, int blue) {
  // loop through leds
  for(int place = 0; place >= _numLeds; place--) {
    // change led color
    _leds[place] = CRGB(green, red, blue);
    FastLED.show();
    // wait before moving onto the next light
    delay(pulse);
  }
}

/*
  This method will change the color of each led in a random order without repeating any leds.

  parameters:
    pulse (int): the delay between changing each led color
    red (int): red RGB value
    green (int): green RGB value
    blue (int): blue RGB value

  returns:
  void
*/
void LightLib::SparkleColorChange(int pulse, int red, int green, int blue) {

  // reorganize led array
  int sparkleLights[_numLeds + 1];
  for (int i = 0; i <= _numLeds + 1; i++) {
    sparkleLights[i] = i;

  }
  size_t n = sizeof(sparkleLights) / sizeof(sparkleLights[0]);
  for (size_t i = 0; i < n - 1; i++) {
    size_t j = random(0, n - i);
    int t = sparkleLights[i];
    sparkleLights[i] = sparkleLights[j];
    sparkleLights[j] = t;
  }

  // loop through reorganized led array
  for(int i = 0; i <= _numLeds - 1; i++) {
    int place = sparkleLights[i];

    // change led color
    _leds[place] = CRGB(green, red, blue);

    // wait before moving onto the next light
    delay(pulse);
    FastLED.show();
  }
}

/*
  This method will break the led strip into different colored bars that move across the strip

  parameters:
    pulse (int): the delay between changing each led color
    barWidth (int): amount of leds in each bar
    repeat (int): amount of times to repeat the function
    numColors (int): amount of different colored bars
    colors[] (CRGB[]): color of each bar

  returns:
    void
*/
void LightLib::BarShift(
  int pulse, int barWidth, int repeat, 
  int numColors, CRGB colors[]) {

  // Ensure numColors is greater than 0
  if (numColors < 1) return;

  // Repeat x amount of times
  for (int i = 0; i < repeat; i++) {

    // Set the LEDs with alternating bars
    for (int j = 0; j < _numLeds; j++) {
      // Determine the current position in relation to the bar width
      int currentPosition = (j + i) % (numColors * barWidth); // Use numColors here

      // Calculate the index of the color based on the current position
      int colorIndex = currentPosition / barWidth; // Determine the color section

      // Set the corresponding color
      _leds[j] = colors[colorIndex % numColors]; // Cycle through colors
    }
    FastLED.show();
    // Wait before moving on to the next light
    delay(pulse);
  }
}

/*
  This method will break the led strip into a set amount of different colors

  parameters:
    numColors (int): amount of different colored bars
    colors[] (CRGB[]): color of each bar

  returns:
    void
*/
void LightLib::SetColors(int numColors, CRGB colors[]) {
    // Ensure numColors does not exceed the number of LEDs
    numColors = min(numColors, _numLeds);
  
    // Calculate the number of LEDs per section
    int sectionDivider = _numLeds / numColors;

    // Loop through all LEDs and assign colors based on section
    for (int place = 0; place < _numLeds; place++) {
        // Determine the section index
        int sectionIndex = place / sectionDivider;
        // Use modulo to handle the case where numColors does not divide _numLeds evenly
        _leds[place] = colors[sectionIndex % numColors]; // Assign the color for that section
    }
    FastLED.show();
}

/*
  This method will change the leds to alternating colors

  parameters:
    numColors (int): amount of different colors
    colors[] (CRGB[]): colors

  returns:
    void
*/
void LightLib::MixedLights(int numColors, CRGB colors[]) {

  // Set colors in a loop
  for (int place = 0; place < _numLeds; place++) {
    // Use modulo to cycle through colors
    _leds[place] = colors[place % numColors];
  }
  FastLED.show();
}
