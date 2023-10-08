#include "progmem_functions.hpp"

void load_rgb_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const sRGB* const imgToLoad) {
    for (unsigned long long int i = 0; i < numPixels; i++) {
        imgContainer[i].r = pgm_read_byte(&imgToLoad[i].red);
        imgContainer[i].g = pgm_read_byte(&imgToLoad[i].green);
        imgContainer[i].b = pgm_read_byte(&imgToLoad[i].blue);
    }
}

void load_rgbrle_image_progmem(CRGB* imgContainer, const unsigned long long int numPixels, const RLEPixel* const imgToLoadRLE, uint32_t compressedSize, uint64_t* decompressedSize) {
    // uint64_t decompressedSize;
    // CRGB* decompressedImg = decompressRLE(imgToLoadRLE, (uint64_t)numPixels, &decompressedSize);
    uint64_t decompressedDataIndex = 0;
    for (unsigned long long int i = 0; i < compressedSize; i++) {
        uint8_t count = pgm_read_byte(&imgToLoadRLE[i].count);
        for (uint8_t j = 0; j < count; j++) {
            imgContainer[decompressedDataIndex].r = pgm_read_byte(&imgToLoadRLE[i].rgb.red);
            imgContainer[decompressedDataIndex].g = pgm_read_byte(&imgToLoadRLE[i].rgb.green);
            imgContainer[decompressedDataIndex].b = pgm_read_byte(&imgToLoadRLE[i].rgb.blue);
            decompressedDataIndex++;
        }
    }

    *decompressedSize = decompressedDataIndex;
}
