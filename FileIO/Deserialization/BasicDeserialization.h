#pragma once

#include "FileIO/DatabaseFile.h"
#include <stdint.h>
#include "Utility/String.h"

Byte deserializeByte(DatabaseFile* file);

void deserializeInteger(DatabaseFile* file, Byte* firstByte, size_t width);
int32_t deserializeInt32(DatabaseFile* file);
int64_t deserializeInt64(DatabaseFile* file);

void* deserializeAddress(DatabaseFile* file);
void deserializeString(DatabaseFile* file, String string);
