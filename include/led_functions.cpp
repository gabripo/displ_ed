#include "led_functions.h"

void leds_refresh() {
    FastLED.show();
    FastLED.delay(seconds_per_frame);
}

void set_color_all_rows(CRGB* leds_values, const CRGB color) {
    for (pixelPos yPos = 0; yPos < leds_height; yPos++) {
        for (pixelPos xPos = 0; xPos < leds_width; xPos++) {
            leds_values[xPos + leds_width * yPos] = color;
        }
    }
}

void switch_off_all(CRGB* leds_values) {
    set_color_all_rows(leds_values, CRGB::Black);
}

bool position_in_boundaries(const pixelPosCouple xyPos) {
    if ((xyPos.x <= leds_width) && (xyPos.y <= leds_height)) {
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
