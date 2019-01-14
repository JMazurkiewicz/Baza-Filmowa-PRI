#include "FileIO/DatabaseFile.h"
#include <stdlib.h>

bool openOutputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "wb");

    if(file->handle != 0) {

        file->key = 0; // @toexchange (rand() % 255) + 1;
        return true;

    }

    return false;

}

bool openInputFile(DatabaseFile* file, StringView path) {

    file->handle = fopen(path, "rb");
    return file->handle != 0;

}
