#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>
#include <cmath>
#include <cassert>

class ComplexNumber;
double RealPart(const ComplexNumber& z);
double ImaginaryPart(const ComplexNumber& z);
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z);

class ComplexNumber
{
    private:
        double mRealPart;
        double mImaginaryPart;
    public:
        ComplexNumber(): mRealPart(0), mImaginaryPart(0) {}
        ComplexNumber(const double x, const double y): mRealPart(x) , mImaginaryPart(y) {}
        ComplexNumber(const double real): mRealPart(real), mImaginaryPart(0) {}
        double CalculateModulus() const;
        double CalculateArgument() const;
        ComplexNumber CalculatePower(double n) const;
        ComplexNumber& operator=(const ComplexNumber& z);
        void operator+=(const ComplexNumber& z);
        ComplexNumber operator-() const;
        ComplexNumber operator+(const ComplexNumber& z) const;
        ComplexNumber operator+(const double x) const;
        ComplexNumber operator-(const ComplexNumber& z) const;
        ComplexNumber operator-(const double x) const;
        friend std::ostream& operator<<(std::ostream& output,const ComplexNumber& z);

        //exercise prototypes
        double GetRealPart() const;
        double GetImaginaryPart() const;
        friend double RealPart(const ComplexNumber& z);
        friend double ImaginaryPart(const ComplexNumber& z);
        ComplexNumber CalculateConjugate() const;
        void SetConjugate();

        //not mandatory, but useful for exercise 6.1.7
        ComplexNumber operator*(const ComplexNumber& z) const;
        ComplexNumber operator*(double x) const;
};

#endif
