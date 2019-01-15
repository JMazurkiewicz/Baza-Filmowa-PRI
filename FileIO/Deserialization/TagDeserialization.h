#pragma once

#include "FileIO/DatabaseFile.h"
#include "Utility/Byte.h"
#include "Utility/Date.h"

void deserializeHeader(DatabaseFile* file);
Date deserializeDate(StringView path);

bool startListDeserialization(DatabaseFile* file);
bool endObjectDeserialization(DatabaseFile* file);
