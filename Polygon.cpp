#include "Polygon.h"
#include "Geometricobjects.h"
#include "Line.h"




void Polygon::draw()
{
	// drawing outer circle from base class
	Geometricobjects::draw_red_circle(312, 125, 50, 2);

	drawpentagon(0.0f, 0.0f, 1.0f);
}



void Polygon::drawpentagon(const float& red, const float& green, const float& blue)
{

	Line::drawLine(300, 100, 325, 100, red, green, blue);

	Line::drawLine(300, 100, 290, 125, red, green, blue);

	Line::drawLine(325, 100, 335, 125, red, green, blue);


	Line::drawLine(290, 125, 312, 150, red, green, blue);

	Line::drawLine(335, 125, 312, 150, red, green, blue);



}