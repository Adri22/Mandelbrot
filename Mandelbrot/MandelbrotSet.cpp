#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(Point origin) {
	MandelbrotSet::origin = origin;
	elements = new std::list<MandelbrotElement>;
	accuracy = 0.001;

	for(float x = -1; x <= 1; x += accuracy) {
		for(float y = -1; y <= 1; y += accuracy) {
			elements->push_front(*new MandelbrotElement({x, y}));
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