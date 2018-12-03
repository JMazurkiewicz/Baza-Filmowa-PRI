#pragma once

#include <stdbool.h>
#include "Utility/String.h"

char scanCharIf(bool (*predicate)(char));
int scanIntegerIf(bool (*predicate)(int));
void scanStringIf(String target, bool (*predicate)(StringView));
