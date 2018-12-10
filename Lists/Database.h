#pragma once

#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"

struct Database {

    ActorList actors;
    MovieList movies;
    RoleList roles;
    StudioList studios;

};

void initDatabase(Database* database);
void freeDatabase(Database* database);
