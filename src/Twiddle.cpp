#include "Twiddle.h"
#include <math.h>
#include <stdlib.h> 

using namespace std;
Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}
/*
* TODO: Complete the PID class.
*/

void Twiddle::Init(int cycle_length, double delta)
{
    this -> cycle_length = cycle_length;
    this -> delta = delta;
    cycle_counter = 0;
    prevAvgCte = 100; 
    iteration = 0;


}

double Twiddle::Update(double cte, double K)
{
    this -> K = K;
    this -> cte = cte;
    cycle_counter++;
    sumCte += abs(cte);
    if (cycle_counter >= cycle_length){
       K = Tune();
       cycle_counter = 0;
       sumCte = 0;
       iteration++;
    }
    return K;
}   


double Twiddle::Tune()
{
    
    avgCte = sumCte / double(cycle_length);

    if (avgCte < prevAvgCte) 
    {        
        K += delta;        
    } else {             
        delta = -delta/2.0; 
        K += delta;        
    }
    prevAvgCte = avgCte;    
    return K;

}