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

//Asian Option Subclass
class AsianOpt : public PathDependentOptions
{
    private:
        double K;
    public:
        AsianOpt(double K_) : K(K_) {};
        double Payoff(double *prices, int N);
};

//Loockback Option Subclass
class LookbackOpt : public PathDependentOptions
{
    public:
        LookbackOpt(){};
        double Payoff(double *prices, int N);

};

//Knockout Option Subclass
class KnockoutOpt : public PathDependentOptions
{
    private:
        double K; //Strike
        double B; //Barrier
    public:
        KnockoutOpt(double K_, double B_) : K(K_), B(B_) {};
        double Payoff(double *prices, int N);
};

//Barrier Option Subclass
class BarrierOpt : public PathDependentOptions
{
    private:
        double K;
        double B;
        int M;
    public:
        BarrierOpt(double K_, double B_, int M_) : K(K_), B(B_), M(M_) {};
        double Payoff(double *prices, int N);
};

#endif // PATHDEPENDENTOPTIONS_H
