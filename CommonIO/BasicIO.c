#include "CommonIO/BasicIO.h"
#include <stdlib.h>
#include "Utility/System.h"

void clearStdin(void) {

    int input;
    do {
        input = getchar();
    } while(input != '\n' && input != EOF);

}

void discardWhitespace(void) {
    scanf(" ");
}

void waitForEnter(void) {

    printString("Nacisnij enter aby kontynuowac...");
    clearStdin();

}

void scanLine(String target) {

    discardWhitespace();

    char input;
	size_t charCounter = 0;

	while(scanf("%c", &input) != 0 && input != '\n') {

		if(charCounter < 128) {
			target[charCounter++] = input;
		} else {
			break;
		}

	}

	target[charCounter] = '\0';

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
