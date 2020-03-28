#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(Point origin) {
	MandelbrotSet::origin = origin;
	elements = new std::list<MandelbrotElement>;

	for(int x = -50; x <= 50; x++) {
		for(int y = -50; y <= 50; y++) {
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
		iterator->Draw(renderer,
					   origin.x + iterator->GetCoordinate().x,
					   origin.y + iterator->GetCoordinate().y);
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