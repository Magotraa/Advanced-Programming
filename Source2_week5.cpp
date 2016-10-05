#define SQR(a) (a)*(a)


//#include <iostream>
#include <vector>
#include "Geometricobjects.h"

#include "Circle.h"
#include "Box.h"




#include <GLFW\glfw3.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>

GLFWwindow* window;
double win_x, win_y;

//const int width = 640;
//const int height = 480;
//const int num_lines = 3;

// color = (Red, Green, Blue)
// float* pixels = new float[width * height * 3];




//void clearBackground()
//{
//	//background cleaning
//	for (int i = 0; i < width; i++)
//		for (int j = 0; j < height; j++)
//		{
//			pixels[(i + width*j) * 3 + 0] = 1.0f;	//red
//			pixels[(i + width*j) * 3 + 1] = 1.0f;	//green
//			pixels[(i + width*j) * 3 + 2] = 1.0f;	//blue
//		}
//}
//
//void draw()
//{
//	clearBackground();
//
//}


//void drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
//{
//
//
//
//	pixels[(i + width *j) * 3 + 0] = red;
//	pixels[(i + width *j) * 3 + 1] = green;
//	pixels[(i + width *j) * 3 + 2] = blue;
//
//}




//void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
//{
//	if (i0 < i1)
//	{
//		for (int i = i0; i <= i1; i++)
//		{
//			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
//
//			drawonepixel(i, j, red, green, blue);
//		}
//	}
//	else if (i0 > i1)
//	{
//		for (int i = i1; i <= i0; i++)
//		{
//			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
//
//			drawonepixel(i, j, red, green, blue);
//		}
//	}
//	else
//	{
//		if (j0 < j1)
//		{
//			for (int j = j0; j < j1; j++)
//			{
//				drawonepixel(i0, j, red, green, blue);
//			}
//		}
//		else if (j0 > j1)
//		{
//			for (int j = j1; j < j0; j++)
//			{
//				drawonepixel(i0, j, red, green, blue);
//			}
//		}
//		else
//		{
//			drawonepixel(i0, j0, red, green, blue);
//		}
//	}
//
//
//}




//void drawrectangle(const float& red, const float& green, const float& blue)
//{
//
//	for (int i = 230; i <= 300; i++)
//	{
//		int j = 460, x = 360;
//		drawonepixel(i, j, red, green, blue);
//		drawonepixel(i, x, red, green, blue);
//	}
//
//
//	for (int j = 360; j <= 460; j++)
//	{
//		int i = 230, y = 300;
//		drawonepixel(i, j, red, green, blue);
//		drawonepixel(y, j, red, green, blue);
//	}
//
//
//
//
//
//	for (int i = 330; i <= 390; i++)
//	{
//		int j = 460, x = 360;
//
//		for (int j = 360; j <= 460; j++)
//		{
//			drawonepixel(i, j, red, green, blue);
//			//drawonepixel(i, x, red, green, blue);
//		}
//	}
//
//
//
//}


//void drawtriangle(const float& red, const float& green, const float& blue)
//{
//	const int i0 = 10, i1 = 100;
//	const int j0 = 150, j1 = 200;
//	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 1.0f);
//
//	drawLine(50, 150, i1, j1, 1.0f, 0.0f, 1.0f);
//
//	drawLine(10, 150, 50, 150, 1.0f, 0.0f, 1.0f);
//}

//void drawpentagon(const float& red, const float& green, const float& blue)
//{
//
//	drawLine(150, 150, 200, 150, 1.0f, 0.0f, 1.0f);
//
//	drawLine(130, 180, 150, 150, 1.0f, 0.0f, 1.0f);
//
//	drawLine(200, 150, 220, 180, 1.0f, 0.0f, 1.0f);
//
//
//	drawLine(130, 180, 180, 230, 1.0f, 0.0f, 1.0f);
//
//	drawLine(180, 230, 220, 180, 1.0f, 0.0f, 1.0f);
//
//
//
//}









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


	/*for (int j = 0; j < height * width; j++)
	std::cout << pixels[j] << std::endl;*/


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
	//const int i0 = 30, i1 = 200;
	//const int j0 = 400, j1 = 480;
	//drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);




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

//class GeometricObjects {
//
//public:
//
//
//	void draw() {
//
//
//		//draw objects
//		//
//		//
//
//
//	}
//
//
//};







//class Circle : public GeometricObjects
//
//
//
//{
//public:
//	int center_x_, center_y_, radius_;
//
//	Circle()
//	{}
//
//
//
//
//	Circle(const int& _x, const int& _y, const int& _r)
//		: center_x_(_x)////, y, r.......
//	{
//
//	}
//	
//
//
//	void init(const int& _x, const int& _y, const int& _r)
//	{
//
//
//	}
//
//	void draw() {
//
//		// draw this circle using center_x, center_y, radius_
//
//		std::cout << "this is a circle" << std::endl;
//
//	}
//
//
//
//};








//class Box : public GeometricObjects
//
//
//{
//	
//	
//	
//	int  bottom_left_x, bottom_left_y;// right up
//	// egdes
//
//	void draw() {
//		std::cout << "this is a box" << std::endl;
//
//	}
//};



// c- style



int main(void) {

	/*std::vector<GeometricObjects*> go_vector;

	go_vector.push_back(new Circle);
	go_vector.push_back(new Box);*/

	// triangles, polygons, diamond, rohmbus.......

	/*for (auto itr : go_vector)
		(itr)->draw();*/



	


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

		Circle *my_circle = new Circle();
		my_circle->draw();

		/*for (int i = 0; i < go_vector.size(); i++)
			go_vector[i]->draw();*/

		/*Box* b = new Box;
		b->draw();*/

		//GeometricObjects* go = new GeometricObjects;

		

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels;

	return 0;







	/*GeometricObjects  *my_circle = new Circle(100,100,10);

	GeometricObjects  *my_box = new Box;

	my_circle->draw();
	my_box->draw();
*/








	//// c -style



	////oop style

	//Circle my_circle;

	////my_circle.center_x_ =10;
	////my_circle.center_y_= 20 ;
	////my_circle.radius_ = 30 ;


	//my_circle.drawcircle();


	////pointer
	//Circle * my_circle_ptr = nullptr;
	////in old style, my_circle_ptr = 0;

	//if (my_circle_ptr != nullptr)
	//	my_circle_ptr = new Circle(100, 100, 10);


	////// after using my_circle
	//my_circle_ptr->drawcircle();




	////
	//if (my_circle_ptr != nullptr)
	//	delete my_circle_ptr;


	//system("pause");

}




////glDrawPixels(window_width, window_height, GL_RGB, GL_FLOAT, pixels);
//
//
//#include<iostream>
//
//using namespace std;
//
////void main()
////{
////	cout << "hello world" << endl;
////
////
////	system("pause");
////
////}
//// this example is fro  from   http://www.glfw.org/documentation.html
//#include <GLFW/glfw3.h>
//
//
//const int width = 640;
//const int height = 480;
//
//
//////color = (R,G,b)
//////dynamic memory allocation
//float *pixels = new  float[width * height * 3];
//////float *pixels = (float *) malloc(sizeof(float)*width*heght*3)
////
////
//////draw a line
////
////
////draw
//void drawonepixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
//{
//
//
//
//	pixels[(i + width *j) * 3 + 0] = red;
//	pixels[(i + width *j) * 3 + 1] = green;
//	pixels[(i + width *j) * 3 + 2] = blue;
//
//}
//
//
//
////
////float* pixels = new float[width*height * 3];
////
////void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
////{
////	pixels[(i + width* j) * 3 + 0] = red;
////	pixels[(i + width* j) * 3 + 1] = green;
////	pixels[(i + width* j) * 3 + 2] = blue;
////}
////
//void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
//{
//	for (int i = i0; i <= i1; i++)
//	{
//		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
//		//int x = i+1, y= j+1;
//
//		drawonepixel(i, j, red, green, blue);
//		//drawonepixel(x, y, red, green, blue);
//	}
//}
//
//
//void drawrectangle(const float& red, const float& green, const float& blue)
//{
//
//	for (int i = 230; i <= 300; i++)
//	{
//		int j = 460, x = 360;
//		drawonepixel(i, j, red, green, blue);
//		drawonepixel(i, x, red, green, blue);
//	}
//
//
//	for (int j = 360; j <= 460; j++)
//	{
//		int i = 230, y = 300;
//		drawonepixel(i, j, red, green, blue);
//		drawonepixel(y, j, red, green, blue);
//	}
//
//
//
//
//
//	for (int i = 330; i <= 390; i++)
//	{
//		int j = 460, x = 360;
//
//		for (int j = 360; j <= 460; j++)
//		{
//			drawonepixel(i, j, red, green, blue);
//			//drawonepixel(i, x, red, green, blue);
//		}
//	}
//
//
//
//}
//
//
//void drawtriangle(const float& red, const float& green, const float& blue)
//{
//	const int i0 = 10, i1 = 100;
//	const int j0 = 150, j1 = 200;
//	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 1.0f);
//
//	drawLine(50, 150, i1, j1, 1.0f, 0.0f, 1.0f);
//
//	drawLine(10, 150, 50, 150, 1.0f, 0.0f, 1.0f);
//}
//
//void drawpentagon(const float& red, const float& green, const float& blue)
//{
//
//	drawLine(150, 150, 200, 150, 1.0f, 0.0f, 1.0f);
//
//	drawLine(130, 180, 150, 150, 1.0f, 0.0f, 1.0f);
//
//	drawLine(200, 150, 220, 180, 1.0f, 0.0f, 1.0f);
//
//
//	drawLine(130, 180, 180, 230, 1.0f, 0.0f, 1.0f);
//
//	drawLine(180, 230, 220, 180, 1.0f, 0.0f, 1.0f);
//
//
//
//}
//
//
//void draw()
//{
//
//
//	//white background(1.0,1.0,1.0)
//	//let assign all pixels red color
//
//	for (int j = 0; j < height; j++)
//		for (int i = 0; i < width; i++)
//		{
//			pixels[(i + width *j) * 3 + 0] = 1.0f;
//			pixels[(i + width *j) * 3 + 1] = 1.0f;
//			pixels[(i + width *j) * 3 + 2] = 1.0f;
//
//		}
//
//
//
//
//	const int i_center = 50, j_center = 50;
//	const int thickness = 5;
//
//	for (int j = j_center - thickness; j < j_center + thickness; j++)
//		for (int i = i_center - thickness; i < i_center + thickness; i++)
//		{
//			drawonepixel(i, j, 1.0f, 0.0f, 0.0f);
//
//		}
//
//	drawonepixel(10, 10, 600, 300, 0.0f);
//
//	// drawing a line
//	// drawing a line
//	//TODO: anti-aliasing
//	const int i0 = 30, i1 = 200;
//	const int j0 = 400, j1 = 480;
//	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);
//
//
//
//
//	drawrectangle(1.0f, 0.0f, 0.0f);
//
//	drawtriangle(1.0f, 0.0f, 1.0f);
//
//	drawpentagon(1.0f, 0.0f, 1.0f);
//
//}
//
//
//
//
//int main(void)
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	/* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(window))
//	{
//		/* Render here */
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//
//
//
//
//		draw();
//		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//
//	//
//	delete[] pixels;
//	//free(pixels); in c
//	return 0;
//}
