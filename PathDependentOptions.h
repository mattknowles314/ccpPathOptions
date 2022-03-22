#ifndef PATHDEPENDENTOPTIONS_H
#define PATHDEPENDENTOPTIONS_H

#include <cmath>

#include "TriPath.h"

/*  CLASS:  PATHDEPENDENTOPTIONS

    The class PathDependentOptions is a pure virtual class which prices path-dependent
    options. Note that the abstract function Payoff has been redefined from the
    BinModel class to take an array of prices by reference.
*/


class PathDependentOptions
{
   public:
        virtual double Payoff(double *prices, int N){return 0.0;}
        double PriceByExpectation (TriPath Model);
};

// Write your subclasses below this line.


//Asian Option Subclass
class AsianOpt : public PathDependentOptions
{

};

//Loockback Option Subclass
class LookbackOpt : public PathDependentOptions
{

};

//Knockout Option Subclass
class KnockoutOpt : public PathDependentOptions
{

};

//Barrier Option Subclass
class BarrierOpt : public PathDependentOptions
{

};

#endif // PATHDEPENDENTOPTIONS_H
