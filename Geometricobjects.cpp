#include "GeometricObjects.h"


#include "Circle.h"
#include "Box.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"







void Geometricobjects::drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width*j) * 3 + 0] = red;	//red
	pixels[(i + width*j) * 3 + 1] = green;	//green
	pixels[(i + width*j) * 3 + 2] = blue;	//blue
}

void Geometricobjects::draw_red_circle(const int& center_x, const int& center_y, const int& _radius, const int& _thickness)
{
	std::cout << "  This is a Mother class circle" << std::endl;

	//Circle::drawcircle(const int& _center_x, const int& _center_y, const int& radius, const int& thickness, const float& red, const float& green, const float& blue)
	Circle::drawcircle(center_x, center_y, _radius, _thickness, 1.0f, 0.0f, 0.0f);



	
}

Geometricobjects* Geometricobjects::createGeometricObjects(std::string& name)
{
	//switchcase
	if (name == "Circle") {

	
		return new Circle;
	}
	else if (name == "Line")
	{
		return new Line;
	}
	else if (name == "Box")
	{
		return new Line;
	}
	else if (name == "Triangle")
	{
		return new Line;
	}
	else if (name == "Polygon")
	{
		return new Line;
	}
	else
	{
		return nullptr;
	}
}