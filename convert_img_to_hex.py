import sys
from PIL import Image

def convert_image_to_hex(image_path):
    # Open the image
    image = Image.open(image_path)

    # Convert the image to RGB mode
    image = image.convert('RGB')

    # Get the pixel data
    pixels = list(image.getdata())

    # Convert each RGB pixel to a single 24-bit hexadecimal value
    hex_values = []
    for i, pixel in enumerate(pixels, start=1):
        r, g, b = pixel
        rgb_hex = (r << 16) | (g << 8) | b
        hex_values.append(format(rgb_hex, '06x'))

        if i % 16 == 0:  # Add a newline after every 16 values
            hex_values.append('\n')

    # Join the hexadecimal values with spaces
    hex_string = ' '.join(hex_values)

    # Write the hex string to the output file
    output_file_path = 'output.txt'
    with open(output_file_path, 'w') as output_file:
        output_file.write(hex_string)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python script.py <image_path>")
        sys.exit(1)

    image_path = sys.argv[1]
    convert_image_to_hex(image_path)
