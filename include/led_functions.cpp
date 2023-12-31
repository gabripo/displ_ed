#include "led_functions.h"

void leds_refresh() {
    FastLED.show();
    FastLED.delay(seconds_per_frame);
}

void leds_refresh_wait(const unsigned long long int timeToWait) {
    leds_refresh();
    FastLED.delay(timeToWait);
}

void set_color_all_rows(CRGB* leds_values, const CRGB color) {
    for (pixelPos yPos = 0; yPos < leds_height; yPos++) {
        for (pixelPos xPos = 0; xPos < leds_width; xPos++) {
            leds_values[xPos + leds_width * yPos] = color;
        }
    }
    leds_refresh();
}

void switch_off_all(CRGB* leds_values) {
    set_color_all_rows(leds_values, CRGB::Black);
    leds_refresh();
}

void rgb_test(CRGB* leds_values) {
    set_color_all_rows(leds_values, CRGB::Red);
    leds_refresh_wait(1000);
    set_color_all_rows(leds_values, CRGB::Green);
    leds_refresh_wait(1000);
    set_color_all_rows(leds_values, CRGB::Blue);
    leds_refresh_wait(1000);
    set_color_all_rows(leds_values, CRGB::White);
    leds_refresh_wait(1000);
    switch_off_all(leds_values);
    leds_refresh_wait(1000);
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

void turnon_nth_led_each_stripe(CRGB* leds_values, const pixelPos nthPos, const CRGB colorToSet) {
    if (nthPos > leds_width) {
        set_color_all_rows(leds_values, CRGB::Red);
        return;
    }
    pixelPosCouple xyPosToSet;
    xyPosToSet.x = nthPos;
    for (pixelPos numRow = 0; numRow < leds_height; numRow++) {
        xyPosToSet.y = numRow;
        set_color_by_position(leds_values, xyPosToSet, colorToSet);
    }
    leds_refresh();
}

void turnon_incrementally(CRGB* leds_values) {
    for (pixelPos currLed = 0; currLed < num_leds; currLed++) {
        leds_values[currLed] = CRGB::Red;
        leds_refresh_wait(500);
    }
}

void load_crgb_image(CRGB* leds_values, const CRGB* imgToLoad, unsigned int* imgLoaded) {
    if (!(*imgLoaded)) {
        memcpy(leds_values, imgToLoad, num_leds * sizeof(CRGB));
        leds_refresh();
        *imgLoaded = 1;
        Serial.println("Image loaded!");
    }
}