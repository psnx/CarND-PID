#include "PID.h"
#include <math.h>
#include <stdlib.h> 

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;

    p_error = 0;
    d_error = 0;
    i_error = 0;
    
}


void PID::UpdateError(double cte) 
{
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;    
}

double PID::TotalError() 
{
    double gain_factor;
    if (abs(p_error) > 5)
    {
        gain_factor = 1.5;
    } else {
        gain_factor = 1;
    }
    return Kp*p_error + Kd*d_error + Ki*i_error;
    
}

void Twiddle(cte)
{
    SetParams();
    Probe();
    Evaluate();

}
