#pragma once
#include <iostream>
#include "GeometricObjects.h"

class Circle  : public GeometricObjects



{
public:
	int center_x_, center_y_, radius_;

	Circle()
	{}


	Circle(const int& _x, const int& _y, const int& _r)
		: center_x_(_x)////, y, r.......
	{
	}



	void init(const int& _x, const int& _y, const int& _r)
	{
	}

	void draw();
	
};
