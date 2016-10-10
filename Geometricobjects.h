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
class Geometricobjects {

public:

	virtual void draw() {}
	static void draw_red_circle(const int& center_x, const int& center_y, const int& _radius, const int& _thicknes);
	static void drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue);

	static Geometricobjects* createGeometricObjects(std::string& name);
	
};
