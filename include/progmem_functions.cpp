#include "progmem_functions.hpp"

void load_rgb_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const sRGB* const imgToLoad) {
    for (unsigned long long int i = 0; i < numPixels; i++) {
        imgContainer[i].r = pgm_read_byte(&imgToLoad[i].red);
        imgContainer[i].g = pgm_read_byte(&imgToLoad[i].green);
        imgContainer[i].b = pgm_read_byte(&imgToLoad[i].blue);
    }
}