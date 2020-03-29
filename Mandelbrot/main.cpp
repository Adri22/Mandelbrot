#include "Frame.h"

Frame* frame = nullptr;

int main(int argc, char* argv[]) {
	frame = new Frame(
		"Mandelbrot",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		false);

	while(frame->IsOpen()) {
		frame->HandleEvents();
		frame->Update();
	}

	frame->Quit();
	// delete frame;

	return 0;
}