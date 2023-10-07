#include "image_compression.hpp"
#include "images.hpp"
#include "pixeltypes.h"

int main() {
    uint8_t width = 16;
    uint8_t height = 16;
    rgb_color* imageData = convert_crgb_rgbimage(img_pokeball, width * height);

    int compressedSize;
    RLEPixel* compressedData = compressRLE(imageData, width, height, &compressedSize);

    int decompressedSize;
    CRGB* decompressedData = decompressRLE(compressedData, compressedSize, &decompressedSize);

    free(compressedData);
    free(decompressedData);

    return 0;
}