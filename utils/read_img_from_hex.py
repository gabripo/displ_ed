import argparse
from PIL import Image
import binascii
import math


def hex_to_image(hex_string):
    # Remove '0x' prefix if it exists
    if hex_string.startswith("0x"):
        hex_string = hex_string[2:]

    # Check if the hex string has the correct length for a 24-bit image (6 characters)
    if len(hex_string) != 6:
        print("Hex string should be 6 characters long (24 bits).")
        return None

    try:
        # Convert the hex string to bytes
        image_data = bytes.fromhex(hex_string)

        # Create a PIL Image from the binary data
        image = Image.frombytes("RGB", (1, 1), image_data)
        return image
    except Exception as e:
        print(f"Error: {e}")
        return None


def load_hex_values_from_file(file_path):
    try:
        with open(file_path, "r") as file:
            lines = file.read().splitlines()
        return lines
    except Exception as e:
        print(f"Error reading file: {e}")
        return []


def combine_hex_values_as_image(hex_values, invert_even_lines=False):
    width = int(math.ceil(math.sqrt(len(hex_values))))  # Calculate image width
    height = int(math.ceil(len(hex_values) / width))  # Calculate image height

    image = Image.new("RGB", (width, height))

    for i, hex_string in enumerate(hex_values):
        pixel = hex_to_image(hex_string)
        if pixel:
            x = i % width
            y = i // width

            if invert_even_lines and y % 2 == 1:
                # Invert even lines
                x = width - x - 1

            image.putpixel((x, y), pixel.getpixel((0, 0)))

    return image


def main():
    # Create an argument parser
    parser = argparse.ArgumentParser(
        description="Convert and display hex values as an image"
    )
    parser.add_argument(
        "file_path", help="Path to the file containing hex values separated by commas"
    )
    parser.add_argument("--invert-even", action="store_true", help="Invert even lines")

    # Parse the command-line arguments
    args = parser.parse_args()

    # Load hex values from the specified file
    lines = load_hex_values_from_file(args.file_path)

    # Combine all hex values into a single image, optionally inverting even lines
    hex_values = [
        hex_value.strip()
        for line in lines
        for hex_value in line.split(",")
        if hex_value.strip()
    ]
    image = combine_hex_values_as_image(hex_values, invert_even_lines=args.invert_even)

    # Display the combined image using the default image viewer
    image.show()


if __name__ == "__main__":
    main()
