#include "IO/BasicIO.h"
#include <stdio.h>
#include "UserInterface/Logo.h"

void displayBigLogo(void) {

    static const char* LOGO[5] = {
        " ____                   _____ _ _",
        "| __ )  __ _ ______ _  |  ___(_) |_ __ ___   _____      ____ _",
        "|  _ \\ / _` |_  / _` | | |_  | | | '_ ` _ \\ / _ \\ \\ /\\ / / _` |",
        "| |_) | (_| |/ / (_| | |  _| | | | | | | | | (_) \\ V  V / (_| |",
        "|____/ \\__,_/___\\__,_| |_|   |_|_|_| |_| |_|\\___/ \\_/\\_/ \\__,_|"
    };

    for(int i = 0; i < 5; ++i) {
        puts(LOGO[i]);
    }
    newLine();

}
