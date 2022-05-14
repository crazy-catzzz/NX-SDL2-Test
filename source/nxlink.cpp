#include "../include/nxlink.h"

#include <switch.h>
#include <unistd.h>
#include <iostream>

void nxlink_init() {
    if (R_FAILED(socketInitializeDefault())) return;

    s_nxlinkSock = nxlinkStdio();

    if (s_nxlinkSock >= 0)
        std::cout << "stdout redirected to nxlink!" << std::endl;
    else
        socketExit(); 
}

void nxlink_deinit()
{
    if (s_nxlinkSock >= 0) {
        close(s_nxlinkSock);
        socketExit();
        s_nxlinkSock = -1;
    }
}