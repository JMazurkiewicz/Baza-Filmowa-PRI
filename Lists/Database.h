#pragma once

#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"

typedef struct Database {

    ActorList actors;
    RoleList roles;
    MovieList movies;
    StudioList studios;

} Database;

void initDatabase(Database* database);
void freeDatabase(Database* database);
