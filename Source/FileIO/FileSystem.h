#pragma once

#include "Utility/String.h"

bool doesFileExist(StringView fileName);
size_t getNamesOfDatabaseFiles(String names[], size_t arraySize);
