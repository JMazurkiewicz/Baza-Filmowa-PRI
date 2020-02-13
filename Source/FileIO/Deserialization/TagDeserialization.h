#pragma once

#include "FileIO/DatabaseFile.h"
#include <stdbool.h>
#include "Utility/Date.h"

void deserializeHeader(DatabaseFile* file);
Date deserializeDateFromFile(StringView path);

bool startListDeserialization(DatabaseFile* file);
bool endObjectDeserialization(DatabaseFile* file);
