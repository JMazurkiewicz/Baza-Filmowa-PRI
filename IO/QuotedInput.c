#include "IO/BasicIO.h"
#include "IO/QuotedInput.h"
#include <stdbool.h>

static const char DELIMITER = '\"';

void scanQuotedString(String target) {

    char symbol = getchar();

    if(symbol != DELIMITER) {
        ungetc(symbol, stdin);
        scanf("%s", target);
        return;
    }

    do {

        symbol = getchar();
        if(symbol == DELIMITER) {
            break;
        }

	    *target++ = symbol;

    } while(true);

    *target = '\0';

}
