#include "5_6.h"
#include <cassert>

void Multiply(
    double** res,
    double** A,
    double** B,
    int ARows,
    int ACols,
    int BRows,
    int BCols
    )
{
  assert(ARows == BCols);
  assert(ACols == BRows);

  for(int j = 0; j < ARows; j++)
  {
    for(int i = 0; i < BCols; i++)
    {
      res[j][i] = 0;

      for(int k = 0; k < ACols; k++)
        res[j][i] += A[j][k] * B[k][i];

    }
  }
}

void Multiply(
    double* res,
    double* A,
    double** B,
    int ACols,
    int BRows,
    int BCols)
{
  assert(ACols == BRows);

  for(int i = 0; i < BCols; i++)
  { 
    res[i] = 0;
    for(int k = 0; k < ACols; k++)
      res[i] += A[k]*B[k][i];
  }
}


void Multiply(
    double* res,
    double** A,
    double* B,
    int ARows,
    int ACols,
    int BRows)
{
  assert(ACols == BRows);

  for(int i = 0; i < ARows; i++)
  { 
    res[i] = 0;
    for(int k = 0; k < ACols; k++)
      res[i] += A[i][k]*B[k];
  }
}

void Multiply(
    double** res,
    double scalar,
    double** B,
    int BRows,
    int BCols)
{
  for(int j = 0; j < BRows; j++)
  {
    for(int i = 0; i < BCols; i++)
      res[j][i] = scalar * B[j][i];
  }
}

void Multiply(
    double** res,
    double** B,
    double scalar,
    int BRows,
    int BCols)
{
  for(int j = 0; j < BRows; j++)
  {
    for(int i = 0; i < BCols; i++)
      res[j][i] = scalar * B[j][i];
  }
}

