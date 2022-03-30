#include "PathDependentOptions.h"

#include <algorithm>
#include <iostream>
#include <cmath>

double PathDependentOptions::PriceByExpectation(TriPath model)
{
    int n = model.GetN();
    int t = model.GetT();
    double R = model.Get_r();
    
    const int power = pow(3,n);
    double coeff = (1/(1+R));
    
    int Path[n] = {0};
    double Prices[n] = {0};
    double Payoffs[power] = {0};
    double Probs[power] = {0};
    
    for (int x = 0; x < power; x++)
    {
        model.PathByNumber(x,Path);
        Probs[x] = model.ProbabilityByPath(Path);
        model.PricesByPath(Path,Prices);
        Payoffs[x] = Payoff(Prices,n);      
    }

    double ExpPayoff = 0;
    for(int i=0; i<power;i++){
        ExpPayoff+=(Probs[i]*Payoffs[i]);
    }

    double Price = pow(coeff,t)*ExpPayoff;
    return Price;
}

double KnockoutOpt::Payoff(double *prices, int N)
{
    double discPrices[N] = {0};
    for (int i = 0; i < N; i++)
    {
        discPrices[i] = prices[i]-B;
    }
    
    double Poff = *std::max_element(discPrices,discPrices+N) > 0 ? 0 : K;
    return Poff;
}

double LookbackOpt::Payoff(double *prices, int N)
{
    double Poff = (prices[N-1]-*std::max_element(prices,prices+N));
    return Poff;
}

double AsianOpt::Payoff(double *prices, int N)
{
    double pathVal = 0;
    double avg;
    for(int i=0; i<N; i++){
        pathVal+=prices[i];
    }
    avg = pathVal/N; //Geometrix mean
    double disk = avg-K;
    /*
    Note we have used the fixed price formula C(T) = max(A(0,T)-K,0) 
    */
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