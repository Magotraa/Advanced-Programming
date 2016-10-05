#define SQR(a) (a)*(a)


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

 //color = (Red, Green, Blue)
 float* pixels = new float[width * height * 3];

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
class GeometricObjects
{
public:
	virtual void draw() {

		std::cout << "  This is a mother class  GeometricObjects" << std::endl;
	}

	void draw_red_circle(const int& center_x, const int& center_y, const int& _radius, const int& _thickness) {
		drawcircle(center_x, center_y, _radius, _thickness,1.0f,0.0f,0.0f);

	}
};

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

class Line : public GeometricObjects
{

public:
	int start_x_;
	int start_y_;
	int end_x_;
	int end_y_;

	void initialize(const int& start_x, const int& start_y, const int& end_x, const int& end_y) {
		start_x_ = start_x;
		start_y_ = start_y;
		end_x_ = end_x;
		end_y_ = end_y;
			
	}

void draw()
{
	std::cout << "  This is a child class Line" << std::endl;
	//drawLine(start_x_, start_y_, end_x_, end_y_, 0.0f, 1.0f, 0.0f);

	// drawing outer circle from base class
	GeometricObjects::draw_red_circle(100, 360, 50, 2);
	drawLine(75, 325, 125, 375, 0.0f, 0.0f, 1.0f);
}


};



class Circle : public GeometricObjects 
{

public:
	void draw()
	{
		std::cout << "  This is a child class  circle" << std::endl;


		// drawing outer circle from base class
		GeometricObjects::draw_red_circle(550, 125, 50, 2);

		drawcircle(550,125,30,2,0.0f,1.0f,0.0f);
	}



};

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

class Box: public GeometricObjects
{
public:

	void draw()
	{


		// drawing outer circle from base class
			GeometricObjects::draw_red_circle(350, 350, 50, 2);
			GeometricObjects::draw_red_circle(550, 350, 50, 2);




		//drawing empty box
		drawrectangle(0.0f,0.0f,1.0f);
		// drawing filled box.
		const int i_center = 550, j_center = 350;
		const int thickness = 26;

		for (int j = j_center - thickness; j < j_center + thickness; j++)
			for (int i = i_center - thickness; i < i_center + thickness; i++)
			{
				drawonepixel(i, j, 0.0f, 1.0f, 0.0f);

			}


	}


};
void drawtriangle(const float& red, const float& green, const float& blue)
{
	drawLine(75, 100, 125, 100, red, green, blue);
	drawLine(75, 100, 100, 150, red, green, blue);
	drawLine(125, 100, 100, 150, red, green, blue);
}
void drawpentagon(const float& red, const float& green, const float& blue)
{

	drawLine(300, 100, 325, 100, red, green, blue);

	drawLine(300, 100, 290, 125, red, green, blue);

	drawLine(325, 100, 335, 125, red, green, blue);


	drawLine(290, 125, 312, 150, red, green, blue);

	drawLine(335, 125, 312, 150, red, green, blue);



}
class Triangle: public GeometricObjects
{
public:
	void draw()
	{


		// drawing outer circle from base class
		GeometricObjects::draw_red_circle(100, 125, 50, 2);

		drawtriangle(0.0f,0.0f,1.0f);
	}

};

class Polygon : public GeometricObjects
{
public:
	void draw()
	{
		// drawing outer circle from base class
		GeometricObjects::draw_red_circle(312, 125, 50, 2);

		drawpentagon(0.0f, 0.0f, 1.0f);
	}

};

GeometricObjects  **my_objects = new GeometricObjects*[6];

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


	for (int i = 0; i<5; i++)
		my_objects[i]->draw();



	//const int i_center = 50, j_center = 50;
	//const int thickness = 5;

	//for (int j = j_center - thickness; j < j_center + thickness; j++)
	//	for (int i = i_center - thickness; i < i_center + thickness; i++)
	//	{
	//		drawonepixel(i, j, 1.0f, 0.0f, 0.0f);

	//	}

	//drawonepixel(10, 10, 600, 300, 0.0f);

	//// drawing a line
	//// drawing a line
	////TODO: anti-aliasing
	/*const int i0 = 30, i1 = 200;
	const int j0 = 400, j1 = 480;
	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);*/




	//	//drawrectangle(1.0f, 0.0f, 0.0f);
	//
	//	drawtriangle(1.0f, 0.0f, 1.0f);
	//
	//	drawpentagon(1.0f, 0.0f, 1.0f);
	//
	//	drawcircle(150, 50, 40, 1, 1.0f, 0.0f, 0.0f);
	//
	//drawcircle(150, 50, 20, 1, 1.0f, 0.0f, 0.0f);

}

int main(void) {
	my_objects[0] = new Line();	
	my_objects[1] = new Circle();
	my_objects[2] = new Box();
	my_objects[3] = new Triangle();
	my_objects[4] = new Polygon();


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Week 5: polymorphism", NULL, NULL);
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