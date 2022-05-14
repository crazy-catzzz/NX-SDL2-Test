#include "../include/graphics.h"

void graphics_init(graphics& gfx, color bgColor) {
    gfx.win = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!gfx.win) SDL_Quit();

    gfx.rend = SDL_CreateRenderer(gfx.win, -1, SDL_RENDERER_SOFTWARE);
    if (!gfx.rend) SDL_Quit();

    gfx.scr = SDL_GetWindowSurface(gfx.win);

    gfx.bg = bgColor;
}
void graphics_deinit(graphics& gfx) {
    SDL_FreeSurface(gfx.scr);
    
    SDL_DestroyRenderer(gfx.rend);
    
    SDL_DestroyWindow(gfx.win);
}

void init_rect(SDL_Rect& rect, int x, int y, int w, int h) {
    rect.h = h;
    rect.w = w;
    rect.x = x;
    rect.y = y;
}
void graphics_drawRectBorder(graphics& gfx, color color, SDL_Rect* rect) {
    SDL_SetRenderDrawColor(gfx.rend, color.r, color.g, color.b, color.a);
    
    SDL_RenderDrawRect(gfx.rend, rect);

    SDL_SetRenderDrawColor(gfx.rend, gfx.bg.r, gfx.bg.g, gfx.bg.b, gfx.bg.a);
}
void graphics_drawRectFill(graphics& gfx, color color, SDL_Rect* rect) {
    SDL_SetRenderDrawColor(gfx.rend, color.r, color.g, color.b, color.a);
    
    SDL_RenderDrawRect(gfx.rend, rect);
    SDL_RenderFillRect(gfx.rend, rect);
    
    SDL_SetRenderDrawColor(gfx.rend, gfx.bg.r, gfx.bg.g, gfx.bg.b, gfx.bg.a);
}