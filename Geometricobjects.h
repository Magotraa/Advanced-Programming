#pragma once
#include <iostream>

const int width = 640;
const int height = 480;
const int num_lines = 3;
// color = (Red, Green, Blue)

namespace
{
	float* pixels = new float[width * height * 3];
}


//interface  
class GeometricObjects {

public:

	virtual void draw() {
	}
	void drawredcircle();
	void drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
	
};
