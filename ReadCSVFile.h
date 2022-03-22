/*
Class for reading a CSV file to obtain necessary data.

Psas a file location to the class. 
*/
#ifndef READCSVFILE_H
#define READCSVFILE_H
 
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
 
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

#endif // READCSVFILE_H