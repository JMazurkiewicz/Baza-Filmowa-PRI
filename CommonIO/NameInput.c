#include <ctype.h>
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include <stdbool.h>

static bool isNameValid(StringView name);
static bool isNameValidImpl(StringView name, size_t nameLength);

void scanName(String name) {
    scanStringLineIf(name, isNameValid);
    trimWhitespace(name);
}

bool isNameValid(StringView name) {

    const size_t posOfFirstGraphChar = strFindIf(name, isgraph);
    if(posOfFirstGraphChar == STRING_NPOS) {
        return false;
    }

    name += posOfFirstGraphChar;
    const size_t nameLength = strReverseFindIf(name, isgraph);

    return isNameValidImpl(name, nameLength);

}

bool isNameValidImpl(StringView name, size_t nameLength) {

    bool isThisBeginOfName = true;

    for(StringConstIterator it = name; nameLength-- > 0; ++it) {

        if(isThisBeginOfName) {

            if(isupper(*it) == 0) {
                return false;
            } else {
                isThisBeginOfName = false;
                continue;
            }

        }

        if(*it == ' ') {
            isThisBeginOfName = true;
            continue;
        }

        if(islower(*it) == 0) {
            return false;
        }

    }

    return isThisBeginOfName == false;

}
