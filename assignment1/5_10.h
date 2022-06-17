#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);
double** allocateMatrix(int rows, int cols);
void freeMatrix(double** matrix, int rows);
bool reduceSystem(double** res, double* u, double** A, double* b, int n);
bool pivot(double** res, double* u, int i, int n);
void killRows(double** res, double* u, int i, int n);
void normalizeRow(double** res, double* u, int i, int n);
void backwardSubstitution(double* u, double** A, double* b, int n);
#endif
