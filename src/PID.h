#ifndef PID_H
#define PID_H
#include <math.h>
#include "Twiddle.h"


class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  Twiddle p_twiddle;
  Twiddle i_twiddle;
  Twiddle d_twiddle;

  int cycle_counter;
  int d_it;


  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
};

#endif /* PID_H */
