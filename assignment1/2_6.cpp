#include "2_6.h"
#include <cmath>
#include <cassert>
#include <iostream>
#include <limits>

double newton_Raphson(double initialGuess, double epsilon)
{

  double x_prev, x_next;
  double minEps = std::numeric_limits<double>::denorm_min();
  double k = -1;
  x_next = initialGuess;
  
  do
  {
    x_prev = x_next;
    
    x_next = x_prev - f(x_prev)/f_prime(x_prev);

  }while(std::abs(x_next - x_prev) > epsilon);

  return x_next;
}

double f(double x)
{
  return std::exp(x)+std::pow(x,3)-5;
}

double f_prime(double x)
{
  return std::exp(x)+3*std::pow(x,2);
}
