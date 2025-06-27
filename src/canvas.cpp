#include "../include/canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height): width(width), height(height) {
    pixels = new Color[width * height]();
    SDL_SetAppMetadata("Yet Another Renderer", "1.0", "diniscanastro.yer");
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
    }

    if (!SDL_CreateWindowAndRenderer("Yet Another Renderer", width, height, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    }
}

bool Canvas::pollExit() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                return false;
        }
    }
    return true;
}

void Canvas::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Background
    SDL_RenderClear(renderer);
    for (int i = 0; i < height * width; i++) {
        SDL_SetRenderDrawColor(renderer, pixels[i].r, pixels[i].g, pixels[i].b, SDL_ALPHA_OPAQUE);
        int x = i % width;
        int y = floor(i / width);
        SDL_RenderPoint(renderer, x, y);
    }
    SDL_RenderPresent(renderer);
}

void Canvas::destroy() {
    free(pixels);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Canvas::putPixel(int x, int y, Color color) {
    int real_x = x + width / 2;
    int real_y = -y + height / 2;
    pixels[real_y * width + real_x] = color;
}
