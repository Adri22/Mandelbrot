#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(Point origin) {
	MandelbrotSet::origin = origin;
	elements = new std::list<MandelbrotElement>;
	accuracy = 0.01;

	for(double x = -2; x <= 2; x += accuracy) { // make bounds dynamic?
		for(double y = -2; y <= 2; y += accuracy) {
			elements->push_front(*new MandelbrotElement({x, y})); // bad_alloc - change to x64 runtime configuration
		}
	}
}

MandelbrotSet::~MandelbrotSet() {
	ClearList();
	delete elements;
}

void MandelbrotSet::Draw(SDL_Renderer* renderer) {
	std::list<MandelbrotElement>::iterator iterator = elements->begin();
	while(iterator != elements->end()) {
		// std::cout << "x: " << iterator->GetCoordinate().x << " y: " << iterator->GetCoordinate().y << std::endl;
		iterator->Draw(renderer,
					   origin.x + iterator->GetCoordinate().x / accuracy,
					   origin.y + iterator->GetCoordinate().y / accuracy);
		iterator++;
	}
}

void MandelbrotSet::ClearList() {
	std::list<MandelbrotElement>::iterator iterator = elements->begin();
	while(iterator != elements->end()) {
		// elements->remove(*iterator); // wtf?!
		delete& iterator;
		iterator++;
	}
}