#!/bin/bash

d=$(find *.cpp)
g++ -std=c++11 $(echo $d) `pkg-config --libs --cflags opencv` -o run.sh
./exe.sh
sleep 0.1
rm exe.sh
Rscript src.R
