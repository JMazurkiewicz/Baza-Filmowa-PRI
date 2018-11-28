#include "Lists/Database.h"

void initDatabase(Database* database) {

    database->actors = NULL;
    database->roles = NULL;
    database->movies = NULL;
    database->studios = NULL;

}

void freeDatabaseMemory(Database* database) {

    freeActorListMemory(database->actors);
    freeRoleListMemory(database->roles);
    freeMovieListMemory(database->movies);
    freeStudioListMemory(database->studios);

    initDatabase(database);

}
