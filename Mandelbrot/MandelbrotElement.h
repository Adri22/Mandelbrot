#pragma once

#include "SDL.h"
#include "Geometry.h"
#include <complex>
#include <cmath>

struct Color {
	int r, g, b;
};

class MandelbrotElement {

public:
	MandelbrotElement(Point coordinate);
	~MandelbrotElement();
	void Draw(SDL_Renderer* renderer, int x, int y);
	Point GetCoordinate();

private:
	Point coordinate;
	int iterations;
	double iterateValue;
	Color color;
	void Iterate(double value);
};