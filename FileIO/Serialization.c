#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "FileIO/Serialization/ListSerialization.h"
#include "FileIO/Serialization/TagSerialization.h"
#include "Lists/Database.h"

static void serializationError(void);
static void serializeData(DatabaseFile* file, const Database* database);

void serializeDatabase(StringView dbFileName, Database* database) {

    DatabaseFile file;

    String path;
    strcpy(path, dbFileName);
    strcat(path, DATABASE_FILE_EXTENSION);

    if(!openOutputFile(&file, path)) {
        serializationError();
    } else {
        serializeData(&file, database);
    }

    closeDatabaseFile(&file);

}

void serializationError(void) {

    puts("Blad zapisu! Sprawdz czy podana sciezka jest prawidlowa.");
    waitForEnter();

}

void serializeData(DatabaseFile* file, const Database* database) {

    serializeHeader(file);

    startListSerialization(file);
    serializeRoleList(file, &database->roles);
    endListSerialization(file);

    startListSerialization(file);
    serializeActorList(file, &database->actors);
    endListSerialization(file);

    startListSerialization(file);
    serializeMovieList(file, &database->movies);
    endListSerialization(file);

    startListSerialization(file);
    serializeStudioList(file, &database->studios);
    endListSerialization(file);

}
