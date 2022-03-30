#include "PathDependentOptions.h"

#include <algorithm>
#include <iostream>
#include <cmath>

double PathDependentOptions::PriceByExpectation(TriPath model)
{
    //Get N, T and r from the class (Change variable case to avoid memalloc issues)
    int n = model.GetN();
    int t = model.GetT();
    double R = model.Get_r();
    
    //Define these constants here for ease of use
    int power = pow(3,n); //Number of paths in the tree
    double coeff = (1/(1+R)); //Risk-free return
    
    //Initialise empty arrays as all zeros
    int Path[n] = {0};
    double Prices[n] = {0};
    double Payoffs[power] = {0};
    double Probs[power] = {0};
    
    //Loop through all the possible paths
    for (int x = 0; x < power; x++)
    {
        model.PathByNumber(x,Path); //Generate path
        Probs[x] = model.ProbabilityByPath(Path); //Calculate probability of selecting path
        model.PricesByPath(Path,Prices); //Generate prices along path
        Payoffs[x] = Payoff(Prices,n); //Calculate payoff for the path
    }

    //Calculate expected payoff by looping over all paths
    double ExpPayoff = 0;
    for(int i=0; i<power;i++){
        ExpPayoff+=(Probs[i]*Payoffs[i]);
    }

    //Discount expected payoff w.r.t risk-free return to give price
    double Price = pow(coeff,t)*ExpPayoff;
    return Price;
}

//Payoff function for the knockout option
double KnockoutOpt::Payoff(double *prices, int N)
{
    //Empty array for storing prices with barrier taken out
    double discPrices[N] = {0};
    for (int i = 0; i < N; i++)
    {
        discPrices[i] = prices[i]-B;
    }
    //Payoff is 0 if stock price exceeded barrier B, else return K
    double Poff = *std::max_element(discPrices,discPrices+N) > 0 ? 0 : K;
    return Poff;
}

double LookbackOpt::Payoff(double *prices, int N)
{
    //Lookback payoff is given as max(S(T)-Smin(t),0)
    double Poff = std::max(prices[N-1]-*std::min_element(prices,prices+N),0.0);
    return Poff;
}

double AsianOpt::Payoff(double *prices, int N)
{
    //Sum all vaues along the path
    double pathVal = 0;
    double avg;
    for(int i=0; i<N; i++){
        pathVal+=prices[i];
    }
    avg = pathVal/N; //Divide that sum by N for arithmetic mean
    double disk = avg-K;
    //Note we have used the fixed price formula C(T) = max(A(0,T)-K,0) 
    double Poff = std::max(disk, 0.0);
    return Poff;
}

//TODO: Control reaches end of non void function
double BarrierOpt::Payoff(double *prices, int N)
{
    for (int i = 0; i < N; i++)
    {
        //Check price exceeds barrier
        if (prices[i]>=B)
        {
            //Start the clock
            bool clock = true; 
            int count = 1;
            while (clock)
            {
                //If price stays above barrier, incrament the count
                if(prices[i+count]>=B){
                    count+=1;
                //If period above barrier exceeds M time incraments, option is worthless
                }else if (count >= M)
                {
                    return 0;
                } else{ //clock gets reset if price drops below B
                    clock = false;
                }
            }
            continue;   
        } else{
            return K; //Valued at stike if price never exceeds barrier
        }  
    }
    return 0;
}