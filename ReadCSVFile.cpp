#include "ReadCSVFile.h"

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<vector<string>> ReadCSV::CSV2VEC()
{
    vector<vector<string>> data;
    string line, datapoint;
    vector<string> row;
    fstream file(fileLoc, ios::in);
    if(file.is_open()){
        while (getline(file, line))
        {
            //Empty the row of the vector for new line
            row.clear();
            
            //Create empty stringstream object to store the entire line of the CSV as a string
            stringstream str(line);

            //Loop through each datapoint in the CSV
            while (getline(str,datapoint,','))
            {
                //Add datapoint to the row 
                row.push_back(datapoint); 
            }
            //Add the entire row to the vector of vectors
            data.push_back(row);
        }
    } else{
        cout << "ERROR - No Such File" << endl;
    }
    return data;
}