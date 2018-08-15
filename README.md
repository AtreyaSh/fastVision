# fastVision c++ scripts

This project aims to increase efficiencies of administrative processes by applying the OCR algorithm to images.

The main test image is located in the `/data` directory and is named `test.png`. You can replace this image with another `.png` image  and rename it to `test.png` if you want a quick test without having to modify code.

## 1. Guide to implement `bBox.cpp` in Ubuntu 16.04

`bBox.cpp` allows a user to interactively select Regions of Interest (ROIs) or bounding boxes, which can then later be used within `fastVisionMain.cpp`.

1. Ensure you have a C++ compiler installed, in this example we recommend `g++`.

   `$ sudo apt-get install g++`

2. Install `opencv` onto your system. A comprehensive guide can be found here: https://www.learnopencv.com/install-opencv3-on-ubuntu/

3. Compile `bBox.cpp` script using `g++`

   ``$ g++ -std=c++11 bBox.cpp `pkg-config --libs --cflags opencv` -o bBox.exe``

4. Run the compiled file.

   `$ ./bBox.exe`

The script will allow you to select ROIs and will save their dimensions into a `.csv` file in the `/results` directory.

## 2. Guide to implement `fastVisionMain.cpp` in Ubuntu 16.04

`fastVisionMain.cpp` helps one to parse ROIs in images for text. Below are instructions to implement the script.

1. Ensure you have a C++ compiler installed, in this example we recommend `g++`.

   `$ sudo apt-get install g++`

2. Next, we need to install `tesseract-ocr`, `libtesseract-dev` and `libleptonica-dev`.

   `$ sudo apt-get install tesseract-ocr libtesseract-dev libleptonica-dev`

3. Open up `fastVisionMain.cpp` using your favourite text editor. Set your rectangle dimensions where you would like to parse the image into text.

4. We now have the relevant compiler(s) and packages to compile our code. To compile, we use `g++`.

   `$ g++ fastVisionMain.cpp -o program.exe -llept -ltesseract`

5. This will now create an executable file `program.exe`. Execute it to see the results.

   `$ ./program.exe`

The Tesseract OCR algorithm will parse the image into text and output it into the console.

## Developments

1. Provide user-interactivity in choosing bounding boxes for optimized text-recognition

2. Optimize bounding boxes invariance under constant aspect-ratio image deformations

3. Bind `bBox.cpp` and `fastVisionMain.cpp` into an interactive application

4. Pack application as a docker image for hands-off cross-platform testing

5. Bind all functions within a R-framework to process larger data-flows

## Credits

Tesseract OCR algorithm: https://github.com/tesseract-ocr/tesseract
