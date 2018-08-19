# fastVision

In certain administrative processes, it is extremely helpful to parse raw text from PDF files containing static images of text. An example of this is batch parsing raw text from scanned images. In order to go about this process, we could utilize the Tesseract Optical Character Recognition (OCR) algorithm.

To go about this process, we need to accomplish the following:

1. Select Regions of Interest (ROIs) in our image to optimize the OCR algorithm. These regions should be ideally invariant under constant aspect-ratio transformations, such that a user would be able to parse the same text if the PDF image is converted into an image with varying resolutions or DPIs.

2. Optimize the DPI for conversion from PDF to image file, which would be `.png` or `.jpg` in this case. The optimal DPI would produce the most accurate OCR algorithm results.

With the help of this repository, we will attempt to provide a solution for both aforementioned tasks.

The main test PDF file is `/dataC/test.pdf`. The corresponding image file used for ROI selection is `/dataC/test.png`.  You can replace these files with your own. Just ensure the names are the same, especially if you want a quick test without having to modify code. So far, our code has only been tested with `.png` image files, but feel free to experiment other formats.

## Guide for Ubuntu 16.04

## Dependencies

1. As our code requires c++ compilation, we would need a c++ compiler installed. In this example, we recommend `g++`.

   `$ sudo apt-get install g++`
   
2. We require `R` to be installed on your system:

   `$ sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E298A3A825C0D65DFD57CBB651716619E084DAB9`
   
   `$ sudo add-apt-repository 'deb [arch=amd64,i386] https://cran.rstudio.com/bin/linux/ubuntu xenial/'`
   
   `$ sudo apt-get update && sudo apt-get install r-base`

3. The following installations are necessary to run R-scripts:

   `$ sudo apt-get install imagemagick libpoppler-cpp-dev libcurl4-openssl-dev openjdk-8-jdk libmagick++-dev`

4. In order to run the Tesseract OCR algorithm, we need to install the following:

   `$ sudo apt-get install tesseract-ocr libtesseract-dev libleptonica-dev`

5. In order to run ROI selection processes, we need to install `OpenCV` onto our system. A comprehensive guide can be found here:

   https://www.learnopencv.com/install-opencv3-on-ubuntu/
   
   Note: This step can be long and tedious

## Run Application on Host Machine

Once the dependencies have been installed, we can run our application. 

1. Clone our repository and navigate to its main directory:

   `$ git clone https://github.com/AtreyaSh/fastVision`
   
   `$ cd fastVision`

2. Normally, we would need to compile our scripts and run them manually. Here, we provide a compact executable file `run.sh` to handle this process. Simply do as follows:

   `$ ./run.sh`

   This will allow you to analyze your image and select relevant ROIs. Selected ROIs with aspect-ratio invariant dimensions will be saved as `/results/results.csv`. 

3. To optimize the DPI for the Tesseract OCR algorithm, run the following:

   `$ Rscript src.R`

   While running this script, there could be additional dependencies required to install R packages. This would be shown directly in the console and clear instructions would be given on how to install the necessary corresponding aptitude packages.

   The optimized DPI will be saved as `/results/dpi.csv`.

## Docker Implementation (Experimental)

Docker is a useful means of testing containerized applications. Here, we provide this possibility of testing this application in a docker container.

1. To do this, firsty ensure `docker` is installed on your system. Clear instructions are given here: https://docs.docker.com/install/linux/docker-ce/ubuntu/

2. We need to install certain `X Server` dependencies on the host system:

   `$ sudo apt-get install xserver-xorg-core xserver-xorg xorg openbox`

3. Next, within this git repository, navigate to the `/docker` directory and build our docker image from source.

   `$ cd docker && docker build -t atreyash/fastvision .`

   Note: This will be a long process with ~9 GB of data to be installed.

4. **Please note, this step is still experimental.** After building the image, we would then need to run our docker image in a container. Since, we require GUI services within the container, we would need to tweak our container as below:

   `$ xhost +local:root`

   `$ docker run -ti --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw atreyash/fastvision`

6. **Note that this is not a secure means of running the container with multiple users.** This should be fine for single-users. Please check before changing `xhost` permissions. After running the container, remember to return `xhost` permissions back to its secure state.

   `$ xhost -local:root`

## Developments

1. Secure X11 service for Docker implementation

2. Work on input and output ports for Docker container

## Credits

Tesseract OCR: https://github.com/tesseract-ocr/tesseract

ROS.org Docker Wiki: http://wiki.ros.org/docker/Tutorials/GUI

@xczhang in StackOverFlow discussion for input on openCV window hiding issue:
https://stackoverflow.com/questions/8417531/opencv-how-to-force-the-image-window-to-appear-on-top-of-other-windows

@schicking for openCV Dockerfile template: https://github.com/schickling/dockerfiles

@pkdogcom for Dockerfile template: https://github.com/pkdogcom/opencv-docker
