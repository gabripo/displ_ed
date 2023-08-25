#ifndef LED_FUNCTIONS
#define LED_FUNCTIONS

#include <Arduino.h>
#include <FastLED.h>

#include "led_settings.h"

void set_color_all_rows(CRGB* leds_values, const CRGB color);

#endif