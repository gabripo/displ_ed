#include "image_compression.hpp"

const RLEPixel img_pokeball_rle[] PROGMEM = {
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)38},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)4},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)10},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)7},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)8},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)6},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)8},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)5},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)10},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xf8, (uint8_t)0xf8}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)1},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0x80, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)1},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)3},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)2},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)3},
    {{(uint8_t)0xf8, (uint8_t)0xf8, (uint8_t)0xf8}, (uint8_t)1},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)5},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xf8, (uint8_t)0xf8}, (uint8_t)3},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)3},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)6},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)4},
    {{(uint8_t)0xf8, (uint8_t)0xf8, (uint8_t)0xf8}, (uint8_t)3},
    {{(uint8_t)0x90, (uint8_t)0x90, (uint8_t)0x90}, (uint8_t)1},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)1},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)7},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0xff, (uint8_t)0xff, (uint8_t)0xff}, (uint8_t)4},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)2},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)10},
    {{(uint8_t)0x0, (uint8_t)0x0, (uint8_t)0x0}, (uint8_t)4},
    {{(uint8_t)0xff, (uint8_t)0x0, (uint8_t)0xff}, (uint8_t)38},
};

const uint32_t img_pokeball_rle_size PROGMEM = (uint32_t)60;