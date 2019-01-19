#include "FileIO/Deserialization/BasicDeserialization.h"
#include "FileIO/Serialization/BasicSerialization.h"
#include "FileIO/DatabaseFile.h"
#include <stdlib.h>

bool openOutputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "wb");
    file->key = 0;

    if(file->handle != 0) {

        const int newKey = (rand() % 255) + 1;
        serializeByte(file, newKey);
        file->key = newKey;

        return true;

    }

    return false;

}

bool openInputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "rb");
    file->key = 0;

    if(file->handle != 0) {

        file->key = deserializeByte(file);
        return true;

    }

    return false;

}

void closeDatabaseFile(DatabaseFile* file) {
    fclose(file->handle);
    file->handle = 0;
}
