#pragma once

#include "Geometricobjects.h"



class Line : public GeometricObjects
{

public:
	int start_x_;
	int start_y_;
	int end_x_;
	int end_y_;

	void initialize(const int& start_x, const int& start_y, const int& end_x, const int& end_y) {
		start_x_ = start_x;
		start_y_ = start_y;
		end_x_ = end_x;
		end_y_ = end_y;

	}

	void draw();
	static void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);

};

