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



void draw()
{


	//white background(1.0,1.0,1.0)


	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			pixels[(i + width *j) * 3 + 0] = 1.0f;
			pixels[(i + width *j) * 3 + 1] = 1.0f;
			pixels[(i + width *j) * 3 + 2] = 1.0f;

		}
}



GeometricObjects  **my_objects = new GeometricObjects*[6];



	int main(void) {


		my_objects[0] = new Line();
		my_objects[1] = new Circle();
		my_objects[2] = new Box();
		my_objects[3] = new Triangle();
		my_objects[4] = new Polygon();




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



