#pragma once

#include "SDL.h"
#include <iostream>

struct Point {
	int x, y;
};

struct Axis {

public:
	Axis(int xStart, int yStart, int xEnd, int yEnd) {
		start = {xStart, yStart};
		end = {xEnd, yEnd};
	}

	Point GetStartPoint() {
		return start;
	}

	Point GetEndPoint() {
		return end;
	}

private:
	Point start, end;
};

class CoordinateSystem {

public:
	CoordinateSystem(int frameWidth, int frameHeight);
	~CoordinateSystem();
	void Draw(SDL_Renderer* renderer);

private:
	void DrawAxis(SDL_Renderer* renderer);
	Axis* xAxis;
	Axis* yAxis;
	Point coordinateOrigin;
};