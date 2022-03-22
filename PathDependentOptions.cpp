#include "PathDependentOptions.h"

#include <algorithm>
#include <iostream>
#include <cmath>

double PathDependentOptions::PriceByExpectation(TriPath model)
{
    return 0;
}

double KnockoutOpt::Payoff(double *prices, int N)
{
    return ((*std::max_element(prices,prices+N))-B) > 0 ? 0 : K;
}

double LookbackOpt::Payoff(double *prices, int N)
{
    return (prices[N-1]-*std::min_element(prices,prices+N));
}

double AsianOpt::Payoff(double *prices, int N)
{
    double pathVal = 0;
    double avg;
    for(int i=0; i<N; i++){
        pathVal+=prices[i];
    }
    avg = pathVal/N; //Geometrix mean
    double disc = avg-K;
    return std::max(disc,0.0);
}

double BarrierOpt::Payoff(double *prices, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (prices[i]>=B)
        {
            //Start the clock
            bool clock = true; 
            int count = 1;
            while (clock)
            {
                //If price stays above barrier, add one to the count
                if(prices[i+count]>=B){
                    count++;
                //If period above barrier exceeds M time incraments, option is worthless
                }else if (count >= M)
                {
                    return 0;
                } else{ //clock gets reset if price drops below B
                    clock = false;
                }
            }   
        }   
    }
}