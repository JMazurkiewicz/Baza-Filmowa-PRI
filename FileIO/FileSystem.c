#include <dirent.h>
#include "FileIO/DatabaseFile.h"
#include "FileIO/FileSystem.h"

static bool hasFileProperExtension(StringView fileName);

size_t getNamesOfDatabaseFiles(String names[], size_t arraySize) {

    DIR* stream = opendir(".");
    size_t directoryCount = 0;
    struct dirent* directory = readdir(stream);

    while(directory != NULL && directoryCount < arraySize) {

        if(hasFileProperExtension(directory->d_name)) {

            strcpy(names[directoryCount], directory->d_name);
            ++directoryCount;

        }

        directory = readdir(stream);

    }

    return directoryCount;

}

bool hasFileProperExtension(StringView fileName) {

    const StringView extension = fileName + strReverseFind(fileName, '.');
    return strcmp(extension, DATABASE_FILE_EXTENSION) == 0;

}
