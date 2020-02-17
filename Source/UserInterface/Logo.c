#include "CommonIO/BasicIO.h"
#include "Logo.h"
#include "Utility/String.h"

#define LOGO_ARRAY_SIZE (5)

static StringView LOGO[LOGO_ARRAY_SIZE] = {
    " ____                   _____ _ _",
    "| __ )  __ _ ______ _  |  ___(_) |_ __ ___   _____      ____ _",
    "|  _ \\ / _` |_  / _` | | |_  | | | '_ ` _ \\ / _ \\ \\ /\\ / / _` |",
    "| |_) | (_| |/ / (_| | |  _| | | | | | | | | (_) \\ V  V / (_| |",
    "|____/ \\__,_/___\\__,_| |_|   |_|_|_| |_| |_|\\___/ \\_/\\_/ \\__,_|"
};

void displayLogo(void) {
    for(int i = 0; i < LOGO_ARRAY_SIZE; ++i) {
        puts(LOGO[i]);
    }
    newLine();
}
