#include <Arduino.h>
#include <FastLED.h>

#include "images.h"
#include "led_functions.cpp"
#include "led_settings.h"
#include "motion_sensor.cpp"

FASTLED_USING_NAMESPACE

// #define FRAMES_PER_SECOND 120

// void nextPattern();
// void rainbow();
// void rainbowWithGlitter();
// void addGlitter(fract8 chanceOfGlitter);
// void confetti();
// void sinelon();
// void bpm();
// void juggle();

void setup() {
    // delay(3000);  // 3 second delay for recovery
    Serial.begin(9600);

    FastLED.addLeds<LED_TYPE, ARDUINO_DATA_PIN, COLOR_ORDER>(leds, num_leds);

    FastLED.setBrightness(BRIGHTNESS);
    // rgb_test(leds);
    setup_motion_sensor();

    // for (size_t led_row = 0; led_row < leds_height; led_row++) {
    //     leds[led_row * leds_width] = CRGB::Red;
    // }
}

// // List of patterns to cycle through.  Each is defined as a separate function below.
// typedef void (*SimplePatternList[])();
// SimplePatternList gPatterns = {rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm};

// uint8_t gCurrentPatternNumber = 0;  // Index number of which pattern is current
// uint8_t gHue = 0;                   // rotating "base color" used by many of the patterns

void loop() {
    // if (is_motion_started()) {
    //     Serial.println("Motion detected!");
    //     set_color_all_rows(leds, CRGB::Red);
    // }
    // if (is_motion_finished()) {  // pin state change: HIGH -> LOW
    //     Serial.println("Motion stopped!");
    //     switch_off_all(leds);
    // }
    if (isMotion) {
        Serial.println("Motion!");
        // set_color_all_rows(leds, CRGB::Red);
        load_image(leds, img_masterBall);
    } else {
        switch_off_all(leds);
    }
    // Serial.println(digitalRead(interruptPin));
    // Serial.println();

    // Call the current pattern function once, updating the 'leds' array
    // gPatterns[gCurrentPatternNumber]();

    // send the 'leds' array out to the actual LED strip
    // FastLED.show();
    // insert a delay to keep the framerate modest
    // FastLED.delay(1000 / FRAMES_PER_SECOND);

    // EVERY_N_MILLISECONDS(20) { gHue++; }    // slowly cycle the "base color" through the rainbow
    // EVERY_N_SECONDS(10) { nextPattern(); }  // change patterns periodically
}

// #define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// void nextPattern() {
//     // add one to the current pattern number, and wrap around at the end
//     gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
// }

// void rainbow() {
//     // FastLED's built-in rainbow generator
//     fill_rainbow(leds, NUM_LEDS, gHue, 7);
// }

// void rainbowWithGlitter() {
//     // built-in FastLED rainbow, plus some random sparkly glitter
//     rainbow();
//     addGlitter(80);
// }

// void addGlitter(fract8 chanceOfGlitter) {
//     if (random8() < chanceOfGlitter) {
//         leds[random16(NUM_LEDS)] += CRGB::White;
//     }
// }

// void confetti() {
//     // random colored speckles that blink in and fade smoothly
//     fadeToBlackBy(leds, NUM_LEDS, 10);
//     int pos = random16(NUM_LEDS);
//     leds[pos] += CHSV(gHue + random8(64), 200, 255);
// }

// void sinelon() {
//     // a colored dot sweeping back and forth, with fading trails
//     fadeToBlackBy(leds, NUM_LEDS, 20);
//     int pos = beatsin16(13, 0, NUM_LEDS - 1);
//     leds[pos] += CHSV(gHue, 255, 192);
// }

// void bpm() {
//     // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
//     uint8_t BeatsPerMinute = 62;
//     CRGBPalette16 palette = PartyColors_p;
//     uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
//     for (int i = 0; i < NUM_LEDS; i++) {  // 9948
//         leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
//     }
// }

// void juggle() {
//     // eight colored dots, weaving in and out of sync with each other
//     fadeToBlackBy(leds, NUM_LEDS, 20);
//     uint8_t dothue = 0;
//     for (int i = 0; i < 8; i++) {
//         leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
//         dothue += 32;
//     }
// }
