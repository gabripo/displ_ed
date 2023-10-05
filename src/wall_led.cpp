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
    setup_motion_sensor();
    // turnon_incrementally(leds);
}

void loop() {
    if (isMotion) {
        Serial.println("Motion!");
        load_image(leds, img_pokeball, &imgLoaded);
    } else {
        switch_off_all(leds);
        imgLoaded = 0;
    };
}