import sys
from PIL import Image


def invert_even_rows(image):
    width, height = image.size
    pixels = image.load()

    even_rows = [y for y in range(height) if y % 2 == 0]
    for y in even_rows:
        row_pixels = [pixels[x, y] for x in range(width)]
        for x in range(width):
            pixels[x, y] = row_pixels[width - 1 - x]


def convert_image_to_hex(image_path, invert):
    # Open the image
    image = Image.open(image_path)

    # Convert the image to RGB mode
    image = image.convert("RGB")

    # Invert even rows if specified
    if invert:
        invert_even_rows(image)

    # Get the pixel data
    pixels = list(image.getdata())

    # Convert each RGB pixel to a single 24-bit hexadecimal value
    hex_values = []
    for i, pixel in enumerate(pixels, start=1):
        r, g, b = pixel
        rgb_hex = (r << 16) | (g << 8) | b
        hex_values.append("0x" + format(rgb_hex, "06x") + ",")

        if i % 16 == 0:  # Add a newline after every 16 values
            hex_values.append("\n")

    # Join the hexadecimal values with spaces
    hex_string = " ".join(hex_values)

    # Write the hex string to the output file
    output_file_path = "output.txt"
    with open(output_file_path, "w") as output_file:
        output_file.write(hex_string)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python script.py <image_path> [--invert]")
        sys.exit(1)

    image_path = sys.argv[1]
    invert = "--invert" in sys.argv
    convert_image_to_hex(image_path, invert)
