#include "TriModel.h"
#include <cmath>

using namespace std;

/* MEMBER FUNCTIONS IMPLEMENTATIONS */

void TriModel::Set_dtdx(double T, int N)
{
    dt = T/N;
    dx = sigma*sqrt(2*dt);
}

double TriModel::RiskNeutProb_up()
{
    return 0.5*((sigma*sigma*dt + nu*nu*dt*dt)/dx/dx + nu*dt/dx);
}

double TriModel::RiskNeutProb_down()
{
    return 0.5*((sigma*sigma*dt + nu*nu*dt*dt)/dx/dx - nu*dt/dx);
}