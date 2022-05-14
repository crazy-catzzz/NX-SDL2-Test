#pragma once

#include <switch.h>

struct input {
    PadState pad;
    u32 max_players;
    int current_button = -1;
};

void init_input(input& in, u32 maxPlayers);

int getInput(input& in);