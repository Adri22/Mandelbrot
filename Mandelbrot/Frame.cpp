#include "Frame.h"

Frame::Frame(const char* title, int x, int y, int width, int height, bool fullscreen) {
	dimension = {width, height};

	if(!SDL_Init(SDL_INIT_EVERYTHING)) {
		window = SDL_CreateWindow(
			title,
			x, y,
			dimension.width, dimension.height,
			fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		isRunning = true;
		coordinateSystem = new CoordinateSystem(dimension);
		mandelbrotset = new MandelbrotSet(coordinateSystem->GetOrigin());
	} else {
		isRunning = false;
	}
}

Frame::~Frame() {
	delete window;
	delete coordinateSystem;
	delete mandelbrotset;
}

void Frame::HandleEvents() {
	SDL_Event event;

	SDL_PollEvent(&event);
	// std::cout << "event type: " << event.type << std::endl;

	switch(event.type) {
		case SDL_QUIT:
			isRunning = false;
		case SDL_KEYDOWN:
			if(!(event.key.keysym.scancode == SDL_GetScancodeFromKey(SDLK_ESCAPE))) {
				break;
			}
			isRunning = false;
			break;
		default: break;
	}
}

void Frame::Update() {} // update stuff here 

void Frame::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // move into Draw()-Functions?
	coordinateSystem->Draw(renderer);
	mandelbrotset->Draw(renderer);
	SDL_RenderPresent(renderer);
}

void Frame::Quit() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}