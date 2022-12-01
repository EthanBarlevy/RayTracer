#include "Renderer.h"
#include <iostream>

int main(int, char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(600, 400);

	Canvas canvas(600, 400, renderer);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		// render things
		canvas.Clear({0, 0, 0, 1});
		for (int i = 0; i < 50000; i++)
		{
			canvas.DrawPoint({ Random(0, 600), Random(0, 400) }, {1, 1, 1, 0});
		}
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	renderer.Shutdown();

	return 0;
}