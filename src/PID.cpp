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
    p_twiddle.Init(1000, 0.001);
    i_twiddle.Init(1000, 0.001);
    d_twiddle.Init(1000, 0.0001);
    
}


void PID::UpdateError(double cte) 
{
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;    
    
    if (d_twiddle.iteration < 6){ Kd = d_twiddle.Update(cte, Kd); }
    else {
        if (p_twiddle.iteration < 6){ Kp = p_twiddle.Update(cte, Kp); }
        else{
            if (i_twiddle.iteration < 6){ Kp = i_twiddle.Update(cte, Ki); }
        }
    }

    //Kp = p_twiddle.Update(cte, Kp);
    //Ki = i_twiddle.Update(cte, Ki);
    
    std::cout << "cycle: \t" << "Kd: " << Kd;
    std::cout << "cycle: \t" << "Kp: " << Kp;
    std::cout << "cycle: \t" << "Ki: " << Ki << endl;
}

double PID::TotalError() 
{
    return Kp*p_error + Kd*d_error + Ki*i_error;    
}