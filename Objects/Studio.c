#include "Objects/Studio.h"

bool hasStudioThisName(const Studio* studio, StringView name) {
    return strcmp(studio->name, name) == 0;
}
