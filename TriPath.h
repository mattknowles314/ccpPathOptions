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
    public:
        //Constructor
        TriPath(double S0_, double sigma_, double r_, double T_, int N_) : TriModel(S0,sigma,r) {}

        //Return a path given an index
        void PathByNumber(int x, int *path);

        //Calculate prices along a given path
        void PricesByPath(int *path, double *prices);

        //Calculate probability path is selected
        double ProbabilityByPath(int *path);

        //For a level n of the tree, this returns the node of a path
        int getNode(int x, int n);

        //Fo
        int getPos(int x, int node);

        void AllPaths();
};



#endif // TRIPATH_H
