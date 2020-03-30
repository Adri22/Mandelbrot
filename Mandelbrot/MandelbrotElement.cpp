#include "MandelbrotElement.h"

MandelbrotElement::MandelbrotElement(Point coordinate) {
	MandelbrotElement::coordinate = coordinate;
	iterations = 0;
	iterateValue = 0;
	c.real(coordinate.x);
	c.imag(coordinate.y);
	color = {0, 0, 0};
	Iterate(iterateValue);
}

MandelbrotElement::~MandelbrotElement() {}

void MandelbrotElement::Draw(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

Point MandelbrotElement::GetCoordinate() {
	return coordinate;
}

void MandelbrotElement::Iterate(std::complex<double> value) {
	// std::cout << "coordinate: " << coordinate.x << "/" << coordinate.y;
	// std::cout << " - iterateValue: " << iterateValue << std::endl;
	iterateValue = std::pow(value, 2) + c;
	iterations++;

	if(std::abs(iterateValue) > 2 || /*this is shit*/ iterations > 10) { // temp, add exception-handling
		SetColor();
	} else {
		Iterate(iterateValue);
	}
}

void MandelbrotElement::SetColor() {

	switch(iterations) { // ugly
		case 11:
			color = {0, 0, 0};
			break;
		case 10:
			color = {100, 100, 100};
			break;
		case 9:
			color = {150, 150, 150};
			break;
		case 8:
			color = {120, 0, 30};
			break;
		case 7:
			color = {30, 220, 10};
			break;
		case 6:
			color = {10, 110, 255};
			break;
		case 5:
			color = {20, 255, 130};
			break;
		case 4:
			color = {140, 250, 50};
			break;
		case 3:
			color = {250, 40, 40};
			break;
		case 2:
			color = {255, 60, 70};
			break;
		case 1:
			color = {255, 255, 255};
			break;
		default:
			break;
	}
}