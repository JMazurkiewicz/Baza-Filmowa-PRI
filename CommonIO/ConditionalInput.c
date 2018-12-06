#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include <stdio.h>

static void tryAgain(void);

char scanCharIf(bool (*predicate)(char)) {

    char input = getchar();

    while(!predicate(input)) {
        tryAgain();
        input = getchar();
    }

    clearStdin();
    return input;

}

int scanIntegerIf(bool (*predicate)(int)) {

    int input;

    while(scanf("%d", &input) == 0 || !predicate(input)) {
        tryAgain();
    }

    clearStdin();
    return input;

}

int scanIntegerFromRange(int min, int max) {

    int input;

    while(scanf("%d", &input) == 0 || input < min || max < input) {
        tryAgain();
    }

    clearStdin();
    return input;

}

void scanStringIf(String target, bool (*predicate)(StringView)) {

    scanf(SCAN_STRING, target);

    while(!predicate(target)) {
        tryAgain();
        scanf(SCAN_STRING, target);
    }

    clearStdin();

}

void scanStringLineIf(String target, bool (*predicate)(StringView)) {

    getLine(target);

    while(!predicate(target)) {
        tryAgain();
        getLine(target);
    }

    clearStdin();

}

void tryAgain(void) {
    printString("\aNieprawidlowe dane, sprobuj ponownie: ");
    clearStdin();
}
