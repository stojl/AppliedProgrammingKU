#include "5_4.h"
#include <cassert>
#include <cmath>

double calc_mean(double a[], int length)
{
  assert(length > 0);

  double sum = 0;
  
  for(int i = 0; i < length; i++)
    sum += a[i];

  return (double) sum/length;
}

double calc_std(double a[], int length)
{ 

  assert(length > 0);

  int N;

  (length == 1) ? N = 1 : N = length - 1;

  double mean = calc_mean(a, length);

  double sugma = 0;

  for(int i = 0; i < length; i++)
    sugma += (a[i]-mean)*(a[i]-mean);

  return std::sqrt(sugma/N);
}
