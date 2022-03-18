#ifndef TRIPATH_H
#define TRIPATH_H
#include "TriModel.h"

/*  CLASS:  TRIPATH

    The class TriPath is a subclass of TriModel. The purpose of the class is to encode
    all possible paths in a trinomial tree, their associated prices, and their associated
    probabilities.

    You should implement the methods for the path, prices and trees yourself, including
    any functions you deem necessary.
*/

class TriPath : public TriModel
{
    private:
        double T;
        int N;
    public:
        /*
        TRIPATH CONSTRUTOR: Only partially implemented.
            You should finish this off!
        */

        TriPath(double S0_, double sigma_, double r_, double T_, int N_) {};


};



#endif // TRIPATH_H
