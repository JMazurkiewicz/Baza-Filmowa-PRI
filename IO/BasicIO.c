#include "IO/BasicIO.h"
#include <stdlib.h>
#include "Utility/System.h"

void clearStdin(void) {
    fseek(stdin, 0, SEEK_END);
}

void clearConsole(void) {

#if defined(SYSTEM_WINDOWS)
    system("cls");
#elif defined(SYSTEM_LINUX)
    system("clear");
#endif

}

void newLine(void) {
    putchar('\n');
}

void printString(String string) {
    fputs(string, stdout);
}
