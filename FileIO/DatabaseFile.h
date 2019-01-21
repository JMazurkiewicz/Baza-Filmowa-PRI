#pragma once

#include "CommonIO/BasicIO.h"
#include "Utility/Byte.h"

static const StringView DATABASE_FILE_EXTENSION = ".mbf";
static const StringView BACKUP_FILE_NAME = "__backup__.mbf";

typedef struct DatabaseFile {

    FILE* handle;
    Byte key;

} DatabaseFile;

bool openOutputFile(DatabaseFile* file, StringView path);
bool openInputFile(DatabaseFile* file, StringView path);

void closeDatabaseFile(DatabaseFile* file);
