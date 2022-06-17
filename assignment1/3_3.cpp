#include "3_3.h"
#include <sstream>
#include <cassert>
#include <fstream>

void implicit_Euler(int n)
{
  assert(n > 1);

  n -= 1;

  double h = (double) 1/n;
  
  double ynext, yprev, xnext;
  
  ynext = 1;
  xnext = 0;
  
  std::ofstream myfile;
  
  myfile.open("xy.dat");
  myfile << xnext << "," << ynext << "\n";

  for(int i = 0; i < n; i++)
  {
    yprev = ynext;
    xnext += h;
    ynext = yprev - h * yprev;

    myfile << xnext << "," << ynext << "\n";
  }

}
