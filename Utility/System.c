#include <stdio.h>
#include <stdlib.h>
#include "Utility/System.h"

#if defined(SYSTEM_WINDOWS)
# include <windows.h>
#elif defined(SYSTEM_LINUX)
# include <unistd.h>
#endif

void clearConsole(void) {

#if defined(SYSTEM_WINDOWS)
    system("cls");
#elif defined(SYSTEM_LINUX)
    system("clear");
#endif

}

void sleep(int milliseconds) {

#if defined(SYSTEM_WINDOWS)
    Sleep(milliseconds);
#elif defined(SYSTEM_LINUX)
    usleep(1000 * milliseconds);
#endif

}
