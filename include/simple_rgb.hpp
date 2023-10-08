#ifndef SIMPLERGB
#define SIMPLERGB

#include <stdint.h>

typedef struct {
    union {
        struct
        {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
        };
        uint8_t raw[3];
    };
} sRGB;

const uint32_t bitMaskRed = 0x00FF0000;
const uint32_t bitMaskGreen = 0x0000FF00;
const uint32_t bitMaskBlue = 0x000000FF;

uint8_t get_rgb_red(const sRGB* const rgbVal);
uint8_t get_rgb_green(const sRGB* const rgbVal);
uint8_t get_rgb_blue(const sRGB* const rgbVal);

#endif