#pragma once

#include "SDL.h"

struct Point {
	int x, y;
};

struct Color {
	int r, g, b;
};

class MandelbrotElement {

public:
	MandelbrotElement();
	~MandelbrotElement();
	void Draw(SDL_Renderer* renderer);

private:
	Point coordinates;
	int iterations;
	Color color;
};