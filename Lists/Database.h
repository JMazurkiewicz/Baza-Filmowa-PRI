#pragma once

#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"

typedef struct Database {

    ActorList actors;
    MovieList movies;
    RoleList roles;
    StudioList studios;

} Database;

void initDatabase(Database* database);
void freeDatabase(Database* database);
