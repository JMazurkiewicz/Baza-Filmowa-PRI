#include <ctype.h>
#include "Utility/String.h"

const size_t STRING_NPOS = (size_t)(-1);

size_t strFindIf(StringView string, int (*predicate)(int)) {

    for(size_t index = 0; string[index] != '\0'; ++index) {
        if(predicate(string[index])) {
            return index;
        }
    }

    return STRING_NPOS;

}

size_t strReverseFindIf(StringView string, int (*predicate)(int)) {

    for(size_t index = strlen(string); index-- > 0; ) {
        if(predicate(string[index])) {
            return index;
        }
    }

    return STRING_NPOS;

}

void trimWhitespace(String string) {

    const size_t posOfFirstGraphChar = strFindIf(string, isgraph);

    if(posOfFirstGraphChar == STRING_NPOS) {
        string[0] = '\0';
        return;
    }

    const size_t posAfterLastGraphChar = strReverseFindIf(string, isgraph) + 1;
    const size_t graphCharsCount = posAfterLastGraphChar-posOfFirstGraphChar;

    if(posOfFirstGraphChar != 0) {
        memmove(string, string+posOfFirstGraphChar, graphCharsCount);
    }

    string[graphCharsCount] = '\0';

}
