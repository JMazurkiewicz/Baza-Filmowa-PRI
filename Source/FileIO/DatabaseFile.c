#include "DatabaseFile.h"
#include "Deserialization/BasicDeserialization.h"
#include "Serialization/BasicSerialization.h"
#include <stdbool.h>
#include <stdlib.h>

const StringView DATABASE_FILE_EXTENSION = ".mbf";
const StringView BACKUP_FILE_NAME = ".backup.mbf";

bool openOutputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "wb");
    file->key = 0;

    const bool isFileGood = file->handle != NULL;

    if(isFileGood) {
        const int newKey = (rand() % 255) + 1;
        serializeByte(file, newKey);
        file->key = newKey;
    }
    return isFileGood;

}

bool openInputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "rb");
    file->key = 0;

    const bool isFileGood = file->handle != NULL;

    if(isFileGood) {
        file->key = deserializeByte(file);
    }
    return isFileGood;

}

void closeDatabaseFile(DatabaseFile* file) {
    fclose(file->handle);
    file->handle = NULL;
}
