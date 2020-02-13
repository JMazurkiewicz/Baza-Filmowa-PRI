#pragma once

#include "CommonIO/BasicIO.h"
#include "Utility/Byte.h"

extern const StringView DATABASE_FILE_EXTENSION;
extern const StringView BACKUP_FILE_NAME;

typedef struct DatabaseFile {

    FILE* handle;
    Byte key;

} DatabaseFile;

bool openOutputFile(DatabaseFile* file, StringView path);
bool openInputFile(DatabaseFile* file, StringView path);

void closeDatabaseFile(DatabaseFile* file);
