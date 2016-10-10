#include "Box.h"


void Box::draw()  // declaration  - definition (header , body)
{
  //
	Geometricobjects::draw_red_circle(350, 350, 50, 2);
	Geometricobjects::draw_red_circle(550, 350, 50, 2);

	//
	std::cout << "  This is a child class  Box" << std::endl;

	//drawrectangle(1.0f, 1.0f, 0.0f);
	
	//
	//drawing empty box
	drawrectangle(0.0f, 0.0f, 1.0f);
	// drawing filled box.
	const int i_center = 550, j_center = 350;
	const int thickness = 26;

	for (int j = j_center - thickness; j < j_center + thickness; j++)
		for (int i = i_center - thickness; i < i_center + thickness; i++)
		{
			Geometricobjects::drawonepixel(i, j, 0.0f, 1.0f, 0.0f);

		}


}


	




void Box::drawrectangle(const float& red, const float& green, const float& blue)
{

	for (int i = 325; i <= 375; i++)
	{
		int j = 375, x = 325;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(i, x, red, green, blue);
	}

	for (int j = 325; j <= 375; j++)
	{
		int i = 325, y = 375;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(y, j, red, green, blue);
	}


}