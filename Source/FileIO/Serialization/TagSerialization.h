#pragma once

#include "FileIO/DatabaseFile.h"

void startListSerialization(DatabaseFile* file);
void startObjectSerialization(DatabaseFile* file);
void endObjectSerialization(DatabaseFile* file);
void endListSerialization(DatabaseFile* file);

void serializeHeader(DatabaseFile* file);
