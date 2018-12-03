#include <ctype.h>
#include "IO/ConditionalInput.h"
#include "IO/NameInput.h"
#include <stdbool.h>

static bool isNameValid(StringView name);

void scanName(String name) {
    scanStringIf(name, isNameValid);
}

bool isNameValid(StringView name) {

    bool isThisBeginOfName = true;

    for(const char* it = name; *it != '\0'; ++it) {

        if(isThisBeginOfName) {

            if(isupper(*it) == 0) {
                return false;
            } else {
                isThisBeginOfName = false;
                continue;
            }

        }

        if(*it == '-') {
            isThisBeginOfName = true;
            continue;
        }

        if(islower(*it) == 0) {
            return false;
        }

    }

    return isThisBeginOfName == false;

}
