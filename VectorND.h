#pragma once
template<class TT>
class VectorND {


public:
	int n_dimension_;
	TT *values_;

	VectorND()
		:n_dimension_(0),  values_(nullptr)
	{};

	//VectorND(const int& x, const int& y, const int& z)
	//	:x_(x), y_(y), z_(z)
	//{}

	VectorND(const int& number)
	{
		values_ = nullptr;

		initialize(number);
	}

	void initialize(const int& number)
	{		
         n_dimension_ = number;
		for (int i = 0; i < n_dimension_; i++)
			values_[i] = TT();
		}



	//overloading plus additive operation
	//VectorND& operator+(const VectorND& input)
	//{
	//	VectorND vec;
	//	vec.x_ = this->x_ + input.x_;
	//	vec.y_ = this->y_ + input.y_;
	//	vec.z_ = this->z_ + input.z_;
	//	return  	vec;
	//}





VectorND<TT> operator+(const VectorND & vector) const
{


	VectorND<TT> result(num_dimension_);

	for (int i = 0; i<num_dimension_; i++) result[i] = values_[i] + vector.values_[i];

	return result;
}



	// dot product 
	//int operator*(const VectorND& input) {

	//	int ans;
	//	ans = this->x_ * input.x_;
	//	ans += this->y_ * input.y_;
	//	ans += this->z_ * input.z_;
	//	return ans;
	//}



VectorND <TT> operator*(const TT& s) const
{
	VectorND <TT> V(num_dimension_);

	for (int i = 0; i < num_dimension_; i++) V.values_[i] = values_[i] * s;

	return V;
}


void write(std::ofstream& os) const
{
	os.write((char*)&i_start_, sizeof(i_start_));
	os.write((char*)&j_start_, sizeof(j_start_));
	os.write((char*)&k_start_, sizeof(k_start_));

	os.write((char*)&i_res_, sizeof(i_res_));
	os.write((char*)&j_res_, sizeof(j_res_));
	os.write((char*)&k_res_, sizeof(k_res_));

	for (int p = 0; p < ijk_res_; p++)
		os.write((char*)&values_[p], sizeof(TT));
}




};

//std::ostream& operator<<(std::ostream& os, const VectorND& vec) {
//
//	os << vec.x_ << "  " << vec.y_ << "  " << vec.z_ << std::endl;
//	return os;
//
//}
