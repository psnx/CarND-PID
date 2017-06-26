#include "PID.h"
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include "Twiddle.h"
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

    //Twiddle twiddle;
    twiddle.Init(100);
    
}


void PID::UpdateError(double cte) 
{
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;    
    
    Kp = twiddle.Update(cte, Kd);
    std::cout << "cycle: \t" << twiddle.cycle_counter <<" \t Kd: " << Kd << endl;
}

double PID::TotalError() 
{

    return Kp*p_error + Kd*d_error + Ki*i_error;    
}