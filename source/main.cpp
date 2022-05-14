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
        switch (in.current_button) {
            case 0:
                std::cout << "Pressed A" << std::endl;
                SDL_SetRenderDrawColor(gfx.rend, 0, 255, 0, 255);
                break;
            case 10:
                run = false;
                break;
        }
        in.current_button = -1;

        graphics_drawRectBorder(gfx, WHITE, &rects[0]);

        SDL_SetRenderDrawColor(gfx.rend, gfx.bg.r, gfx.bg.g, gfx.bg.b, gfx.bg.a);
        SDL_RenderPresent(gfx.rend);
        SDL_RenderClear(gfx.rend);
    }

    deinit();

    return 0;
}