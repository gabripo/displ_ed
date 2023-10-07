#include "image_compression.hpp"

rgb_color convert_crgb_rgbcolor(const CRGB* const crgb_color) {
    rgb_color convertedRgbColor;
    convertedRgbColor.red = (uint32_t)*crgb_color & 0x00FF0000;
    convertedRgbColor.green = (uint32_t)*crgb_color & 0x0000FF00;
    convertedRgbColor.blue = (uint32_t)*crgb_color & 0x000000FF;
    return convertedRgbColor;
}

rgb_color* convert_crgb_rgbimage(const CRGB* const crgb_image, const uint64_t imageSize) {
    rgb_color* convertedRgbImage = (rgb_color*)malloc(imageSize * sizeof(rgb_color));
    for (uint64_t i = 0; i < imageSize; i++) {
        convertedRgbImage[i] = convert_crgb_rgbcolor(&crgb_image[i]);
    }
    return convertedRgbImage;
}

int is_same_rgbcolor(const rgb_color* const color1, const rgb_color* const color2) {
    if ((color1->red == color2->red) && (color1->green == color2->green) && (color1->red == color2->red)) {
        return 1;
    }
    return 0;
}

RLEPixel* compressRLE(rgb_color* imageData, uint8_t width, uint8_t height, int* compressedSize) {
    RLEPixel* compressedData = NULL;
    int compressedIndex = 0;

    rgb_color currentColor;
    uint32_t currentColorCount = 0;
    for (uint8_t y = 0; y < height; y++) {
        for (uint8_t x = 0; x < width; x++) {
            rgb_color imageColor = imageData[y * width + x];

            if (is_same_rgbcolor(&imageColor, &currentColor) && (currentColorCount < 0xFFFFFFFF)) {
                currentColorCount++;
            } else {
                if (currentColorCount > 0) {
                    compressedData = (RLEPixel*)realloc(compressedData, (compressedIndex + 1) * sizeof(RLEPixel));
                    compressedData[compressedIndex].rgb = currentColor;
                    compressedData[compressedIndex].count = currentColorCount;
                    compressedIndex++;
                }
                currentColor = imageColor;
                currentColorCount = 1;
            }
        }
    }

    // Store the last run
    compressedData = (RLEPixel*)realloc(compressedData, (compressedIndex + 1) * sizeof(RLEPixel));
    compressedData[compressedIndex].rgb = currentColor;
    compressedData[compressedIndex].count = currentColorCount;

    *compressedSize = compressedIndex + 1;
    return compressedData;
}

CRGB* decompressRLE(const RLEPixel* const compressedData, uint64_t compressedSize, int* decompressedSize) {
    CRGB* decompressedData = (CRGB*)malloc(compressedSize * sizeof(CRGB));
    int decompressedDataIndex = 0;
    for (uint8_t i = 0; i < compressedSize; i++) {
        for (size_t j = 0; j < compressedData[i].count; j++) {
            decompressedData[decompressedDataIndex].red = compressedData[i].rgb.red;
            decompressedData[decompressedDataIndex].green = compressedData[i].rgb.green;
            decompressedData[decompressedDataIndex].blue = compressedData[i].rgb.blue;
            decompressedDataIndex++;
        }
    }

    *decompressedSize = decompressedDataIndex + 1;
    return decompressedData;
}
