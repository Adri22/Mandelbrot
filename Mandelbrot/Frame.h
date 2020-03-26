#pragma once

#include "SDL.h"
#include <iostream>

struct Dimension {
	int width;
	int height;
};

class Frame {

public:
	Frame(const char* title, int x, int y, int width, int height, bool fullscreen);
	~Frame();
	void HandleEvents();
	void Update();
	void Render();
	void Quit();
	bool IsOpen() { return isRunning; }
	Dimension getDimension() { return dimension; };

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Dimension dimension;
};