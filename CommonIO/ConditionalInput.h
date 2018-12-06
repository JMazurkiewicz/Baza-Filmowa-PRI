#pragma once

#include <stdbool.h>
#include "Utility/String.h"

char scanCharIf(bool (*predicate)(char));

int scanIntegerIf(bool (*predicate)(int));
int scanIntegerFromRange(int min, int max);

void scanStringIf(String target, bool (*predicate)(StringView));
void scanStringLineIf(String target, bool (*predicate)(StringView));
