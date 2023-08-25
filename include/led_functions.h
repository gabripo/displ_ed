#ifndef LED_FUNCTIONS
#define LED_FUNCTIONS

#include <Arduino.h>
#include <FastLED.h>

#include "led_settings.h"

typedef unsigned long long int pixelPos;
typedef struct {
    pixelPos x;
    pixelPos y;
} pixelPosCouple;

void set_color_all_rows(CRGB* leds_values, const CRGB color);

bool position_in_boundaries(const pixelPosCouple xyPos);
pixelPos position_to_idx(const pixelPosCouple xyPos);
CRGB get_color_by_position(CRGB* leds_values, const pixelPosCouple xyPos);

#endif