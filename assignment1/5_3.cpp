#include "5_3.h"

void swap_pointer(double* a, double* b)
{
  double tmp = *a;

  *a = *b;

  *b = tmp;
}

void swap_ref(double& a, double& b)
{
  double tmp = a;

  a = b;

  b = tmp;
}
