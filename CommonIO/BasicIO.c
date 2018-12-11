#include "CommonIO/BasicIO.h"
#include <stdlib.h>
#include "Utility/System.h"

void clearStdin(void) {
    fseek(stdin, 0, SEEK_END);
}

void waitForEnter(void) {

    printString("Nacisnij enter aby kontynuowac...");
    getchar();
    clearStdin();

}

void scanLine(String target) {

    int input = getchar();
    size_t charCounter = 0;

    while(input != '\n' && input != EOF) {

        if(charCounter < STRING_MAX_LENGTH) {
            target[charCounter++] = input;
            input = getchar();
        } else {
            break;
        }

    }

    target[charCounter] = '\0';
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

void printString(StringView string) {
    fputs(string, stdout);
}
