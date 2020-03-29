#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem(Dimension d) {
	coordinateOrigin = {(float)d.width / 2, (float)d.height / 2};
	xAxis = new Line(0, coordinateOrigin.y, d.width, coordinateOrigin.y);
	yAxis = new Line(coordinateOrigin.x, 0, coordinateOrigin.x, d.height);
}

CoordinateSystem::~CoordinateSystem() {
	delete xAxis;
	delete yAxis;
}

void CoordinateSystem::Draw(SDL_Renderer* renderer) {
	DrawAxis(renderer);
}

Point CoordinateSystem::GetOrigin() {
	return coordinateOrigin;
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