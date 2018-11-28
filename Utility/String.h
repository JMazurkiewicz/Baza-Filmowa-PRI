#pragma once

#include <string.h>

#define STRING_MAX_LENGTH (128)
#define SCAN_STRING "%128s"

typedef char String[STRING_MAX_LENGTH + 1];
typedef const char* StringView;
