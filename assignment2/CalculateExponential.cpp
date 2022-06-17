#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
/*
int main()
{

    double a[9] = {1,2,3,3,2,1,2,3,1};

    ComplexNumber* A[3];
    A[0] = new ComplexNumber[3];
    A[1] = new ComplexNumber[3];
    A[2] = new ComplexNumber[3];

    ComplexNumber* B[3];
    B[0] = new ComplexNumber[3];
    B[1] = new ComplexNumber[3];
    B[2] = new ComplexNumber[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            A[i][j] = ComplexNumber(i, j);
        }
    }

    CalculateExponential(A, 100, B);
    printMatrix(B, 3, 3);

    delete[] A[0];
    delete[] A[1];
    delete[] A[2];

    delete[] B[0];
    delete[] B[1];
    delete[] B[2];

    return 0;

}
*/
void Multiply(ComplexNumber** A, ComplexNumber** B, ComplexNumber** res)
{   
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {   
            res[i][j] = ComplexNumber(0);
            for(int k = 0; k < 3; k++)
                res[i][j] = res[i][j] + B[i][k]*A[k][j];
        }
    }
}

void AddMult(ComplexNumber** A, ComplexNumber** B, double x)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            B[i][j] = (B[i][j] + (A[i][j]*x));
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    ComplexNumber* B[3];
    B[0] = new ComplexNumber[3];
    B[1] = new ComplexNumber[3];
    B[2] = new ComplexNumber[3];

    ComplexNumber* C[3];
    C[0] = new ComplexNumber[3];
    C[1] = new ComplexNumber[3];
    C[2] = new ComplexNumber[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            B[i][j] = A[i][j];
            if(i == j)
            {
                res[i][j] = ComplexNumber(1);
            } else
            {
                res[i][j] = ComplexNumber(0);
            }
        }
    }
    double k = 1;
    bool check = true;
    for(int i = 1; i < nMax; i++)
    {   
        k *= i;
        if(check)
        {
            AddMult(B, res, 1/k);
            Multiply(A, B, C);
            check = false;
        } else {
            AddMult(C, res, 1/k);
            Multiply(A, C, B);
            check = true;
        }
        
    }

    delete[] B[0];
    delete[] B[1];
    delete[] B[2];

    delete[] C[0];
    delete[] C[1];
    delete[] C[2];

}

void printMatrix(ComplexNumber **A, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            std::cout << A[i][j] << "\t";

        std::cout << std::endl;
    }
}