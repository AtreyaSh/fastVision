#!/bin/bash

Rscript -e 'library(pdftools); pdf_convert("./data/test.pdf", filenames = "./data/test.png", dpi = 72)' \
&& d=$(find *.cpp) \
&& g++ -std=c++11 $(echo $d) `pkg-config --libs --cflags opencv` -o exe.sh \
&& ./exe.sh && sleep 0.1 && rm exe.sh
