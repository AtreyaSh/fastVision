# fastVision

In certain administrative processes, it is extremely helpful to parse raw text from PDF files containing static images of text. An example of this is batch parsing raw text from scanned images. In order to go about this process, we could utilize the Tesseract Optical Character Recognition (OCR) algorithm.

To go about this process, we need to accomplish the following:

1. Select Regions of Interest (ROIs) in our image to optimize the OCR algorithm. These regions should be ideally invariant under constant aspect-ratio transformations, such that a user would be able to parse the same text if the PDF image is converted into an image with varying resolutions or DPIs.

2. Optimize the DPI for conversion from PDF to image file, which would be `.png` or `.jpg` in this case. The optimal DPI would produce the most accurate OCR algorithm results.

With the help of this repository, we will attempt to provide a solution for both aforementioned tasks.

## Guide for Ubuntu 16.04

## Dependencies

1. As our code requires c++ compilation, we would need a c++ compiler installed. In this example, we recommend `g++`.

   ```shell
   $ sudo apt-get install g++
   ```
   
2. We require `R` to be installed on your system:

   ```shell
   $ sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E298A3A825C0D65DFD57CBB651716619E084DAB9
   
   $ sudo add-apt-repository 'deb [arch=amd64,i386] https://cran.rstudio.com/bin/linux/ubuntu xenial/'
   
   $ sudo apt-get update && sudo apt-get install r-base
   ```

3. The following installations are necessary to run R-scripts:

   ```shell
   $ sudo apt-get install imagemagick libpoppler-cpp-dev libcurl4-openssl-dev openjdk-8-jdk libmagick++-dev
   ```

4. In order to run the Tesseract OCR algorithm, we need to install the following:

   ```shell
   $ sudo apt-get install tesseract-ocr libtesseract-dev libleptonica-dev
   ```

5. In order to run ROI selection processes, we need to install `OpenCV` onto our system. A comprehensive guide can be found here:

   https://www.learnopencv.com/install-opencv3-on-ubuntu/
   
   Note: This step can be long and tedious

## Run Application

Once the dependencies have been installed, we can run our application. 

1. Clone our repository and navigate to its main directory:

   ```shell
   $ git clone https://github.com/atreyasha/fastVision && cd fastVision
   ```

   The main test PDF file is `/data/test.pdf`. You can simply replace this PDF with your own and rename it as `test.pdf`.

2. Normally, we would need to compile our scripts and run them manually. Here, we provide a compact executable file `run.sh` to handle this process. Simply do as follows:

   ```shell
   $ ./run.sh
   ```

   This will allow you to analyze your image and select relevant ROIs. Selected ROIs with aspect-ratio invariant dimensions will be saved as `/results/results.csv`. 

3. To optimize the DPI for the Tesseract OCR algorithm, run the following:

   ```shell
   $ Rscript src.R
   ```

   The optimized DPI will be saved as `/results/dpi.csv`.

## Docker Implementation

We offer a docker implementation of this application here: https://github.com/atreyasha/dockerOpenCVnR

## Credits

Tesseract OCR: https://github.com/tesseract-ocr/tesseract

@xczhang in StackOverFlow discussion for input on openCV window hiding issue:
https://stackoverflow.com/questions/8417531/opencv-how-to-force-the-image-window-to-appear-on-top-of-other-windows
