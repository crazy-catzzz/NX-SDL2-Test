#pragma once

#include <SDL2/SDL.h>

struct color {  // Color structure
    uint8_t r;  // red
    uint8_t g;  // green
    uint8_t b;  // blue
    uint8_t a;  // alpha
};

// Color constants
const color RED     = { 255, 0, 0, 255 };       // RGBA:   255, 0, 0, 255
const color GREEN   = { 0, 255, 0, 255 };       // RGBA:   0, 255, 0, 255
const color BLUE    = { 0, 0, 255, 255 };       // RGBA:   0, 0, 255, 255
const color BLACK   = { 0, 0, 0, 255 };         // RGBA:   0, 0, 0, 255
const color WHITE   = { 255, 255, 255, 255 };   // RGBA:   255, 255, 255, 255

struct graphics {
    // SDL WINDOW
    SDL_Window* win;

    // SDL RENDERER
    SDL_Renderer* rend;

    // SDL SURFACE
    SDL_Surface* scr;

    // BACKGROUND / BASE COLOR
    color bg;
};
void graphics_init(graphics& gfx, color bgColor);
void graphics_deinit(graphics& gfx);

void graphics_drawRectBorder(graphics& gfx, color color, SDL_Rect* rect);
void graphics_drawRectFill(graphics&gfx, color color, SDL_Rect* rect);
void init_rect(SDL_Rect& rect, int x, int y, int w, int h);