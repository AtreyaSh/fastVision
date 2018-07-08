# Tesseract Optical Character Recognition (OCR) algorithm

Here we test some examples of the Tesseract OCR algorithm.

This project aims to increase efficiencies of administrative processes by applying the OCR algorithm to images.

# Guide for implementation in Linux Ubuntu 16.04

1. Ensure you have a C++ compiler installed, in this example we recommend `g++`.

   `$ sudo apt-get install g++`

2. Next, we need to install `tesseract-ocr`, `libtesseract-dev` and `libleptonica-dev`.

   `$ sudo apt-get install tesseract-ocr libtesseract-dev libleptonica-dev`

3. We now have the relevant compiler(s) and packages to compile our code. To compile, we use `g++`.

   `$ g++ fastVisionMain.cpp -o program.exe -llept -ltesseract`

4. This will now create an executable file `program.exe`. Execute it to see the results.

   `$ ./program.exe`

The Tesseract OCR algorithm will parse the image into text.

Note: This project is under development and will be slowly improved to provide user-interactivity in choosing bounding boxes for optimized text-recognition.

Credits to tesseract: https://github.com/tesseract-ocr/tesseract

Authors: Atreya Shankar, Henrik Distel
