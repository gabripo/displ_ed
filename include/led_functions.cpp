#include "led_functions.h"

void set_color_all_rows(CRGB* leds_values, const CRGB color) {
    for (pixelPos rowIdx = 0; rowIdx < leds_height; rowIdx++) {
        for (pixelPos ledInRow = 0; ledInRow < leds_width; ledInRow++) {
            leds_values[ledInRow] = color;
        }
    }
}

bool position_in_boundaries(const pixelPos xPos, const pixelPos yPos) {
    if ((xPos < leds_width) && (yPos < leds_height)) {
        return true;
    }
    return false;
}

pixelPos position_to_idx(const pixelPos xPos, const pixelPos yPos) {
    if (position_in_boundaries(xPos, yPos)) {
        return xPos + leds_width * yPos;
    }
    return 0;
}

CRGB get_color_by_position(CRGB* leds_values, const pixelPos xPos, const pixelPos yPos) {
    if (position_in_boundaries(xPos, yPos)) {
        return leds_values[position_to_idx(xPos, yPos)];
    }
    return CRGB();
}
