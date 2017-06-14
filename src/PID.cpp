#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() :
  p_error(0.0),
  i_error(0.0),
  d_error(0.0),
  Kp(0.0),
  Ki(0.0),
  Kd(0.0)
{
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error = i_error + cte;
}

double PID::TotalError() {
  return p_error * Kp + d_error * Kd + i_error * Ki;
}

