#include "Box.h"


void Box::draw()  // declaration  - definition (header , body)
{
	GeometricObjects::drawredcircle();
	std::cout << "  This is a child class  Box" << std::endl;

	drawrectangle(1.0f, 1.0f, 0.0f);
	



	

}


void Box::drawrectangle(const float& red, const float& green, const float& blue)
{

	for (int i = 230; i <= 300; i++)
	{
		int j = 460, x = 360;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(i, x, red, green, blue);
	}

	for (int j = 360; j <= 460; j++)
	{
		int i = 230, y = 300;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(y, j, red, green, blue);
	}


	for (int i = 330; i <= 390; i++)
	{
		int j = 460, x = 360;

		for (int j = 360; j <= 460; j++)
		{
			drawonepixel(i, j, red, green, blue);
			//drawonepixel(i, x, red, green, blue);
		}
	}


}