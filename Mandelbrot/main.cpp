#include "Frame.h"
#include "RenderHandler.h"

Frame* frame = nullptr;
RenderHandler* renderHandler = nullptr;

int main(int argc, char* argv[]) {
	frame = new Frame(
		"Mandelbrot",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, // make window-size changeable?
		false);

	renderHandler = new RenderHandler(frame);

	while(frame->IsOpen()) {
		frame->HandleEvents();
		frame->Update();
	}

	frame->Quit();
	// delete frame;
	// delete renderHandler;

	return 0;
}