#include <Arduino.h>
#include <FastLED.h>

#include "image_compression.cpp"
#include "images.hpp"
#include "led_functions.cpp"
#include "led_settings.h"
#include "motion_sensor.cpp"

FASTLED_USING_NAMESPACE

void setup() {
    Serial.begin(9600);

    FastLED.addLeds<LED_TYPE, ARDUINO_DATA_PIN, COLOR_ORDER>(leds, num_leds);

    FastLED.setBrightness(BRIGHTNESS);
    Serial.println("RGBW test...");
    rgb_test(leds);
    Serial.println("RGBW test completed.");
    delay(1000);
    Serial.println("Setting up motion sensor...");
    setup_motion_sensor();
    Serial.println("Motion sensor set up.");
    // turnon_incrementally(leds);
}

void loop() {
    if (isMotion && digitalRead(interruptPin)) {
        Serial.println("Motion!");
        load_image(leds, img_pokeball, &imgLoaded);
    } else {
        switch_off_all(leds);
        imgLoaded = 0;
    };
}