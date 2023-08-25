#include "led_functions.h"

void set_color_all_rows(CRGB* leds_values, const CRGB color) {
    for (pixelPos rowIdx = 0; rowIdx < leds_height; rowIdx++) {
        for (pixelPos ledInRow = 0; ledInRow < leds_width; ledInRow++) {
            leds_values[ledInRow] = color;
        }
    }
}

bool position_in_boundaries(const pixelPosCouple xyPos) {
    if ((xyPos.x < leds_width) && (xyPos.y < leds_height)) {
        return true;
    }
    return false;
}

pixelPos position_to_idx(const pixelPosCouple xyPos) {
    if (position_in_boundaries(xyPos)) {
        return xyPos.x + leds_width * xyPos.y;
    }
    return 0;
}

CRGB get_color_by_position(CRGB* leds_values, const pixelPosCouple xyPos) {
    if (position_in_boundaries(xyPos)) {
        return leds_values[position_to_idx(xyPos)];
    }
    return CRGB();
}

void set_color_by_position(CRGB* leds_values, const pixelPosCouple xyPos, const CRGB colorToSet) {
    if (position_in_boundaries(xyPos)) {
        leds_values[position_to_idx(xyPos)] = colorToSet;
    }
}
