#!/bin/bash
g++ -c  classes/js/object.cpp -o build/object.o
g++ -c main.cpp -o build/main.o
cd build
g++ -Xlinker object.o main.o  -o ../ji
