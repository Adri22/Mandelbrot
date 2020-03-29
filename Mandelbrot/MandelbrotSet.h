#pragma once

#include "SDL.h"
#include "MandelbrotElement.h"
#include "Geometry.h"
#include <iostream>
#include <list>
#include <iterator>

class MandelbrotSet {

public:
	MandelbrotSet(Point origin);
	~MandelbrotSet();
	void Draw(SDL_Renderer* renderer);

private:
	Point origin;
	std::list<MandelbrotElement>* elements;
	float accuracy;
	void ClearList();
};