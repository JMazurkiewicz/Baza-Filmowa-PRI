#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include <ctype.h>
#include <stdbool.h>

static bool isNameValid(StringView name);
static bool isNameGrammaticallyCorrect(StringView name, size_t nameLength);

void scanName(String name) {
    scanLineIf(name, isNameValid);
    trimWhitespace(name);
}

bool isNameValid(StringView name) {

    const size_t posOfFirstGraphChar = strFindIf(name, isgraph);
    if(posOfFirstGraphChar == STRING_NPOS) {
        return false;
    }

    const size_t nameLength = strReverseFindIf(name, isgraph) + 1;

    return isNameGrammaticallyCorrect(name + posOfFirstGraphChar, nameLength);

}

bool isNameGrammaticallyCorrect(StringView name, size_t nameLength) {

    bool beginOfName = true;

    for(StringConstIterator it = name; nameLength-- > 0; ++it) {

        if(beginOfName) {

            if(isupper(*it) == 0) {
                return false;
            } else {
                beginOfName = false;
            }

        } else if(*it == ' ') {
            beginOfName = true;
        } else if(islower(*it) == 0) {
            return false;
        }

    }

    return beginOfName == false;

}
