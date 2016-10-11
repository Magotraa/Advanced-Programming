#define SQR(a) (a)*(a)



#include <vector>
//#include "Geometricobjects.h"
#include <GLFW\glfw3.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#include <vector>

GLFWwindow* window;
double win_x, win_y;


const int width = 640;
const int height = 480;
const int num_lines = 3;

float* pixels = new float[width * height * 3];


//std::vector<Geometricobjects*> go_vector;
//std::vector<GeometricObjectInterface*> obj_list;
//obj_list = nullptr;



void drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width *j) * 3 + 0] = red;
	pixels[(i + width *j) * 3 + 1] = green;
	pixels[(i + width *j) * 3 + 2] = blue;
}


// a simple distance function
float distanceFrom(int x, int y, int cx, int cy) {
	return sqrt(SQR(cx - x) + SQR(cy - y));
};

void drawcircle(const int& _center_x, const int& _center_y, const int& radius, const int& thickness, const float& red, const float& green, const float& blue)
{

	for (int x = _center_x - radius; x < _center_x + radius; x++) {
		for (int y = _center_y - radius; y < _center_y + radius; y++) {
			float distance = distanceFrom(x, y, _center_x, _center_y);
			if (distance < radius && distance > radius - thickness)
			{
				drawonepixel(x, y, red, green, blue);
			}
		}

	}

}


void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
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


void drawrectangle(const float& red, const float& green, const float& blue)
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


	//for (int i = 330; i <= 390; i++)
	//{
	//	int j = 460, x = 360;

	//	for (int j = 360; j <= 460; j++)
	//	{
	//		drawonepixel(i, j, red, green, blue);
	//		//drawonepixel(i, x, red, green, blue);
	//	}
	//}


}


class Box // NO PARENT (2pts)
{
public:
	// some variables
	void draw()
	{
		// draw box here

		//drawing empty box
		drawrectangle(0.0f, 0.0f, 1.0f);
	}
};



class Circle // NO PARENT (2pts)
{
public:
	// some variables
	void draw()

	{
		// draw circle here

		drawcircle(550, 125, 30, 2, 0.0f, 1.0f, 0.0f);
	}
};


class GeometricObjectInterface
{
public:
	// implement here

	virtual void draw() = 0;
};


std::vector<GeometricObjectInterface*> obj_list;



// And implement an templatized GeometricObject class. (3pts)

template<class T_operation>
class GeometricObject : public GeometricObjectInterface
{

public:

	void draw()
	{
		T_operation  operation;
		operation.draw();

	}
};



void draw()
{
	//white background(1.0,1.0,1.0)
	//let assign all pixels red color
	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			pixels[(i + width *j) * 3 + 0] = 1.0f;
			pixels[(i + width *j) * 3 + 1] = 1.0f;
			pixels[(i + width *j) * 3 + 2] = 1.0f;
		}


	for (auto itr : obj_list)
		(itr)->draw();
}




int main()
{

	//std::vector<GeometricObjectInterface*> obj_list;
	obj_list.push_back(new GeometricObject<Box>);
	obj_list.push_back(new GeometricObject<Circle>);
	
	
	
	/*for (auto itr : obj_list)
		itr->draw();*/
	


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Week 6: polymorphism", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glfwGetCursorPos(window, &win_x, &win_y);

		draw();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels;

	return 0;

}