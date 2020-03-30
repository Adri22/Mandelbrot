#pragma once

#include "SDL.h"
#include "Frame.h"
#include <iostream>
#include <thread>

class RenderHandler {

public:
	RenderHandler(Frame* f);
	~RenderHandler();

private:
	Frame* frame;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_GLContext glContext;
	void RenderProcess();
};