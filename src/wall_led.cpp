#include <Arduino.h>
#include <FastLED.h>
#include <avr/pgmspace.h>

#include "images.hpp"
#include "images_rle.hpp"
#include "led_functions.cpp"
#include "led_settings.h"
#include "motion_sensor.cpp"
#include "progmem_functions.cpp"
#include "simple_rgb.cpp"

FASTLED_USING_NAMESPACE

CRGB imgToLoad[num_leds];

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

    // load_rgb_image_progmem(imgToLoad, num_leds, img_pokeball);
    uint64_t decompressedSize;
    load_rgbrle_image_progmem(imgToLoad, num_leds, img_pokeball_rle, pgm_read_dword(&img_pokeball_rle_size), &decompressedSize);
    Serial.println((int)decompressedSize);
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