#pragma once

#include "Lists/Declarations.h"
#include "Objects/Declarations.h"

void scanRolesOfActor(RoleList* list, const MovieList* movies, const Actor* actor);
void scanRolesFromMovie(RoleList* list, const ActorList* actors, const Movie* movie);

void printRolesOfActor(const RoleList* list, const Actor* actor);
void printRolesFromMovie(const RoleList* list, const Movie* movie);
