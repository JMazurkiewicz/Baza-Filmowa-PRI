#include "DatabaseFile.h"
#include "Utility/System.h"

static bool hasFileProperExtension(StringView fileName);

#if defined(SYSTEM_UNIX)

#include <dirent.h>
#include <unistd.h>

bool doesFileExist(StringView fileName) {
    return access(fileName, F_OK) != -1;
}

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

    closedir(stream);
    return directoryCount;

}

#elif defined(SYSTEM_WINDOWS)

#include <windows.h>

bool doesFileExist(StringView fileName) {
    DWORD attributes = GetFileAttributes(fileName);
    return
        attributes != INVALID_FILE_ATTRIBUTES && 
        !(attributes & FILE_ATTRIBUTE_DIRECTORY);
}

size_t getNamesOfDatabaseFiles(String names[], size_t arraySize) {

    WIN32_FIND_DATAA findData;
    HANDLE handle = FindFirstFileA("*.*", &findData);

    if(handle == INVALID_HANDLE_VALUE) {
        return 0;
    }

    size_t directoryCount = 0;

    do {

        if(!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            hasFileProperExtension(findData.cFileName)) {

            strcpy(names[directoryCount], findData.cFileName);
            ++directoryCount;
        
        }

    } while(FindNextFileA(handle, &findData) != 0);

    FindClose(handle);
    return directoryCount;

}

#else
#  error Unsupported file system.
#endif

bool hasFileProperExtension(StringView fileName) {
    const StringView extension = fileName + strReverseFind(fileName, '.');
    return strcmp(extension, DATABASE_FILE_EXTENSION) == 0;
}
