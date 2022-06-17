#include "ComplexNumber.hpp"

double ComplexNumber::CalculateModulus() const
{
    return std::sqrt(mRealPart*mRealPart + mImaginaryPart * mImaginaryPart);
}

double ComplexNumber::CalculateArgument() const
{
    assert(mRealPart != 0 || mImaginaryPart != 0);

    if(mRealPart == 0 && mImaginaryPart > 0)
    {
        return M_PI / 2;
    } else if (mRealPart == 0 && mImaginaryPart < 0)
    {
        return M_PI * 1.5;
    } else if (mRealPart > 0 && mImaginaryPart >= 0)
    {
        return std::atan(mImaginaryPart/mRealPart);
    } else if (mRealPart < 0 && mImaginaryPart >= 0)
    {
        return M_PI - std::atan(-mImaginaryPart/mRealPart);
    } else if (mRealPart < 0 && mImaginaryPart < 0)
    {
        return M_PI + std::atan(mImaginaryPart/mRealPart);
    } else if (mRealPart > 0 && mImaginaryPart < 0)
    {
        return 2 * M_PI - std::atan(-mImaginaryPart/mRealPart);
    }

    return 0;
}

ComplexNumber ComplexNumber::CalculatePower(double n) const
{

    double modulus = std::pow(this->CalculateModulus(), n);
    double argument = n * this->CalculateArgument();

    return ComplexNumber(std::cos(argument) * modulus, std::sin(argument) * modulus);
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.GetRealPart();
    mImaginaryPart = z.GetImaginaryPart();

    return *this;
}

void ComplexNumber::operator+=(const ComplexNumber& z)
{
    mRealPart += z.mRealPart;
    mImaginaryPart += z.mImaginaryPart;
}

ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-mRealPart, -mImaginaryPart);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart + z.GetRealPart(), mImaginaryPart + z.GetImaginaryPart());
}

ComplexNumber ComplexNumber::operator+(const double x) const
{
    return ComplexNumber(mRealPart + x, mImaginaryPart);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart - z.GetRealPart(), mImaginaryPart - z.GetImaginaryPart());
}

ComplexNumber ComplexNumber::operator-(const double x) const
{
    return ComplexNumber(mRealPart - x, mImaginaryPart);
}

double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

ComplexNumber ComplexNumber::CalculateConjugate() const
{
    return ComplexNumber(mRealPart, -mImaginaryPart);
}

void ComplexNumber::SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
    double real = mRealPart*z.GetRealPart() - mImaginaryPart*z.GetImaginaryPart();
    double imaginary = mRealPart*z.GetImaginaryPart() + mImaginaryPart * z.GetRealPart();
    return ComplexNumber(real, imaginary);
}

ComplexNumber ComplexNumber::operator*(double x) const
{
    return ComplexNumber(x*mRealPart, x*mImaginaryPart);
}

std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{   
    
    if(z.mImaginaryPart < 0)
    {
        output << z.mRealPart << "-" << -z.mImaginaryPart << "i";
    } else
    {
        output << z.mRealPart << "+" << z.mImaginaryPart << "i";
    }

    return output;
}