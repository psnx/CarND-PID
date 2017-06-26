#include "Twiddle.h"
#include <math.h>
#include <stdlib.h> 

using namespace std;
PID::Twiddle() {}

PID::~Twiddle() {}
/*
* TODO: Complete the PID class.
*/

void Twiddle::Init(int cycle_length)
{
    this -> cycle_length = cycle_length;
    delta = 0.01;


}

void Twiddle::Update()
{
    cycle_counter++
    sumCte += abs(cte);
    if (cycle_counter > cycle_length){
       Tune();
    }
}   


double Twiddle::Tune()
{
    
    avgCte = sumCte / double(cycle_length)
    if (sumCte < prevAvgCte){        
        K += delta;
        prev_delta = delta;        
    } else{        
        K = -dKp/2.0
        K += dKp;
        prev_delta = dKp;
        turn = true;
    }
    prevAvgCte = avgCte
    return K;

}