#include <ctype.h>
#include "Utility/String.h"

const size_t STRING_NPOS = (size_t)(-1);

size_t strFindIf(StringView target, int (*predicate)(int)) {

    for(size_t index = 0; target[index] != '\0'; ++index) {
        if(predicate(target[index])) {
            return index;
        }
    }

    return STRING_NPOS;

}

size_t strReverseFindIf(StringView target, int (*predicate)(int)) {

    for(size_t index = strlen(target); index-- > 0; ) {
        if(predicate(target[index])) {
            return index;
        }
    }

    return STRING_NPOS;

}

void trimWhitespace(String target) {

    const size_t posOfFirstGraphChar = strFindIf(target, isgraph);

    if(posOfFirstGraphChar == STRING_NPOS) {
        target[0] = '\0';
        return;
    }

    const size_t posAfterLastGraphChar = strReverseFindIf(target, isgraph) + 1;
    const size_t graphCharsCount = posAfterLastGraphChar-posOfFirstGraphChar;

    if(posOfFirstGraphChar != 0) {
        memmove(target, target+posOfFirstGraphChar, graphCharsCount);
    }

    target[graphCharsCount] = '\0';

}
