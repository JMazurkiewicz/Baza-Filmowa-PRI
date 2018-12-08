#include "Lists/Database.h"

void initDatabase(Database* database) {

    initActorList(&database->actors);
    initRoleList(&database->roles);
    initMovieList(&database->movies);
    initStudioList(&database->studios);

}

void freeDatabase(Database* database) {

    freeActorList(&database->actors);
    freeRoleList(&database->roles);
    freeMovieList(&database->movies);
    freeStudioList(&database->studios);

}
