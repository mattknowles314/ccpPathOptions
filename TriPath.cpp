#include "TriPath.h"
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
We use the modulo operator to generate paths for a given input x.
Note the convention used:
 2 = path goes up
 1 = path doesn't change
 0 = path goes down
*/
void TriPath::PathByNumber(int x, int *path){
    //First check x is a legal value
    if(x < 0 || x > pow(3,N)-1){
        cout << "Error - x out of range" << endl;
    } else{
        for(int i=0;x>0;i++){
            path[i] = x%3;
            x/=3;
        }
    }
}


//Loops through the path to calculate next price based on the path
void TriPath::PricesByPath(int *path, double *prices){
    prices[0] = S0;
    for (int i = 1; i < N; i++)
    {
        if(path[i-1]==0){
            prices[i] = prices[i-1]*exp((-1*dx));
        } else if (path[i-1]==1){
            prices[i] = prices[i-1];
        } else if (path[i-1]==2){
            prices[i] = prices[i-1]*exp(dx);
        }
    } 
}

//Calculate probability along a path by multiplying powers of each jump together.
double TriPath::ProbabilityByPath(int *path){
    double qu = RiskNeutProb_up();
    double qd = RiskNeutProb_down();
    double qm = 1-qu-qd; 
    double ups=0; 
    double downs=0;
    double mids=0;
    for (int i = 0; i < N; i++)
    {
        if(path[i]==0){
            downs+=1;
        } else if (path[i]==1)
        {
            mids+=1;
        } else if (path[i]==2)
        {
            ups+=1;
        }
    }
    double prob = pow(qu,ups)*pow(qd,downs)*pow(qm,mids);
    //cout << prob << endl;
    return prob;
}