#ifndef LED_FUNCTIONS
#define LED_FUNCTIONS

#include <Arduino.h>
#include <FastLED.h>

#include "led_settings.h"

typedef unsigned long long int pixelPos;

void set_color_all_rows(CRGB* leds_values, const CRGB color);

bool position_in_boundaries(const pixelPos xPos, const pixelPos yPos);
pixelPos position_to_idx(const pixelPos xPos, const pixelPos yPos);
CRGB get_color_by_position(CRGB* leds_values, const pixelPos xPos, const pixelPos yPos);

#endif