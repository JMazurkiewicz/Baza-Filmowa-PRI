#pragma once

#include <stdbool.h>
#include "Utility/String.h"

char readSingleCharIf(bool (*predicate)(char));
int readIntegerIf(bool (*predicate)(int));
void readStringIf(String target, bool (*predicate)(StringView));
