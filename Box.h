#pragma once
#include <iostream>
#include "Geometricobjects.h"




class Box : public Geometricobjects
{

public:
	void draw(); // declaration  - definition (header , body)
	void drawrectangle(const float& red, const float& green, const float& blue);
};