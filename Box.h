#pragma once
#include <iostream>
#include "GeometricObjects.h"




class Box : public GeometricObjects
{

public:
	void draw(); // declaration  - definition (header , body)
	void drawrectangle(const float& red, const float& green, const float& blue);
};