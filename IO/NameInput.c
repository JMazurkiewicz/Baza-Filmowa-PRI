#include <ctype.h>
#include "IO/ConditionalInput.h"
#include "IO/NameInput.h"
#include <stdbool.h>

static bool isNameValid(StringView name);

void scanName(String name) {
    scanStringLineIf(name, isNameValid);
    trimWhitespace(name);
}

bool isNameValid(StringView name) {

    name += strFindIf(name, isgraph);
    // @todo
    return true;

}
