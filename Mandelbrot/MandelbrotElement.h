#pragma once

#include "SDL.h"
#include "Geometry.h"
#include <iostream>
#include <complex>
#include <cmath>

using namespace std::complex_literals;

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
	std::complex<double> iterateValue;
	std::complex<double> c;
	Color color;
	void Iterate(std::complex<double> value);
	void SetColor();
};