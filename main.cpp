#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "ReadCSVFile.h"
#include "TriModel.h"
#include "TriPath.h"

using namespace std;

//TEMPLATE: This Template Function allows us to display any given 2D vector V.
template<typename vecType>
void DisplayDoubleVector(vecType V){
   for(int i=0; i<V.size();i++){
      for(int j=0;j<V[i].size()-1;j++){
         cout << V[i][j]<<", ";
      }
      //Having this last line prevents printing a comma with the last entry before starting a new line
      cout << V[i][V[i].size()-1] <<endl;
   }
}

int main(){
   cout << "=== PATH DEPENDENT OPTIONS PRICING ===" << endl;
   
   //Create an instance of the ReadCSV class pointing to the CSV file containing stock data
   ReadCSV csv("Data/StockDataMar2022.csv");
   
   //Empty double vector for storing stock data
   vector<vector<string>> stockData;

   //Populate the double vector with the data from the CSV file
   stockData = csv.CSV2VEC();

   //Display stock data
   DisplayDoubleVector(stockData);

}
