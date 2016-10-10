#define SQR(a) (a)*(a)


//#include <iostream>
#include <vector>
#include "Geometricobjects.h"






#include <GLFW\glfw3.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>

GLFWwindow* window;
double win_x, win_y;





Geometricobjects  **my_objects = new Geometricobjects*[6];

std::vector<Geometricobjects*> go_vector;

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


	for (auto itr : go_vector)
	(itr)->draw();


	//single loop for all the objects in child classes.
	/*for (int i = 0; i<5; i++)
		my_objects[i]->draw();*/
}

	int main(void) {
		go_vector.push_back(
			Geometricobjects::createGeometricObjects(std::string("Circle")));
		go_vector.push_back(
			Geometricobjects::createGeometricObjects(std::string("Line")));
		go_vector.push_back(
			Geometricobjects::createGeometricObjects(std::string("Triangle")));
		go_vector.push_back(
			Geometricobjects::createGeometricObjects(std::string("Box")));
		go_vector.push_back(
			Geometricobjects::createGeometricObjects(std::string("Polygon")));






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



