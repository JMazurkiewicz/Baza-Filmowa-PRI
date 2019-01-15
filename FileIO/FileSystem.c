#include <dirent.h>
#include "FileIO/DatabaseFile.h"
#include "FileIO/FileSystem.h"

StringView getFileExtension(StringView file) {
    return file + strReverseFind(file, '.');
}

size_t getNamesOfDatabaseFiles(String names[], size_t arraySize) {

    DIR* stream = opendir(".");
    struct dirent* directory = readdir(stream);
    size_t directoryCount = 0;

    while(directory != NULL && directoryCount < arraySize) {

        const int hasFileProperExtension = strcmp(getFileExtension(directory->d_name), DATABASE_FILE_EXTENSION);

        if(hasFileProperExtension == 0) {

            strcpy(names[directoryCount], directory->d_name);
            ++directoryCount;

        }

        directory = readdir(stream);

    }

    return directoryCount;

}
