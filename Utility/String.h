#pragma once

#include <string.h>

#define STRING_MAX_LENGTH (128)

typedef char String[STRING_MAX_LENGTH + 1];
typedef const char* StringView;
typedef const char* StringConstIterator;

extern const size_t STRING_NPOS;

size_t strFindIf(StringView string, int (*predicate)(int));
size_t strReverseFindIf(StringView string, int (*predicate)(int));

int strCaseInsensitiveCompare(StringView left, StringView right);

void strTrimWhitespace(String string);
