#pragma once

#include <stddef.h>
#include "Utility/String.h"

StringView getFileExtension(StringView file);
size_t getNamesOfDatabaseFiles(String names[], size_t arraySize);
