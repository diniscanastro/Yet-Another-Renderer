#ifndef CANVAS_H
#define CANVAS_H

#include <SDL3/SDL.h>
#include "canvas.h"
#include "color.h"

class Canvas {
public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int width, height;
    Color *pixels;

    Canvas(int width, int height);

    bool pollExit();
    void render();
    void destroy();
    void putPixel(int x, int y, Color color);
};

#endif //CANVAS_H
