//
// Created by dinis on 16.06.2025.
//

#include "../include/canvas.h"
#include "../include/color.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <cmath>


class Canvas {
public:
    // Internals
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Properties
    int width;
    int height;
    Color *pixels;

    Canvas(int w, int h): width(w), height(h) {
        pixels = new Color[width * height]();
    }

    bool initWindow() {
        SDL_SetAppMetadata("Yet Another Renderer", "1.0", "diniscanastro.yer");

        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
            return false;
        }

        if (!SDL_CreateWindowAndRenderer("Yet Another Renderer", width, height, 0, &window, &renderer)) {
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
        for (int i = 0; i < height * width; i++) {
            SDL_SetRenderDrawColor(renderer, pixels[i].r, pixels[i].g, pixels[i].b, SDL_ALPHA_OPAQUE);
            int x = i % width;
            int y = floor(i / width);
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
        int real_x = x + width / 2;
        int real_y = -y + height / 2;
        pixels[real_y * width + real_x] = c;
    }
};
