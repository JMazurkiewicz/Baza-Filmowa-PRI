#include "DatabaseFile.h"
#include "Deserialization.h"
#include "Deserialization/ActorListDeserialization.h"
#include "Deserialization/MovieListDeserialization.h"
#include "Deserialization/RoleListDeserialization.h"
#include "Deserialization/StudioListDeserialization.h"
#include "Deserialization/TagDeserialization.h"
#include "Lists/Database.h"

static void deserializationError(StringView fileName);
static bool deserializeDatabaseStructure(DatabaseFile* file, Database* database);

bool deserializeDatabase(StringView fileName, Database* database) {

    DatabaseFile file;
    bool done = false;

    if(!openInputFile(&file, fileName)) {
        deserializationError(fileName);
    } else {

        Database newDatabase;
        initDatabase(&newDatabase);
        strcpy(newDatabase.fileName, fileName);

        if(deserializeDatabaseStructure(&file, &newDatabase)) {
            freeDatabase(database);
            *database = newDatabase;
            done = true;
        } else {
            deserializationError(fileName);
            freeDatabase(&newDatabase);
        }

    }

    closeDatabaseFile(&file);
    return done;

}

void deserializationError(StringView fileName) {
    printf("Blad odczytu! Plik \"%s\" moze byc uszkodzony lub nie istnieje.\n", fileName);
    waitForEnter();
}

bool deserializeDatabaseStructure(DatabaseFile* file, Database* database) {

    deserializeHeader(file);

    return
        deserializeRoleList(file, database) &&
        deserializeActorList(file, database) &&
        deserializeMovieList(file, database) &&
        deserializeStudioList(file, database);

}
