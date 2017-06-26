#ifndef PID_H
#define PID_H
#include <math.h>

class Twiddle {
public:
  /*
  * Errors
  */
    int cycle_length;
    int cycle_counter
    double dKp_prev;
    double dKd_prev;
    double prev_cte;

  /*
  * Coefficients
  */ 
  double Kp;
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
  void Update();

  /*
  * Calculate the total PID error.
  */
  double Tune();
  
};

#endif /* PID_H */