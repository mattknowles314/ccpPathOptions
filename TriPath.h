#ifndef TRIPATH_H
#define TRIPATH_H
#include "TriModel.h"

/*  CLASS:  TRIPATH

    The class TriPath is a subclass of TriModel. The purpose of the class is to encode
    all possible paths in a trinomial tree, their associated prices, and their associated
    probabilities.
*/

class TriPath : public TriModel
{
    private:
        double T;
        int N;
        double S0;
        double sigma;
        double r;
        double dx;
        double dt;
    public:
        //Constructor
        TriPath(double S0_, double sigma_, double r_, double T_, int N_) : N(N_), T(T_), TriModel(S0_,sigma_,r_) {
            Set_dtdx(T_,N_);
        }


        //Helpful functions for retreiving values of T and N
        int GetN(){ return N;}
        int GetT(){ return T;}
        
        //Return a path given an index
        void PathByNumber(int x, int *path);

        //Calculate prices along a given path
        void PricesByPath(int *path, double *prices);

        //Calculate probability path is selected
        double ProbabilityByPath(int *path);
};



#endif // TRIPATH_H
