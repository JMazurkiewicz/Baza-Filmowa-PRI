#pragma once

#include "FileIO/DatabaseFile.h"
#include <stdint.h>
#include "Utility/String.h"

void serializeByte(DatabaseFile* file, Byte byte);

void serializeInteger(DatabaseFile* file, const Byte* firstByte, size_t width);
void serializeInt32(DatabaseFile* file, int32_t integer);
void serializeInt64(DatabaseFile* file, int64_t integer);

void serializeAddress(DatabaseFile* file, const void* address);
void serializeString(DatabaseFile* file, StringView string);
