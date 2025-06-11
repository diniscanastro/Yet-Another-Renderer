#include <SDL3/SDL.h>
#include "color.cpp"
#include <iostream>
using namespace std;

class Canvas {
public:
	// Internals
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	// Properties
	int canvas_width;
	int canvas_height;
	Color* pixels;

	Canvas(int width, int height): canvas_width(width), canvas_height(height) {
		pixels = new Color[canvas_width * canvas_height]();
	}

	bool initWindow() {
		SDL_SetAppMetadata("Yet Another Renderer", "1.0", "diniscanastro.yer");

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
			return false;
		}

		if (!SDL_CreateWindowAndRenderer("Yet Another Renderer", canvas_width, canvas_height, 0, &window, &renderer)) {
			SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
			return false;
		}

		return true;
	}

	bool pollExit() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_EVENT_QUIT:
				return false;
			}
		}
		return true;
	}

	void render() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Background
		SDL_RenderClear(renderer);
		for (int i = 0; i < canvas_height * canvas_width; i++) {
			SDL_SetRenderDrawColor(renderer, pixels[i].r, pixels[i].g, pixels[i].b, SDL_ALPHA_OPAQUE);
			int x = i % canvas_width;
			int y = floor(i / canvas_width);
			SDL_RenderPoint(renderer, x, y);
		}
		SDL_RenderPresent(renderer);
	}

	void destroy() {
		free(pixels);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void putPixel(int x, int y, Color c) {
		int real_x = x + canvas_width / 2;
		int real_y = - y + canvas_height / 2;
		pixels[real_y * canvas_width + real_x] = c;
	}
};