#pragma once

#include "ActorList.h"
#include "MovieList.h"
#include "RoleList.h"
#include <stdbool.h>
#include "StudioList.h"

struct Database {

    ActorList actors;
    MovieList movies;
    RoleList roles;
    StudioList studios;

    String fileName;
    bool isDatabaseModified;

};

void initDatabase(Database* database);
void freeDatabase(Database* database);
