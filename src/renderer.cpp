//
// Created by dinis on 14.06.2025.
//

#include "../include/renderer.h"
#include <cmath>
#include <SDL3/SDL.h>
#include "color.cpp"
#include <iostream>
using namespace std;

class Camera {
public:
    float center_x, center_y, center_z;

    Camera(float x, float y, float z): center_x(x), center_y(y), center_z(z){}
};

class Viewport {
public:
    float v_w;
    float v_h;
    float d;

    Viewport(float w, float h, float d): v_w(w), v_h(h), d(d){}

    void pixelToViewport(int c_w, int c_h, int c_x, int c_y) { // TODO: Introduce 2D and 3D points struct
        float v_x = c_x * (v_w / c_w);
        float v_y = c_y * (v_h / c_h);
        float v_z = d;
    }
};



class Canvas {
public:
    // Internals
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Properties
    int c_w;
    int c_h;
    Color* pixels;

    Canvas(int w, int h): c_w(w), c_h(h) {
        pixels = new Color[c_w * c_h]();
    }

    bool initWindow() {
        SDL_SetAppMetadata("Yet Another Renderer", "1.0", "diniscanastro.yer");

        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
            return false;
        }

        if (!SDL_CreateWindowAndRenderer("Yet Another Renderer", c_w, c_h, 0, &window, &renderer)) {
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
        for (int i = 0; i < c_h * c_w; i++) {
            SDL_SetRenderDrawColor(renderer, pixels[i].r, pixels[i].g, pixels[i].b, SDL_ALPHA_OPAQUE);
            int x = i % c_w;
            int y = floor(i / c_w);
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
        int real_x = x + c_w / 2;
        int real_y = - y + c_h / 2;
        pixels[real_y * c_w + real_x] = c;
    }
};
