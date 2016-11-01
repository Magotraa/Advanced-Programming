#pragma once
#include "VectorND.h"
#include <fstream>

template<class T>
class MatrixMN
{
public:
	int num_rows_;  // m_
	int num_cols_;  // n_
	T *values_;

	MatrixMN()
		: values_(nullptr), num_rows_(0), num_cols_(0)
	{}
	MatrixMN(const int& _m, const int& _n)
		: values_(nullptr), num_rows_(0), num_cols_(0)
	{}

	void initialize(const int& _m, const int& _n)
	{	
		num_rows_ = _m;
		num_cols_ = _n;

		SAFE_DELETE_ARRAY(values_);

		const int num_all = num_rows_ * num_cols_;
		
		{
		
			values_ = new T[num_all];
				for (int i = 0; i < num_all; i++)
					values_[i] = (T)0;
		}
	}




	void cout()
	{
		for (int row = 0; row < num_rows_; row++)
		{
			for (int col = 0; col < num_cols_; col++)
			{
				std::cout << getValue(row, col) << " ";
			}

			std::cout << std::endl;
		}
	}

	void writeTXT(std::ofstream& of) const
	{
		of << num_rows_ << " " << num_cols_ << std::endl;
		for (int i = 0; i < num_rows_ * num_cols_; i++)
		{
			of << values_[i];

			if (i != num_rows_ * num_cols_ - 1)
				of << " ";
		}
		of << std::endl;
	}




	void multiply(const VectorND<T>& vector, VectorND<T>& result) const
	{

#pragma omp parallel for
		for (int row = 0; row < num_rows_; row++)
		{
			result.values_[row] = (T)0;

			int ix = row*num_cols_;
			T temp;

			for (int col = 0; col < num_cols_; col++, ix++)
			{
				temp = values_[ix];
				temp *= vector.values_[col];

				result.values_[row] += temp;
			}
		}
	}





};
