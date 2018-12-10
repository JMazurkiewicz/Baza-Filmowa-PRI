#include "Objects/Studio.h"

bool hasStudioThisName(const Studio* studio, StringView name) {
    return strCaseInsensitiveCompare(studio->name, name) == 0;
}
