# fastVision

This project aims to allow a user to efficiently and effectively select ROIs from an image, such that the selected ROIs are invariant under constant aspect-ratio transformations. This can largely assist in stabilizing workflows such as in optimizing optical character recognition for images by varying DPIs.

The main test image is located in the `/data` directory and is named `test.png`. You can replace this image with another `.png` image  and rename it to `test.png` if you want a quick test without having to modify code. So far, our code has only been tested with `.png` files, but feel free to experiment other formats.

## Implement `bBox.cpp` in Ubuntu 16.04

1. Ensure you have a C++ compiler installed, in this example we recommend `g++`.

   `$ sudo apt-get install g++`

2. Install `opencv` onto your system. A comprehensive guide can be found here: https://www.learnopencv.com/install-opencv3-on-ubuntu/

3. Normally, you would need to compile the source code and run the executable file manually. However, we have packaged this process into the executable file `cmp.sh`.

   `$ ./cmp.sh`

The script will allow you to select ROIs and will save their dimensions into the `results.csv` file in the `/results` directory. This `.csv` file can then be later parsed for further image-processing.

## Developments

1. Debug hiding window issue when selecting ROIs and clear all memory at end

2. Pack application as a docker image for hands-off cross-platform testing

3. Run some examples using R to show aspect-ratio invariance

# Credits

Tesseract OCR: https://github.com/tesseract-ocr/tesseract
