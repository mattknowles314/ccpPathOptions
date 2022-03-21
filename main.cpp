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
   cout << "running" << endl;
   ReadCSV obj("Data/SampleData.csv");
   vector<vector<string>> optsData;
   obj.CSV2VEC();

   DisplayDoubleVector(optsData);

}
