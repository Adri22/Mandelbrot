#pragma once

#include "SDL.h"
#include "MandelbrotElement.h"
#include <iostream>
#include <list>
#include <iterator>

class MandelbrotSet {

public:
	MandelbrotSet();
	~MandelbrotSet();
	void Draw(SDL_Renderer* renderer);

private:
	std::list<MandelbrotElement>* elements;
};