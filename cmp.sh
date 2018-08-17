#!/bin/bash

d=$(find *.cpp)
g++ -std=c++11 $(echo $d) `pkg-config --libs --cflags opencv` -o run.sh
./run.sh
sleep 0.1
rm run.sh
