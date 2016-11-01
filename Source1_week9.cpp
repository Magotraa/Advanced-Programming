#include<iostream>

#include"Vector3D.h"
#include"Matrix3x3.h"


#include"VectorND.h"
#include"MatrixMXN.h"

//operator overloading

//overload streaming operator




int main()
{
	Vector3D v0(1,2,3);
	Vector3D v1= Vector3D(4,5,6);
	Vector3D v2;
	v2 = v0 + v1;




	//
	std::cout << v0  << std::endl;
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;

	// dot product
	std::cout << v0 * v1 << std::endl;


	Matrix3x3 m(Vector3D(1, 2, 3), Vector3D(4, 5, 6), Vector3D(7, 8, 9));

	Vector3D y = m * v0;


	std::cout << y << std::endl;



	MatrixMN<int> M(5, 4);

	VectorND<int> v(5);

	//VectorND<int> y = m * v;

	//std::cout << y << std::endl;



	return 0;
};

