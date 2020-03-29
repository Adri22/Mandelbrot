#pragma once

#include "SDL.h"
#include "RenderHandler.h"
#include "CoordinateSystem.h"
#include "MandelbrotSet.h"
#include "Geometry.h"
#include <iostream>

class Frame {

public:
	Frame(const char* title, int x, int y, int width, int height, bool fullscreen);
	~Frame();
	void HandleEvents();
	void Update();
	void Quit();
	bool IsOpen() { return isRunning; }
	Dimension getDimension() { return dimension; };

private:
	bool isRunning;
	SDL_Window* window;
	RenderHandler* renderHandler;
	Dimension dimension;
	CoordinateSystem* coordinateSystem;
	MandelbrotSet* mandelbrotset;
};