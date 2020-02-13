#include "BasicIO.h"
#include "ConditionalInput.h"
#include <ctype.h>

#define INPUT_TRUE ((char)'T')
#define INPUT_FALSE ((char)'N')

static void tryAgain(void);

int scanBoundedInteger(int min, int max) {

    discardWhitespace();

    int input;

    while(scanf("%d", &input) == 0 || input < min || max < input) {
        clearStdin();
        tryAgain();
    }

    clearStdin();
    return input;

}

bool scanBoolean() {

    discardWhitespace();

    char input;

    while(scanf("%c", &input) != 0 && (input = toupper(input)) != INPUT_TRUE && input != INPUT_FALSE) {
        clearStdin();
        tryAgain();
    }

    clearStdin();
    return input == INPUT_TRUE;

}

void scanLineIf(String target, bool (*predicate)(StringView)) {

    scanLine(target);

    while(!predicate(target)) {
        tryAgain();
        scanLine(target);
    }

}

void tryAgain(void) {
    printString("Nieprawidlowe dane, sprobuj ponownie: ");
}
