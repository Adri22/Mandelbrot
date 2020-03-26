#include "Frame.h"

Frame::Frame(const char* title, int x, int y, int width, int height, bool fullscreen) {
	dimension = { width, height };

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(
			title,
			x, y,
			dimension.width, dimension.height,
			fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	} else {
		isRunning = false;
	}
}

Frame::~Frame() {
	delete window;
	delete renderer;
}

void Frame::HandleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		std::cout << "event type: " << event.type << std::endl;

		switch (event.type) {
			// case SDL_KEYDOWN:
			case SDL_QUIT:
				isRunning = false;
				break;
			default: break;
		}
	}
}

void Frame::Update() {}

void Frame::Render() {
	SDL_RenderClear(renderer);
	// render everything here
	SDL_RenderPresent(renderer);
}

void Frame::Quit() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}