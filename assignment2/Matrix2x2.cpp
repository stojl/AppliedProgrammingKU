#include "Matrix2x2.hpp"
/*
int main()
{
    Matrix2x2 A(1, 2, 3, 4);
    A.Print();
    return 0;
}
*/
Matrix2x2::Matrix2x2() : val00(0), val01(0), val10(0), val11(0) {}

Matrix2x2::Matrix2x2(const Matrix2x2& other) : 
    val00(other.val00), 
    val01(other.val01), 
    val10(other.val10), 
    val11(other.val11) {}

Matrix2x2::Matrix2x2(double a, double b, double c, double d) : 
    val00(a), val01(b), val10(c), val11(d) {}

double Matrix2x2::CalcDeterminant() const {
    return val00 * val11 - val01 * val10;
}

Matrix2x2 Matrix2x2::CalcInverse() const {
    double factor = 1/(val00 * val11 - val01 * val10);

    return Matrix2x2(factor * val11, -factor * val01, -factor * val10, factor * val00);
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;

    return *this;
}

Matrix2x2 Matrix2x2::operator-() const
{
    return Matrix2x2(-val00, -val01, -val10, -val11);
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
    return Matrix2x2(val00 + z.val00, val01 + z.val01, val10 + z.val10, val11 + z.val11);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
    return Matrix2x2(val00 - z.val00, val01 - z.val01, val10 - z.val10, val11 - z.val11);
}

void Matrix2x2::MultScalar(double scalar)
{
    val00 *= scalar;
    val01 *= scalar;
    val10 *= scalar;
    val11 *= scalar;
}

void Matrix2x2::Print() const
{
    std::cout << val00 << "\t" << val01 << std::endl;
    std::cout << val10 << "\t" << val11 << std::endl;
}