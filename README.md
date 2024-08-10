 Edge Detection

## Overview
This project involves creating a C program that performs edge detection on grayscale images. The program reads an image, applies a Gaussian blur, calculates the discrete derivatives, and outputs an edge-detected version of the image.

## Features
- **Image Blurring:** The image is blurred using convolution with a Gaussian kernel.
- **Edge Detection:** Detects edges using the Sobel operator, calculating gradients, and applying a threshold to highlight significant edges.
- **Output:** The final edge-detected image is saved in black and white.

## Algorithm
1. **Read the Image**: The program reads a grayscale image in PGM format.
2. **Apply Gaussian Blur**: The image is blurred to reduce noise and detail.
3. **Compute Derivatives**: Derivatives in the x and y directions are computed using Sobel kernels.
4. **Calculate Gradient Magnitude**: The magnitude of the gradient is calculated at each pixel.
5. **Thresholding**: Pixels with gradient magnitudes above a certain threshold are marked as edges.
6. **Output Image**: The processed image is saved as a binary black and white image.

## Usage
1. Compile the project using the provided `Makefile`.
   ```bash
   make
   ```
2. Run the program with the following command:
   ```bash
   ./bin/edgedetection -T <threshold> <image file>
   ```
   Replace `<threshold>` with the desired threshold value and `<image file>` with the path to your input image.

## Files
- **main.c**: Contains the main function that coordinates the edge detection process.
- **image.c**: Handles image reading, writing, and manipulation functions.
- **convolution.c**: Implements the convolution operations used for blurring and derivative calculation.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your enhancements.

## License
This project is licensed under University des Saarlandes

