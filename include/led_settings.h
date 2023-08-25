#ifndef LED_SETTINGS
#define LED_SETTINGS

#include <FastLED.h>

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 96
#define ARDUINO_DATA_PIN 3

static const unsigned int leds_width = 20;
static const unsigned int leds_height = 15;
static const unsigned long long int num_leds = leds_width * leds_height;

CRGB leds[num_leds];

static const unsigned int frames_per_second = 120;
static const float seconds_per_frame = 1000.0 / (float)frames_per_second;
#endif