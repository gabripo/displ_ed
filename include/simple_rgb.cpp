#include "simple_rgb.hpp"

uint8_t get_rgb_red(const sRGB* const rgbVal) {
    uint32_t rgbChannel32b = (uint32_t)rgbVal->raw & bitMaskRed;
    uint8_t rgbChannel8b = (uint8_t)(rgbChannel32b >> 16);
    return rgbChannel8b;
}

uint8_t get_rgb_green(const sRGB* const rgbVal) {
    uint32_t rgbChannel32b = (uint32_t)rgbVal->raw & bitMaskGreen;
    uint8_t rgbChannel8b = (uint8_t)(rgbChannel32b >> 8);
    return rgbChannel8b;
}

uint8_t get_rgb_blue(const sRGB* const rgbVal) {
    uint32_t rgbChannel32b = (uint32_t)rgbVal->raw & bitMaskBlue;
    uint8_t rgbChannel8b = (uint8_t)rgbChannel32b;
    return rgbChannel8b;
}