#pragma once

#include "SDL.h"
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
	void Render(SDL_Renderer* renderer);
	void Quit();
	bool IsOpen() { return isRunning; }
	SDL_Window* getWindow() { return window; }
	Dimension getDimension() { return dimension; };

private:
	bool isRunning;
	SDL_Window* window;
	Dimension dimension;
	CoordinateSystem* coordinateSystem;
	MandelbrotSet* mandelbrotset;
};