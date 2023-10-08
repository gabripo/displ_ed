#include <avr/pgmspace.h>

#include "pixeltypes.h"
#include "simple_rgb.hpp"

void load_rgb_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const sRGB* const imgToLoad);