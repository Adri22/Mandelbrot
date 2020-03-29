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
		renderHandler = new RenderHandler(window);
		coordinateSystem = new CoordinateSystem(dimension);
		mandelbrotset = new MandelbrotSet(coordinateSystem->GetOrigin());
	} else {
		isRunning = false;
	}
}

Frame::~Frame() {
	delete window;
	delete renderHandler;
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

void Frame::Update() {
	renderHandler->StillRunning(isRunning);
	// update stuff here
}

void Frame::Quit() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}