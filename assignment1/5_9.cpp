#include "5_9.h"
#include <limits>
#include <cmath>
#include <cassert>
#include <iostream>

void solve3by3(double** A, double* b, double* u)
{
  guassian_elimination(A, b, u, 3);
}

void backwardSubstitution(double* u, double** A, double* b, int n)
{
  u[n - 1] = b[n - 1];

  for(int i = n - 2; i >= 0; i--)
  {
    u[i] = b[i];

    for(int j = n - 1; j > i; j--)
      u[i] -= A[i][j] * u[j];
  }
}

bool pivot(double** res, double* u, int i, int n)
{
  double minEps = std::numeric_limits<double>::denorm_min();
  
  if(i == n - 1 && std::fabs(res[i][i]) <= minEps)
    return false;

  // Find maximum
  int k = i;
  double tmpMax = std::fabs(res[i][i]);
  
  for(int j = i + 1; j < n; j++)
  {
    if(std::fabs(tmpMax) < std::fabs(res[j][i]))
    {
      k = j;
      tmpMax = res[j][i];
    }
  }

  if(std::fabs(tmpMax) <= minEps)
    return false;

  // SWAP ROWS
  double* tmp = res[k];
  res[k] = res[i];
  res[i] = tmp;

  // SWAP VECTOR
  double tmpVec = u[k];
  u[k] = u[i];
  u[i] = tmpVec;

  return true;
}

void normalizeRow(double** res, double* u, int i, int n)
{
  double denominator = res[i][i];

  for(int j = i; j < n; j++)
  {
    res[i][j] /= denominator;
  }

  u[i] /= denominator;
}

void killRows(double** res, double* u, int i, int n)
{
  double factor;
  for(int j = i + 1; j < n; j++)
  {
    factor = res[j][i];

    for(int k = i; k < n; k++)
      res[j][k] -= res[i][k] * factor;
    
    u[j] -= u[i] * factor;
  }
}

bool reduceSystem(double** res, double* u, double** A, double* b, int n)
{
  // COPY MATRIX TO RESULT MATRIX AND VECTORS
  for(int i = 0; i < n; i++)
  {
    u[i] = b[i];
    for(int j = 0; j < n; j++)
      res[i][j] = A[i][j];
  }

  for(int i = 0; i < n - 1; i++)
  {
    if(!pivot(res, u, i, n))
    {
      return false;
    }
    normalizeRow(res, u, i, n);
    killRows(res, u, i, n);
  } 

  if(std::fabs(res[n-1][n-1]) <= std::numeric_limits<double>::denorm_min())
  {
    return false;
  }

  normalizeRow(res, u, n-1, n);

  return true;
}

void guassian_elimination(double** A, double* b, double* u, int n)
{
  double** res = allocateMatrix(n, n);

  if(!reduceSystem(res, u, A, b, n))
  {
    std::cout << "Matrix is singular - cannot solve" << std::endl;
    freeMatrix(res, n);
    return;
  }

  backwardSubstitution(u, res, u, n);

  freeMatrix(res, n);
}

double** allocateMatrix(int rows, int cols)
{
  double** matrix = new double*[rows];
  for(int i = 0; i < rows; i++)
    matrix[i] = new double[cols];

  return matrix;
}

void freeMatrix(double** matrix, int rows)
{
  for(int i = 0; i < rows; i++)
    delete[] matrix[i];

  delete[] matrix;
}