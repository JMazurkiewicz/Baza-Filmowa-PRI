#pragma once

#include <stdbool.h>
#include "Utility/String.h"

int scanIntegerFromRange(int min, int max);
void scanLineIf(String target, bool (*predicate)(StringView));
