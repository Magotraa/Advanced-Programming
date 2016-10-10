#include "GeometricObjects.h"


#include "Circle.h"
#include "Box.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"




void Geometricobjects::draw() {


	std::cout << "  This is a Mother class circle" << std::endl;
	//for (int i = 230; i <= 300; i++)
	//{
	//	int j = 460, x = 360;
	//	Geometricobjects::drawonepixel(i, j, 1, 0, 0);
	//	Geometricobjects::drawonepixel(i, x, 1, 0, 0);
	//}

	//for (int j = 360; j <= 460; j++)
	//{
	//	int i = 230, y = 300;
	//	Geometricobjects::drawonepixel(i, j, 1, 0, 0);
	//	Geometricobjects::drawonepixel(y, j, 1, 0, 0);
	//}
}





void Geometricobjects::drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	// testing if this code is wxwcuted.
	//std::cout << "this is a   value assigned to pixel array" << std::endl;


	//pixels[(i + width*j) * 3 + 0] = red;	//red
	//pixels[(i + width*j) * 3 + 1] = green;	//green
	//pixels[(i + width*j) * 3 + 2] = blue;	//blue


	/*Geometricobjects::drawonepixel_1(const int& i, const int& j, const float& red, const float& green, const float& blue);*/

	Geometricobjects* obj = new Geometricobjects;
	obj->drawonepixel_1(i,j,red,green,blue);

}


void Geometricobjects::drawonepixel_1(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	// testing if this code is wxwcuted.
	//std::cout << "this is a   value assigned to pixel array drawonepixel_1 " << std::endl;


	pixels[(i + width*j) * 3 + 0] = red;	//red
	pixels[(i + width*j) * 3 + 1] = green;	//green
	pixels[(i + width*j) * 3 + 2] = blue;	//blue
}

void Geometricobjects::draw_red_circle(const int& center_x, const int& center_y, const int& _radius, const int& _thickness)
{
	std::cout << "  This is a Mother class RED circle" << std::endl;

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
		return new Box;
	}
	else if (name == "Triangle")
	{
		return new Triangle;
	}
	else if (name == "Polygon")
	{
		return new Polygon;
	}
	else
	{
		return nullptr;
	}
}