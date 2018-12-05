#include "IO/BasicIO.h"
#include <stdlib.h>
#include "Utility/System.h"

void clearStdin(void) {
    fseek(stdin, 0, SEEK_END);
}

void getLine(String target) {

    int input = getchar();
    size_t charCounter = 0;

    for(; input != '\n' && input != EOF; input = getchar()) {

        if(charCounter < STRING_MAX_LENGTH) {
            *target++ = input;
            ++charCounter;
        } else {
            break;
        }

    }

    *target = '\0';
    clearStdin();

}

void clearConsole(void) {

#if defined(SYSTEM_WINDOWS)
    system("cls");
#elif defined(SYSTEM_UNIX)
    system("clear");
#endif

}

void newLine(void) {
    putchar('\n');
}

void printString(String string) {
    fputs(string, stdout);
}
