#!/bin/bash
#Run this in terminal
g++ -c ReadCSVFile.cpp
g++ -c TriModel.cpp
g++ -c TriPath.cpp
g++ -c PathDependentOptions.cpp
g++ -c main.cpp 
g++ ReadCSVFile.o main.o PathDependentOptions.o TriModel.o TriPath.o -o main

exit 0