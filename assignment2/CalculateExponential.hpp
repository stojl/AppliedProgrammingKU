#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);
void Multiply(ComplexNumber** A, ComplexNumber** B, ComplexNumber** res);
void AddMult(ComplexNumber** A, ComplexNumber** B, double x);
//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols);

#endif
