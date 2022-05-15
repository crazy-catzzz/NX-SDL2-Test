#include "../include/input.h"

#include <switch.h>
#include <iostream>

void init_input(input& in, u32 maxPlayers) {
    in.max_players = maxPlayers;
    padConfigureInput(in.max_players, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&in.pad);
}

int getInput(input& in) {
    padUpdate(&in.pad);
    u64 kDown = padGetButtonsDown(&in.pad);
    u64 kUp = padGetButtonsUp(&in.pad);

    std::cout << "kUp: " << kUp << std::endl;

    if (kDown & HidNpadButton_A)                return 0;
    if (kDown & HidNpadButton_B)                return 1;
    if (kDown & HidNpadButton_X)                return 2;
    if (kDown & HidNpadButton_Y)                return 3;
    if (kDown & HidNpadButton_StickL)           return 4;
    if (kDown & HidNpadButton_StickR)           return 5;
    if (kDown & HidNpadButton_L)                return 6;
    if (kDown & HidNpadButton_R)                return 7;
    if (kDown & HidNpadButton_ZL)               return 8;
    if (kDown & HidNpadButton_ZR)               return 9;
    if (kDown & HidNpadButton_Plus)             return 10;
    if (kDown & HidNpadButton_Minus)            return 11;
    if (kDown & HidNpadButton_Left)             return 12;
    if (kDown & HidNpadButton_Up)               return 13;
    if (kDown & HidNpadButton_Right)            return 14;
    if (kDown & HidNpadButton_Down)             return 15;
    if (kDown & HidNpadButton_StickLLeft)       return 16;
    if (kDown & HidNpadButton_StickLUp)         return 17;
    if (kDown & HidNpadButton_StickLRight)      return 18;
    if (kDown & HidNpadButton_StickLDown)       return 19;
    if (kDown & HidNpadButton_StickRLeft)       return 20;
    if (kDown & HidNpadButton_StickRUp)         return 21;
    if (kDown & HidNpadButton_StickRRight)      return 22;
    if (kDown & HidNpadButton_StickRDown)       return 23;
    //if (kDown & HidNpadButton_LeftSL)           return 24;
    //if (kDown & HidNpadButton_LeftSR)           return 25;
    //if (kDown & HidNpadButton_RightSL)          return 26;
    //if (kDown & HidNpadButton_RightSR)          return 27;
    //if (kDown & HidNpadButton_Palma)            return 28;
    //if (kDown & HidNpadButton_29)               return 29;
    //if (kDown & HidNpadButton_HandheldLeftB)    return 30;

    if (kUp != 0)                             return -1;

    return in.current_button;
}