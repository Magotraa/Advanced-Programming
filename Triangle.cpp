
#include "Triangle.h"
#include "Geometricobjects.h"
#include "Line.h""



void Triangle::draw()
{


	// drawing outer circle from base class
	GeometricObjects::draw_red_circle(100, 125, 50, 2);

	drawtriangle(0.0f, 0.0f, 1.0f);
}



void Triangle::drawtriangle(const float& red, const float& green, const float& blue)
{
	Line::drawLine(75, 100, 125, 100, red, green, blue);
	Line::drawLine(75, 100, 100, 150, red, green, blue);
	Line::drawLine(125, 100, 100, 150, red, green, blue);
}
