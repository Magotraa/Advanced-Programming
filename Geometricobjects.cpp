#include "GeometricObjects.h"






void GeometricObjects::drawredcircle() {

	std::cout << "  This is a Mother class circle" << std::endl;
}

void GeometricObjects::drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width*j) * 3 + 0] = red;	//red
	pixels[(i + width*j) * 3 + 1] = green;	//green
	pixels[(i + width*j) * 3 + 2] = blue;	//blue
}