#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdio.h>

static void tryAgain(void);

char readSingleCharIf(bool (*predicate)(char)) {

    char input = getchar();

    while(!predicate(input)) {
        tryAgain();
        input = getchar();
    }

    clearStdin();
    return input;

}

int readIntegerIf(bool (*predicate)(int)) {

    int input;

    while(scanf("%d", &input) == 0 || !predicate(input)) {
        tryAgain();
        clearStdin();
    }

    clearStdin();
    return input;

}

void readStringIf(String target, bool (*predicate)(StringView)) {

    scanf(SCAN_STRING, target);

    while(!predicate(target)) {
        tryAgain();
        scanf(SCAN_STRING, target);
    }

    clearStdin();

}

void tryAgain(void) {
    printString("\aNieprawidlowe dane, sprobuj ponownie: ");
    clearStdin();
}
