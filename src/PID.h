#ifndef PID_H
#define PID_H

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

  /*
  * Twiddle variables
  */
  std::vector<double> dp;
  int step;
  int param_index;
  int settle_steps;
  int eval_steps;
  double total_error;
  double best_error;
  bool try_add;
  bool try_subtract;
  bool use_twiddle;

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

  /*
  * Convenience function for adding dp amount to a PID controller parameter based on index
  */
  void AddToDpAtIndex(int index, double amount);
};

#endif /* PID_H */
