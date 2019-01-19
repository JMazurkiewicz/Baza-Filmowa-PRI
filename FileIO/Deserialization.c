#include "FileIO/DatabaseFile.h"
#include "FileIO/Deserialization.h"
#include "Deserialization/ActorListDeserialization.h"
#include "Deserialization/MovieListDeserialization.h"
#include "Deserialization/RoleListDeserialization.h"
#include "Deserialization/StudioListDeserialization.h"
#include "Deserialization/TagDeserialization.h"
#include "Lists/Database.h"

static void deserializationError(void);
static bool deserializeData(DatabaseFile* file, Database* database);

void deserializeDatabase(StringView filePath, Database* database) {

    DatabaseFile file;

    if(!openInputFile(&file, filePath)) {
        deserializationError();
    } else {

        Database newDatabase;
        initDatabase(&newDatabase);

        if(deserializeData(&file, &newDatabase)) {

            freeDatabase(database);
            *database = newDatabase;

        } else {

            freeDatabase(&newDatabase);
            deserializationError();

        }

    }

    closeDatabaseFile(&file);

}

void deserializationError(void) {
    puts("Blad odczytu! Plik moze byc uszkodzony lub nie istnieje.");
    waitForEnter();
}

bool deserializeData(DatabaseFile* file, Database* database) {

    deserializeHeader(file);

    return
        deserializeRoleList(file, database) &&
        deserializeActorList(file, database) &&
        deserializeMovieList(file, database) &&
        deserializeStudioList(file, database);

}
