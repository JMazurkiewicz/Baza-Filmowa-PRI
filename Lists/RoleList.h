#pragma once

#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include "Objects/Role.h"

typedef struct RoleListNode {

    struct RoleListNode* next;
    Role value;

} RoleListNode;

bool addRole(RoleListNode* head, Actor* actor, Movie* movie);
Role* findRole(RoleListNode* head, Actor* actor, Movie* movie);

void deleteRolesOfActor(RoleListNode* head, const Actor* actor);
void deleteRolesFromMovie(RoleListNode* head, const Movie* movie);

void scanActorsForMovie(RoleListNode* head, const ActorListNode* actors, Movie* movie);
void scanMoviesForActor(RoleListNode* head, const MovieListNode* movies, Actor* actor);

void printRolesOfActor(RoleListNode* head, const Actor* actor);
void printRolesFromMovie(RoleListNode* head, const Movie* movie);

void freeRoleListMemory(RoleListNode* head);
