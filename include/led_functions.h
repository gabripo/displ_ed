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
byte imgLoaded = 0;

void leds_refresh();
void leds_refresh_wait(const unsigned long long int timeToWait);

void set_color_all_rows(CRGB* leds_values, const CRGB color);
void switch_off_all(CRGB* leds_values);
void rgb_test(CRGB* leds_values);

bool position_in_boundaries(const pixelPosCouple xyPos);
pixelPos position_to_idx(const pixelPosCouple xyPos);
CRGB get_color_by_position(CRGB* leds_values, const pixelPosCouple xyPos);
void set_color_by_position(CRGB* leds_values, const pixelPosCouple xyPos, const CRGB colorToSet);
void turnon_nth_led_each_stripe(CRGB* leds_values, const pixelPos nthPos, const CRGB colorToSet);
void turnon_incrementally(CRGB* leds_values);

void load_crgb_image(CRGB* leds_values, const CRGB* imgToLoad, byte* imgLoaded);
#endif