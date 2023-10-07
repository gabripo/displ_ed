#ifndef IMG_COMPRESSION
#define IMG_COMPRESSIOn

#include <stdint.h>
#include <stdlib.h>

#include "pixeltypes.h"

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_color;

typedef struct
{
    rgb_color rgb;
    uint64_t count;
} RLEPixel;

rgb_color convert_crgb_rgbcolor(const CRGB* const crgb_color);
rgb_color* convert_crgb_rgbimage(const CRGB* const crgb_image, const uint64_t imageSize);
int is_same_rgbcolor(const rgb_color* const color1, const rgb_color* const color2);
RLEPixel* compressRLE(rgb_color* imageData, uint8_t width, uint8_t height, int* compressedSize);

#endif