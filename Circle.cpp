#define SQR(a) (a)*(a)

#include "Circle.h"


void Circle::draw() {

	// draw this circle using center_x, center_y, radius_
	////GeometricObjects::drawredcircle();
	std::cout << "this is a child class circle" << std::endl;
	drawcircle(50, 50, 40, 20, 1.0f, 0.0f, 0.0f);
}




// a simple distance function
float Circle::distanceFrom(int x, int y, int cx, int cy) {
	return sqrt(SQR(cx - x) + SQR(cy - y));
};



void Circle::drawcircle(const int& _center_x, const int& _center_y, const int& radius, const int& thickness, const float& red, const float& green, const float& blue)
{

for (int x = _center_x - radius; x < _center_x + radius; x++) {
			for (int y = _center_y - radius; y < _center_y + radius; y++) {
				float distance = distanceFrom(x, y, _center_x, _center_y);
				if (distance < radius && distance > radius - thickness)
				{
					Geometricobjects::drawonepixel(x, y, red, green, blue);
				}
			}
		
	}

}