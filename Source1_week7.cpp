#define SQR(a) (a)*(a)



#include <vector>
//#include "Geometricobjects.h"
#include <GLFW\glfw3.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

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


void drawrectangle(const int& x_, const int& y_, const float& red, const float& green, const float& blue)
{

	for (int i = 125; i <= 175; i++)
	{
		int j = 175, x = 125;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(i, x, red, green, blue);
	}

	for (int j = 125; j <= 175; j++)
	{
		int i = 125, y = 175;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(y, j, red, green, blue);
	}


	//horizontal lines
	for (int i = 325 + x_; i <= 375 -x_; i++)
	{
		int j = 375 - y_, x = 325+y_;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(i, x, red, green, blue);
	}

	//vertical lines
	for (int j = 325+ y_; j <= 375 -y_; j++)
	{
		int i = 325+x_, y = 375-x_;
		drawonepixel(i, j, red, green, blue);
		drawonepixel(y, j, red, green, blue);
	}


	//filled square

	////for (int i = 330; i <= 390; i++)
	////{
	////	int j = 460, x = 360;

	////	for (int j = 360; j <= 460; j++)
	////	{
	////		drawonepixel(i, j, red, green, blue);
	////		//drawonepixel(i, x, red, green, blue);
	////	}
	////}


}


class Box // NO PARENT (2pts)
{
public:
	// some variables
	void draw()
	{
		// draw box here

		//drawing empty box
		drawrectangle(10,10,0.0f, 0.0f, 1.0f);

		drawrectangle(40, 40, 1.0f, 0.0f, 0.0f);
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
class GeometricObject_inner_objects : public GeometricObjectInterface
{

public:

	void draw()
	{
		T_operation  operation;
		operation.draw();

	}
};





//class to draw  for outer circle and box
class GeometricObject_Outer_objects
{

public:



	/*void draw() {};*/
void (GeometricObject_Outer_objects::*draw_surrounding_object_callback)(void) = nullptr;
	
void exe() {

	(this->*draw_surrounding_object_callback)();
}


void drawCircle() {

	std::cout << "Draw circle"<< std::endl;


	drawcircle(550, 125, 45, 2, 0.0f, .0f, 1.0f);
	drawcircle(150, 150, 45, 2, 0.0f, 1.0f, 1.0f);
}

void drawBox() {

	std::cout << "Draw Box" << std::endl;

	drawrectangle(-10, -10, 1.0f, 0.0f, 0.0f);
}

static GeometricObject_Outer_objects * getpointer(const std::string type_name)
{
	auto new_ob = new GeometricObject_Outer_objects;

	if (type_name == "Box")
		new_ob->draw_surrounding_object_callback = &GeometricObject_Outer_objects::drawBox;
	else if (type_name == "Circle")
		new_ob->draw_surrounding_object_callback = &GeometricObject_Outer_objects::drawCircle;

	return new_ob;

}

};


std::vector<GeometricObject_Outer_objects*> obj_list_;


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


	for (auto itr : obj_list_)
		(itr)->exe();
}




int main()
{

	//code to outer  outer circle and box 
	{
		//std::vector<GeometricObject_*> obj_list_;
		obj_list_.push_back(GeometricObject_Outer_objects::getpointer("Box"));
		obj_list_.push_back(GeometricObject_Outer_objects::getpointer("Circle"));

	}


	//code for inner objects
	{
		//std::vector<GeometricObjectInterface*> obj_list;
		obj_list.push_back(new GeometricObject_inner_objects<Box>);
		obj_list.push_back(new GeometricObject_inner_objects<Circle>);
	}




	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Week 7: Function pointer and polymorphism ", NULL, NULL);
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