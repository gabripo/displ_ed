#include <Arduino.h>
#include <FastLED.h>

#include "images.h"
#include "led_functions.cpp"
#include "led_settings.h"
#include "motion_sensor.cpp"

FASTLED_USING_NAMESPACE

void setup() {
    Serial.begin(9600);

    FastLED.addLeds<LED_TYPE, ARDUINO_DATA_PIN, COLOR_ORDER>(leds, num_leds);

    FastLED.setBrightness(BRIGHTNESS);
    // setup_motion_sensor();
    // turnon_incrementally(leds);
    imgLoaded = 0;
    load_image(leds, img_masterBall, &imgLoaded);
}

void loop() {
    // if (isMotion) {
    //     Serial.println("Motion!");
    //     set_color_all_rows(leds, CRGB::Red);
    // load_image(leds, img_masterBall, &imgLoaded);
    //     // imgLoaded = 0;
    // } else {
    //     switch_off_all(leds);
    // };
}