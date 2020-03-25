#pragma once

#include "SDL.h"

class Frame {

public:
	Frame();
	~Frame();
	void Initialize(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Quit();
	bool IsOpen() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};