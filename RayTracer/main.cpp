#include "Renderer.h"
#include "Sphere.h"
#include "Scene.h"
#include "Camera.h"
#include <iostream>

int main(int, char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(600, 300);

	Canvas canvas(600, 300, renderer);
	Camera camera(glm::vec3{ 1, 1, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 90.0f, 600 / (float)300);
	Scene scene;

	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1, 0, -1 }, 0.2f, std::make_unique<Lambertian>(color3{ 1, 1, 0 })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.3f, 0, 0.3f })));

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
		renderer.Render(canvas, scene, camera);
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	renderer.Shutdown();

	return 0;
}