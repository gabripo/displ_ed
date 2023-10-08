#include "image_compression.hpp"

const RLEPixel img_pokeball_rle[] = {
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)2},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)3},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)6},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)3},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)3},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)3},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)5},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)3},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xc000, (uint8_t)0xf80000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)3},
    {{(uint8_t)0xf8, (uint8_t)0x4000, (uint8_t)0xc80000}, (uint32_t)2},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xc000, (uint8_t)0xf80000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)2},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)2},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)2},
    {{(uint8_t)0xf8, (uint8_t)0xc000, (uint8_t)0xf80000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0xf8, (uint8_t)0x4000, (uint8_t)0xc80000}, (uint32_t)2},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)3},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)3},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)5},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)5},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)4},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)4},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)3},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)2},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)3},
    {{(uint8_t)0xc0, (uint8_t)0x2000, (uint8_t)0xe00000}, (uint32_t)2},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)3},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0x90, (uint8_t)0x0, (uint8_t)0xb00000}, (uint32_t)3},
    {{(uint8_t)0xc8, (uint8_t)0x3000, (uint8_t)0x700000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)3},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0xc8, (uint8_t)0x3000, (uint8_t)0x700000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)10},
    {{(uint8_t)0xc8, (uint8_t)0x3000, (uint8_t)0x700000}, (uint32_t)4},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0xc8, (uint8_t)0x3000, (uint8_t)0x700000}, (uint32_t)5},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)3},
    {{(uint8_t)0xf0, (uint8_t)0x3800, (uint8_t)0xb00000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)5},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xf800, (uint8_t)0xf80000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)1},
    {{(uint8_t)0xc8, (uint8_t)0x3000, (uint8_t)0x700000}, (uint32_t)3},
    {{(uint8_t)0xc0, (uint8_t)0x3000, (uint8_t)0x680000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)4},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0x80, (uint8_t)0x7800, (uint8_t)0x780000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)7},
    {{(uint8_t)0xf8, (uint8_t)0xf800, (uint8_t)0xf80000}, (uint32_t)3},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)2},
    {{(uint8_t)0x80, (uint8_t)0x7800, (uint8_t)0x780000}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)2},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xf800, (uint8_t)0xf80000}, (uint32_t)1},
    {{(uint8_t)0x80, (uint8_t)0x7800, (uint8_t)0x780000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0xf8, (uint8_t)0xf800, (uint8_t)0xf80000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0x50, (uint8_t)0x5000, (uint8_t)0x480000}, (uint32_t)5},
    {{(uint8_t)0x80, (uint8_t)0x7800, (uint8_t)0x780000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)6},
    {{(uint8_t)0x80, (uint8_t)0x7800, (uint8_t)0x780000}, (uint32_t)3},
    {{(uint8_t)0xf8, (uint8_t)0xf800, (uint8_t)0xf80000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)1},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)3},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)1},
    {{(uint8_t)0xf0, (uint8_t)0xc800, (uint8_t)0xd80000}, (uint32_t)7},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)2},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)1},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)5},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0xa000, (uint8_t)0xa00000}, (uint32_t)6},
    {{(uint8_t)0x30, (uint8_t)0x3000, (uint8_t)0x300000}, (uint32_t)2},
    {{(uint8_t)0xc0, (uint8_t)0x7800, (uint8_t)0x0}, (uint32_t)3}};