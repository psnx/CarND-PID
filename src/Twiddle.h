#ifndef TWIDDLE_H
#define TWIDDLE_H
#include <math.h>
#include "Twiddle.h"

class Twiddle {
public:
  /*
  * Errors
  */
    int cycle_length;
    int cycle_counter;
    double prev_cte;
    double sumCte;
    double prev_delta;
    double cte;
    double delta;
    int iteration;

  /*
  * Coefficients
  */ 
  double K;
  double avgCte;    
  double prevAvgCte;


  /*
  * Constructor
  */
  Twiddle();

  /*
  * Destructor.
  */
  virtual ~Twiddle();

  /*
  * Initialize PID.
  */
  void Init(int cycle_length, double delta);

  /*
  * Update the PID error variables given cross track error.
  */
  double Update(double cte, double K);

  /*
  * Calculate the total PID error.
  */
  double Tune();
  
};

#endif /* TWIDDLE_H */