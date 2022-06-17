#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>

template<class T> 
class Vector
{
private:
	std::vector<T> mData; // data stored in vector
	int mSize; // size of vector

public:
    // copy constructor
	Vector(int size)
    {
        assert(size > 0);

        mSize = size;
        mData = std::vector<T>(size);
    }

	int size() const
    {
        return mSize;
    }

	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

	T const& operator[] (int i) const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

    // overloading the unary - operator
	Vector<T> operator-() const
    {
        Vector<T> v(mSize);

        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }

        return v;
    }

    // overloading the binary + operator
	Vector<T> operator+(const Vector<T>& v1) const
    {
        assert(mSize == v1.size());

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector<T> operator-(const Vector<T>& v1) const
    {

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector<T> operator*(double a) const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	// p-norm method
	double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mSize; i++)
        {
            sum += std::pow(std::abs(mData[i]), p);
        }
        return std::pow(sum, 1.0 / ((double)(p)));
    }

    void Print() const
    {
        for(auto &elem : mData)
        {
            std::cout << elem << "  ";
        }

        std::cout << std::endl;
    }
};


#endif
