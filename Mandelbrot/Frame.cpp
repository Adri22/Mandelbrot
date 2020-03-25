#include "Frame.h"

Frame::Frame() {
	isRunning = NULL;
	window = NULL;
	renderer = NULL;

	Initialize(
		"Mandelbrot",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		false
		);
}

Frame::~Frame() {
	delete window;
	delete renderer;
}

void Frame::Initialize(const char* title, int x, int y, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, x, y, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	} else {
		isRunning = false;
	}
}

void Frame::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default: break;
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