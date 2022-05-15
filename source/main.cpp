#include <iostream>

#include <SDL2/SDL.h>
#include <switch.h>

#include <unistd.h>

#include "../include/nxlink.h"
#include "../include/graphics.h"
#include "../include/input.h"

bool run;
graphics gfx;
input in;

void init() {
    run = true;
    nxlink_init();
    init_input(in, 1);
    SDL_Init(SDL_INIT_EVERYTHING); // INIT SDL
    graphics_init(gfx, BLACK);
}
void deinit() {
    graphics_deinit(gfx);
    nxlink_deinit();
    SDL_Quit();
}

int main(int argc, char** argv) {

    init();

    SDL_SetRenderDrawColor(gfx.rend, 255, 255, 255, 255);

    SDL_Rect rects[2];
    init_rect(rects[0], 10, 10, 1260, 700);
    init_rect(rects[1], 200, 200, 600, 600);

    while(run) {

        in.current_button = getInput(in);
        if (in.current_button != -1) {
            if (in.current_button == 10) run = false;

            if (in.current_button == 12) rects[1].x -= 10;
            if (in.current_button == 13) rects[1].y -= 10;
            if (in.current_button == 14) rects[1].x += 10;
            if (in.current_button == 15) rects[1].y += 10;
        }

        graphics_drawRectBorder(gfx, WHITE, &rects[0]);
        graphics_drawRectBorder(gfx, RED, &rects[1]);

        SDL_SetRenderDrawColor(gfx.rend, gfx.bg.r, gfx.bg.g, gfx.bg.b, gfx.bg.a);
        SDL_RenderPresent(gfx.rend);
        SDL_RenderClear(gfx.rend);
    }

    deinit();

    return 0;
}