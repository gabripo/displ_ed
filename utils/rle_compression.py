import sys


# Define the RLEPixel structure
class RLEPixel:
    def __init__(self, color, count):
        self.color = color  # 24-bit color value
        self.count = count  # Number of consecutive pixels with the same color


# Function to compress color data into RLE format
def compress_rle(color_data):
    compressed_data = []
    current_color = None
    current_count = 0

    for color in color_data:
        if color == current_color and current_count < 0xFFFFFFFF:
            current_count += 1
        else:
            if current_color is not None:
                compressed_data.append(RLEPixel(current_color, current_count))
            current_color = color
            current_count = 1

    # Add the last run
    if current_color is not None:
        compressed_data.append(RLEPixel(current_color, current_count))

    return compressed_data


# Read color data from the text file
def read_color_data(filename):
    color_data = []
    with open(filename, "r") as file:
        for line in file:
            line = line.strip()
            colors = [
                int(color.strip(), 16) for color in line.split(",") if color.strip()
            ]  # Strip each color individually
            color_data.extend(colors)  # Add the cleaned colors from the line
    return color_data


# Write compressed data to a text file with hex values separated by comma
def write_compressed_data(filename, compressed_data):
    rgbValType = "uint8_t"
    countType = "uint32_t"
    with open(filename, "w") as file:
        for pixel in compressed_data:
            hex_color = hex(pixel.color)[2:]
            hex_color_r = hex(int(hex_color, 16) & 0x000000FF)
            hex_color_g = hex(int(hex_color, 16) & 0x0000FF00)
            hex_color_b = hex(int(hex_color, 16) & 0x00FF0000)
            file.write(
                f"{{{{({rgbValType}) {hex_color_r}, ({rgbValType}) {hex_color_g}, ({rgbValType}) {hex_color_b}}}, ({countType}) {pixel.count}}},\n"
            )


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python compress.py input_filename")
        sys.exit(1)

    input_filename = sys.argv[1]  # Input filename provided as a command-line argument
    output_filename = "compressed_data.txt"  # Replace with your output filename

    # Read color data from the input file
    color_data = read_color_data(input_filename)

    # Compress the data
    compressed_data = compress_rle(color_data)

    # Write compressed data to a text file with hex values separated by comma
    write_compressed_data(output_filename, compressed_data)

    print(f"Compression completed. Compressed data saved to {output_filename}")
