#include <ctype.h>
#include "Utility/String.h"

const size_t STRING_NPOS = -1;

bool strIsEmpty(StringView string) {
    return string[0] == '\0';
}

size_t strReverseFind(StringView string, char c) {

    for(size_t index = strlen(string); index-- > 0; ) {
        if(string[index] == c) {
            return index;
        }
    }

    return STRING_NPOS;

}

size_t strFindIf(StringView string, int (*predicate)(int)) {

    for(size_t index = 0; string[index] != '\0'; ++index) {
        if(predicate(string[index]) != 0) {
            return index;
        }
    }

    return STRING_NPOS;

}

size_t strReverseFindIf(StringView string, int (*predicate)(int)) {

    for(size_t index = strlen(string); index-- > 0; ) {
        if(predicate(string[index]) != 0) {
            return index;
        }
    }

    return STRING_NPOS;

}

int strCaseInsensitiveCompare(StringView left, StringView right) {

    while(*left != '\0' && *right != '\0' && tolower(*left) == tolower(*right)) {
        ++left;
        ++right;
    }

    return tolower(*left) - tolower(*right);

}

void strTrimWhitespace(String string) {

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
