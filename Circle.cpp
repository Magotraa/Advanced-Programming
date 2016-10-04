#include "Circle.h"


void Circle::draw() {

	// draw this circle using center_x, center_y, radius_
	GeometricObjects::drawredcircle();
	std::cout << "this is a child class circle" << std::endl;

}