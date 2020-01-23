#include "CommonIO/BasicIO.h"
#include "UserInterface/Logo.h"
#include "Utility/String.h"

static StringView LOGO[5] = {
    " ____                   _____ _ _",
    "| __ )  __ _ ______ _  |  ___(_) |_ __ ___   _____      ____ _",
    "|  _ \\ / _` |_  / _` | | |_  | | | '_ ` _ \\ / _ \\ \\ /\\ / / _` |",
    "| |_) | (_| |/ / (_| | |  _| | | | | | | | | (_) \\ V  V / (_| |",
    "|____/ \\__,_/___\\__,_| |_|   |_|_|_| |_| |_|\\___/ \\_/\\_/ \\__,_|"
};

void displayLogo(void) {

    for(int i = 0; i < 5; ++i) {
        puts(LOGO[i]);
    }
    newLine();

}
