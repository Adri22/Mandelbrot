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

	if(std::abs(iterateValue) > 2 || iterations == maxIterations) {
		SetColor();
	} else {
		Iterate(iterateValue);
	}
}

void MandelbrotElement::SetColor() {

	if(iterations == maxIterations) {
		color = {0, 0, 0};
	} else {
		int brightness =
			256. * log2(1.75 + iterations - log2(log2(std::abs(iterateValue)))) /
			log2(double(maxIterations));
		color = {brightness, brightness, 255};
	}
}