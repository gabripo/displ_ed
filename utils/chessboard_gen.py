import argparse


# Define a function to create the chessboard
def create_chessboard(board_size, square_size, invert):
    # Define the colors for black and white squares as 24-bit hex values
    rgbColorType = "(uint8_t)"
    black_color = (
        "{" + rgbColorType + "0x00, " + rgbColorType + "0x00, " + rgbColorType + "0x00}"
    )
    white_color = (
        "{" + rgbColorType + "0xFF, " + rgbColorType + "0xFF, " + rgbColorType + "0xFF}"
    )

    # Create a list to store the chessboard values
    chessboard_values = []

    # Iterate through the rows and columns to generate hex values
    for row in range(board_size):
        row_values = []
        for col in range(board_size):
            color = black_color if (row + col) % 2 == 0 else white_color
            row_values.append(color)
        if invert and row % 2 == 1:
            row_values = row_values[::-1]  # Reverse even rows
        chessboard_values.append(row_values)

    return chessboard_values


# Define a function to save chessboard values to a file
def save_to_file(chessboard_values, filename):
    with open(filename, "w") as file:
        for row_values in chessboard_values:
            row_str = ", ".join(row_values) + ","
            file.write(row_str + "\n")


if __name__ == "__main__":
    # Parse command-line arguments
    parser = argparse.ArgumentParser(description="Generate and save chessboard values.")
    parser.add_argument("--invert", action="store_true", help="Reverse even rows")
    args = parser.parse_args()

    # Constants
    board_size = 16  # Size of the chessboard (16x16)
    square_size = 16  # Size of each square in pixels

    # Generate the chessboard values
    chessboard_values = create_chessboard(board_size, square_size, args.invert)

    # Save the chessboard values to a file
    save_to_file(chessboard_values, "chessboard_values.txt")

    print("Chessboard values saved to 'chessboard_values.txt'")
