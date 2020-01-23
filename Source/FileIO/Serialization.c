#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "FileIO/Serialization/ListSerialization.h"
#include "FileIO/Serialization/TagSerialization.h"
#include "Lists/Database.h"

static void serializationError(StringView fileName);
static void serializeDatabaseStructure(DatabaseFile* file, const Database* database);

void serializeDatabase(StringView fileName, Database* database) {

    DatabaseFile file;

    if(!openOutputFile(&file, fileName)) {
        serializationError(fileName);
    } else {
        serializeDatabaseStructure(&file, database);
    }

    closeDatabaseFile(&file);

}

void serializationError(StringView fileName) {

    printf("Blad zapisu! Sprawdz czy nazwa \"%s\" jest prawidlowa.\n", fileName);
    waitForEnter();

}

void serializeDatabaseStructure(DatabaseFile* file, const Database* database) {

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
