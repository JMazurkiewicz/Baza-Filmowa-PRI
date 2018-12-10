#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include <ctype.h>

static void tryAgain(void);

int scanIntegerFromRange(int min, int max) {

    int input;

    while(scanf("%d", &input) == 0 || input < min || max < input) {
        tryAgain();
    }

    clearStdin();
    return input;

}

bool scanBoolean() {

    char input = toupper(getchar());

    while(input != 'T' && input != 'N') {
        tryAgain();
        input = toupper(getchar());
    }

    clearStdin();
    return input == 'T';

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
