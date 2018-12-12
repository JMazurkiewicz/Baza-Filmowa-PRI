#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include <ctype.h>

static void tryAgain(void);

int scanIntegerFromRange(int min, int max) {

    int input;

    while(scanf("%d", &input) == 0 || input < min || max < input) {
        clearStdin();
        tryAgain();
    }

    return input;

}

bool scanBoolean() {

    char input;

    while(scanf("%c", &input) != 0 && (input = toupper(input)) != 'T' && input != 'N') {
        clearStdin();
        tryAgain();
    }

    return input == 'T';

}

void scanLineIf(String target, bool (*predicate)(StringView)) {

    scanLine(target);

    while(!predicate(target)) {
        tryAgain();
        scanLine(target);
    }

}

void tryAgain(void) {
    printString("\aNieprawidlowe dane, sprobuj ponownie: ");
}
