#pragma once

#include "CommonIO/BasicIO.h"
#include <stdbool.h>
#include "Utility/Byte.h"

typedef struct DatabaseFile {

    FILE* handle;
    Byte key;

} DatabaseFile;

bool openOutputFile(DatabaseFile* file, StringView path);
bool openInputFile(DatabaseFile* file, StringView path);
