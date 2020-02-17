#include "BasicIO.h"
#include <stdlib.h>
#include "Utility/System.h"

void clearStdin(void) {

    int input;
    while((input = getchar()) != '\n' && input != EOF);

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

	size_t charCount = 0;
    int input;

	while((input = getchar()) != EOF && input != '\n' && charCount < STRING_MAX_LENGTH) {
        target[charCount++] = input;
	}

	target[charCount] = '\0';

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
