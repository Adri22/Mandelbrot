#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem(int frameWidth, int frameHeight) {
	coordinateOrigin = {frameWidth / 2, frameHeight / 2};
	xAxis = new Axis(0, coordinateOrigin.y, frameWidth, coordinateOrigin.y);
	yAxis = new Axis(coordinateOrigin.x, 0, coordinateOrigin.x, frameHeight);
}

CoordinateSystem::~CoordinateSystem() {}

void CoordinateSystem::Draw(SDL_Renderer* renderer) {
	DrawAxis(renderer);
}

void CoordinateSystem::DrawAxis(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// SDL_RenderSetScale(renderer, 0.1, 0.1);
	SDL_RenderDrawLine(renderer,
					   xAxis->GetStartPoint().x,
					   xAxis->GetStartPoint().y,
					   xAxis->GetEndPoint().x,
					   xAxis->GetEndPoint().y);
	SDL_RenderDrawLine(renderer,
					   yAxis->GetStartPoint().x,
					   yAxis->GetStartPoint().y,
					   yAxis->GetEndPoint().x,
					   yAxis->GetEndPoint().y);
}