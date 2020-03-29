#include "RenderHandler.h"

RenderHandler::RenderHandler(SDL_Window* window) {
	running = false;
	RenderHandler::window = window;
	renderer = nullptr;
	glContext = SDL_GL_GetCurrentContext();
	SDL_GL_MakeCurrent(window, nullptr);
	std::thread thread(&RenderHandler::RenderProcess, this);
	thread.detach();
}

RenderHandler::~RenderHandler() {
	// delete window;
	// delete renderer;
	SDL_DestroyRenderer(renderer);
}

/*
template<typename Function>
void Test(Function function) {
	function();
}
*/

void RenderHandler::RenderProcess() {
	SDL_GL_MakeCurrent(window, glContext);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while(running) {
		if(renderer != nullptr) {
			Render();
		}
	}
}

void RenderHandler::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // move into Draw()-Functions?
	// coordinateSystem->Draw(renderer);
	// mandelbrotset->Draw(renderer);
	SDL_RenderPresent(renderer);
}