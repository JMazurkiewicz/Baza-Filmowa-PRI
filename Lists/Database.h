#pragma once

#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"

typedef struct Database {

    ActorListNode* actors;
    RoleListNode* roles;
    MovieListNode* movies;
    StudioListNode* studios;

} Database;

void initDatabase(Database* database);
void freeDatabaseMemory(Database* database);
