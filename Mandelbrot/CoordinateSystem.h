#pragma once

#include "SDL.h"
#include "Geometry.h"
#include <iostream>

class CoordinateSystem {

public:
	CoordinateSystem(Dimension d);
	~CoordinateSystem();
	void Draw(SDL_Renderer* renderer);
	Point GetOrigin();

private:
	Line* xAxis;
	Line* yAxis;
	Point coordinateOrigin;
	void DrawAxis(SDL_Renderer* renderer);
};