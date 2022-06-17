#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"
#include <cassert>
#include <vector>
#include <iostream>

template<class T>
class Matrix
{
private:
    std::vector<T> mData;
	int mNumRows, mNumCols; // dimensions

public:
    Matrix() {}
	Matrix(int numRows, int numCols)
    {
        assert(numRows > 0);
        assert(numCols > 0);

        mNumRows = numRows;
        mNumCols = numCols;

        mData = std::vector<T>(numRows * numCols);

    }

    std::vector<T> const& getStorage() const{
        return mData;
    }

	int GetNumberOfRows() const
    {
        return mNumRows;
    }

	int GetNumberOfColumns() const
    {
        return mNumCols;
    }

	T& operator()(int i, int j)
    {
        return mData[i * mNumCols + j];
    }

	T const& operator()(int i, int j) const
    {
        return mData[i * mNumCols + j];
    }

	Matrix<T> operator-() const // unary -
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = -mData[i * mNumCols + j];
            }
        }
        return mat;
    }

	Matrix<T> operator+(const Matrix<T>& m1) const // binary +
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[i * mNumCols + j] + m1.mData[i * mNumCols + j];
            }
        }
        return mat;
    }

	Matrix<T> operator-(const Matrix<T>& m1) const // binary -
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[i * mNumCols + j] - m1.mData[i * mNumCols + j];
            }
        }
        return mat;
    }

	// scalar multiplication
	Matrix<T> operator*(double a) const
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = a*mData[i * mNumCols + j];
            }
        }
        return mat;
    }

    void Print() const
    {
        for(int i = 0; i < mNumRows; ++i)
        {
            for(int j = 0; j < mNumCols; ++j)
                std::cout << mData[i * mNumCols + j] << "\t";
            
            std::cout << std::endl;
        }
    }
}; // class Matrix


//matrix-vector multiplications
template<class T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

template<class T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}


#endif
