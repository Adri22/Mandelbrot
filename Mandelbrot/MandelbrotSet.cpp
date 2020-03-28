#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet() {
	elements = new std::list<MandelbrotElement>;
	// fill list here
}

MandelbrotSet::~MandelbrotSet() {
	delete elements;
}

void MandelbrotSet::Draw(SDL_Renderer* renderer) {
	std::list<MandelbrotElement>::iterator iterator = elements->begin();
	while(iterator != elements->end()) {
		iterator->Draw(renderer);
		iterator++;
	}
}