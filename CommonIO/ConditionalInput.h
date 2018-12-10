#pragma once

#include <stdbool.h>
#include "Utility/String.h"

int scanIntegerFromRange(int min, int max);
bool scanBoolean();

void scanLineIf(String target, bool (*predicate)(StringView));
