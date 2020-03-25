#include "Frame.h"

Frame* frame = nullptr;

int main(int argc, char* argv[]) {
	frame = new Frame();

	while (frame->IsOpen()) {
		frame->HandleEvents();
		frame->Update();
		frame->Render();
	}

	frame->Quit();
	// delete frame;

	return 0;
}