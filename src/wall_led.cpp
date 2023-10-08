#include <Arduino.h>
#include <FastLED.h>
#include <avr/pgmspace.h>

#include "image_compression.cpp"
#include "images.hpp"
#include "led_functions.cpp"
#include "led_settings.h"
#include "motion_sensor.cpp"
#include "simple_rgb.cpp"

FASTLED_USING_NAMESPACE

CRGB imgToLoad[num_leds];

void setup() {
    Serial.begin(9600);
    for (size_t i = 0; i < num_leds; i++) {
        imgToLoad[i].r = pgm_read_byte(&img_pokeball[i].red);
        imgToLoad[i].g = pgm_read_byte(&img_pokeball[i].green);
        imgToLoad[i].b = pgm_read_byte(&img_pokeball[i].blue);
    }
    // Serial.println((int)decompressedSize);
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
        load_image(leds, imgToLoad, &imgLoaded);
    } else {
        switch_off_all(leds);
        imgLoaded = 0;
    };
}