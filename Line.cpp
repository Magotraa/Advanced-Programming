#include "Line.h"
#include "Geometricobjects.h"


//
void Line::draw()
{
	std::cout << "  This is a child class Line" << std::endl;
	//drawLine(start_x_, start_y_, end_x_, end_y_, 0.0f, 1.0f, 0.0f);

	// drawing outer circle from base class
	GeometricObjects::draw_red_circle(100, 360, 50, 2);

	for (int i = 0; i<4; i++)  // drawing thick line
		drawLine(75 - 1, 325 + i, 125 - i, 375, 0.0f, 0.0f, 1.0f);
	//drawLine(74, 326, 124, 375, 0.0f, 0.0f, 1.0f);



	//GeometricObjects::drawonepixel(1,2,2,1.0f,0.0f);
}


//
void Line::drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 < i1)
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawonepixel(i, j, red, green, blue);
		}
	}
	else if (i0 > i1)
	{
		for (int i = i1; i <= i0; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawonepixel(i, j, red, green, blue);
		}
	}
	else
	{
		if (j0 < j1)
		{
			for (int j = j0; j < j1; j++)
			{
				drawonepixel(i0, j, red, green, blue);
			}
		}
		else if (j0 > j1)
		{
			for (int j = j1; j < j0; j++)
			{
				drawonepixel(i0, j, red, green, blue);
			}
		}
		else
		{
			drawonepixel(i0, j0, red, green, blue);
		}
	}


}
