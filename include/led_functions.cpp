#include "led_functions.h"

void set_color_all_rows(CRGB* leds_values, const CRGB color) {
    for (size_t rowIdx = 0; rowIdx < leds_height; rowIdx++) {
        for (size_t ledInRow = 0; ledInRow < leds_width; ledInRow++) {
            leds_values[ledInRow] = color;
        }
    }
}