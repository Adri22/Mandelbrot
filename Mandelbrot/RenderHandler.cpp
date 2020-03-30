#include "RenderHandler.h"

RenderHandler::RenderHandler(Frame* f) {
	frame = f;
	window = frame->getWindow();
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

void RenderHandler::RenderProcess() {
	SDL_GL_MakeCurrent(window, glContext);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while(frame->IsOpen()) {
		if(renderer != nullptr) {
			frame->Render(renderer);
		}
	}
}