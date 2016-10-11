#pragma once
#include <GLFW\glfw3.h>
#include <iostream>




class Mypointer2D {

public:

	GLFWwindow* window;


	const int width = 640;
	const int height = 480;



	Mypointer2D() 
		: window(nullptr), width(600)//,height(480)
	{




	}

	Mypointer2D()  //destructor
	{
		std::cout << "The destructor of Mypointer2D" << std::endl;

	}



	void clearwindow() {

		//white background(1.0,1.0,1.0)
		//let assign all pixels red color
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++)
			{
				pixels[(i + width *j) * 3 + 0] = 1.0f;
				pixels[(i + width *j) * 3 + 1] = 1.0f;
				pixels[(i + width *j) * 3 + 2] = 1.0f;
			}
	}





	void preprocessing()
	{


	}


	void postprocessing()
	{
	
	
	}


};
