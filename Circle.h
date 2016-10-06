#pragma once
#include <iostream>
#include "GeometricObjects.h"

class Circle  : public GeometricObjects
{
public:
	int center_x_, center_y_, radius_;

	//Circle()
	//{}


	//Circle(const int& _x, const int& _y, const int& _r)
	//	: center_x_(_x)////, y, r.......
	//{
	//}



	//void init(const int& _x, const int& _y, const int& _r)
	//{
	//}

	void draw();
	static float distanceFrom(int x, int y, int cx, int cy);
	static void drawcircle(const int& _center_x, const int& _center_y, const int& radius, const int& thickness, const float& red, const float& green, const float& blue);
	
};
