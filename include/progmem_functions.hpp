#include <avr/pgmspace.h>

#include "image_compression.cpp"
#include "pixeltypes.h"
#include "simple_rgb.hpp"

void load_rgb_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const sRGB* const imgToLoad);
void load_rgbrle_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const RLEPixel* const imgToLoadRLE, uint32_t compressedSize, uint64_t* decompressedSize);