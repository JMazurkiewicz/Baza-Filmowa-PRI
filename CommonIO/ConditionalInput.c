#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"

static void tryAgain(void);

int scanIntegerFromRange(int min, int max) {

    int input;

    while(scanf("%d", &input) == 0 || input < min || max < input) {
        tryAgain();
    }

    clearStdin();
    return input;

}

void scanLineIf(String target, bool (*predicate)(StringView)) {

    scanLine(target);

    while(!predicate(target)) {
        tryAgain();
        scanLine(target);
    }

    clearStdin();

}

void tryAgain(void) {
    printString("\aNieprawidlowe dane, sprobuj ponownie: ");
    clearStdin();
}
