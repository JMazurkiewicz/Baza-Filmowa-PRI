#pragma once

#include <stdbool.h>
#include <string.h>

#define STRING_MAX_LENGTH (127)
#define STRING_NPOS ((size_t)(-1))

typedef char String[STRING_MAX_LENGTH + 1];
typedef const char* StringView;
typedef const char* StringConstIterator;
typedef int (*CharPredicate)(int);

bool strIsEmpty(StringView string);

size_t strReverseFind(StringView string, char c);

size_t strFindIf(StringView string, CharPredicate predicate);
size_t strReverseFindIf(StringView string, CharPredicate predicate);

int strCaseInsensitiveCompare(StringView left, StringView right);

void strTrimWhitespace(String string);
