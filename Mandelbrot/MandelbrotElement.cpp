#include "MandelbrotElement.h"

MandelbrotElement::MandelbrotElement(Point coordinate) {
	MandelbrotElement::coordinate = coordinate;
	iterations = 0;
	iterateValue = 0;
	color = {0, 0, 0};
	// Iterate(iterateValue);
}

MandelbrotElement::~MandelbrotElement() {}

void MandelbrotElement::Draw(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

Point MandelbrotElement::GetCoordinate() {
	return coordinate;
}

void MandelbrotElement::Iterate(double value) {
	// iterateValue = // calculate here and break
	iterations++;
	Iterate(iterateValue);
}