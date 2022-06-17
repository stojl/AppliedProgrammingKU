#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include <vector>
#include <iterator>
#include <cassert>
#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"

template<class T> 
class SparseVector
{
private:
	std::vector<T> mData;
	std::vector<unsigned int> mIndex;
	unsigned int mDim;

public:
	SparseVector() : mDim(0) {}
	SparseVector(unsigned int dim) : mDim(dim) {}

	void setValue(unsigned int index, T value);

	//returns the value v_i of the vector. Returns 0 if the value is not stored
	T getValue(unsigned int index) const;

	//returns the dimensionality of the vector
	unsigned int size() const {return mDim;}

	// returns the number stored elements
	unsigned int nonZeroes() const {return mData.size();}
	//returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i) const 
	{
		return mIndex[i];
	}
	//returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i) const 
	{
		if(mDim == 0) return 0;
		return mData[i];
		
	}

	//adds x too the current vector
	SparseVector<T>& operator+= (SparseVector<T> const& x);
	//subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x);

	void Print();
};

template<class T> void SparseVector<T>::setValue(unsigned int index, T value)
{

	if(index >= mDim) return;

	for(int i = 0; i < mIndex.size(); ++i)
	{
		if(index == mIndex[i])
		{
			mData[i] = value;
			return;

		} else if (index < mIndex[i])
		{
			mIndex.insert(mIndex.begin() + i, index);
			mData.insert(mData.begin() + i, value);
			return;
		}
	}

	mIndex.push_back(index);
	mData.push_back(value);

}

template<class T> T SparseVector<T>::getValue(unsigned int index) const
{
	assert(index < mDim);

	for(int i = 0; i < mIndex.size(); ++i)
	{
		if(mIndex[i] == index)
		{
			return mData[i];
		} else if (mIndex[i] > index)
		{
			break;
		}
	}

	return 0;
}

template<class T>
void SparseVector<T>::Print()
{
	if(mIndex.size() == 0)
	{
		for(int i = 0; i < mDim; ++i)
			std::cout << 0 << "  ";
		std::cout << std::endl;
		return;
	}

	int j = 0;
	for(int i = 0; i < mDim; ++i)
	{
		if(i != mIndex[j])
		{
			std::cout << 0 << "  ";
		} else if (i == mIndex[j])
		{
			std::cout << mData[j] << "  ";
			j++;
		}
	}

	std::cout << std::endl;
}

template<class T> SparseVector<T>& SparseVector<T>::operator+=(SparseVector<T> const& x)
{
	assert(x.mDim == mDim);

	int j = 0;
	int size1 = mIndex.size();

	for(int i = 0; i < mIndex.size(); ++i)
	{
		if(j == mIndex.size() | j == x.mIndex.size()) break;

		if(mIndex[i] == x.mIndex[j])
		{
			mData[i] = mData[i] + x.mData[j];
			j++;
		} else if (mIndex[i] > x.mIndex[j])
		{	
			mData.insert(mData.begin() + i, x.mData[j]);
			mIndex.insert(mIndex.begin() + i, x.mIndex[j]);
			j++;
		}
		
	}

	for(int k = j; k < x.mIndex.size(); ++k)
	{
		
		mData.push_back(x.mData[k]);
		mIndex.push_back(x.mIndex[k]);
	}

	return *this;
}

template<class T> SparseVector<T>& SparseVector<T>::operator-=(SparseVector<T> const& x)
{
	assert(x.mDim == mDim);

	int j = 0;
	int size1 = mIndex.size();

	for(int i = 0; i < mIndex.size(); ++i)
	{
		if(j == mIndex.size() | j == x.mIndex.size()) break;

		if(mIndex[i] == x.mIndex[j])
		{
			mData[i] = mData[i] - x.mData[j];
			j++;
		} else if (mIndex[i] > x.mIndex[j])
		{	
			mData.insert(mData.begin() + i, -x.mData[j]);
			mIndex.insert(mIndex.begin() + i, x.mIndex[j]);
			j++;
		}
		
	}

	for(int k = j; k < x.mIndex.size(); ++k)
	{
		mData.push_back(-x.mData[k]);
		mIndex.push_back(x.mIndex[k]);
	}

	return *this;
}

// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
	assert(x.size() == y.size());
	SparseVector<T> Z = x;

	Z += y;

	return Z;

}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
	assert(x.size() == y.size());
	SparseVector<T> Z = x;

	Z -= y;

	return Z;
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
	assert(x.size() <= A.GetNumberOfColumns());

	Vector<T> result(A.GetNumberOfRows());

	for(int i = 0; i < A.GetNumberOfRows(); ++i)
	{
		for(int j = 0; j < x.nonZeroes(); ++j)
			result[i] = result[i] + A(i, x.indexNonZero(j)) * x.valueNonZero(j);
	}

	return result;
}

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
	assert(x.size() <= A.GetNumberOfRows());
	
	Vector<T> result(A.GetNumberOfColumns());

	for(int i = 0; i < A.GetNumberOfColumns(); ++i)
	{
		for(int j = 0; j < x.nonZeroes(); ++j)
			result[i] = result[i] + A(x.indexNonZero(j), i) * x.valueNonZero(j);
	}

	return result;
}

#endif