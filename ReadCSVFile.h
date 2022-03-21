/*
Class for reading a CSV file to obtain necessary data.

Psas a file location to the class. 
*/
#ifndef ReadCSVFile_H
#define ReadCSVFile_H
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;

class ReadCSV
{
    private:
        vector<vector<string>> data;
        string fileLoc;
    public:
        ReadCSV(string fileLoc_) : fileLoc(fileLoc_){};
        vector<vector<string>> CSV2VEC();
};

#endif