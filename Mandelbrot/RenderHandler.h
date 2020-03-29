#pragma once

#include "SDL.h"
#include <iostream>
#include <thread>

class RenderHandler {

public:
	RenderHandler(SDL_Window* window);
	~RenderHandler();
	void StillRunning(bool running) { RenderHandler::running = running; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_GLContext glContext;
	bool running;
	void RenderProcess();
	void Render();
};