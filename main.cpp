#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "ReadCSVFile.h"
#include "TriModel.h"
#include "TriPath.h"
#include "PathDependentOptions.h"

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

   cout << "STOCK DATA" << endl;

   DisplayDoubleVector(stockData);

   //Derivative data, Tesla at index 0, Ford at index 1.
   int KVals[2] = {130,160}; 
   int BVals[2] = {160,200};
   int MVals[2] = {2,2};

   //===Pricing Options===

   cout << endl; //Break for formatting

   //Ford

   double FordS0 = stod(stockData[3][1]);
   double FordR = stod(stockData[3][2]);
   double FordSig = stod(stockData[3][3]);

   double TeslaS0 = stod(stockData[2][1]);
   double TeslaR = stod(stockData[2][2]);
   double TeslaSig = stod(stockData[2][3]);
   
   //Call an instance of the TriPath class for the Ford data
   TriPath FModel(FordS0,FordSig,FordR,1,6);
   TriPath TModel(TeslaS0,TeslaSig,TeslaR,1,6);

   //Call an instance of all the various options
   AsianOpt TASOpt(KVals[0]);
   AsianOpt FASOpt(KVals[1]);
   KnockoutOpt FKOOPt(KVals[1],BVals[1]);
   KnockoutOpt TKOOPt(KVals[1],BVals[0]);
   LookbackOpt FLBOpt;
   LookbackOpt TLBOpt;
   BarrierOpt FBAROpt(KVals[1], BVals[1], MVals[1]);
   BarrierOpt TBAROpt(KVals[0], BVals[0], MVals[0]);

   double TasPrice = TASOpt.PriceByExpectation(TModel);
   double FasPrice = FASOpt.PriceByExpectation(FModel);
   
   double TkoPrice = TKOOPt.PriceByExpectation(TModel);
   double FkoPrice = FKOOPt.PriceByExpectation(FModel);
   
   double FlbPrice = FLBOpt.PriceByExpectation(FModel);
   double TlbPrice = TLBOpt.PriceByExpectation(TModel);

   double TbrPrice = TBAROpt.PriceByExpectation(TModel);
   double FbrPrice = FBAROpt.PriceByExpectation(FModel);

   cout << "=== FORD OPTIONS PRICES ===" << endl;

   cout << "Asian Option Price: " << FasPrice << endl;
   cout << "Knockout Option Price: " << FkoPrice << endl;
   cout << "Lookback Option Price: " << FlbPrice << endl;
   cout << "Classic Parisian Option Price: " << TbrPrice << endl;

   cout << endl; //Break for formatting

   cout << "=== TESLA OPTIONS PRICES ===" << endl;

   cout << "Asian Option Price: " << TasPrice << endl;
   cout << "Knockout Option Price: " << TkoPrice << endl;
   cout << "Lookback Option Price: " << TlbPrice << endl;
   cout << "Classic Parisian Option Price: " << FbrPrice << endl;

   
   return 0;
}
