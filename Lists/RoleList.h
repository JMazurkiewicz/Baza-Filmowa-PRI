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

bool addRole(RoleListNode* head, const Actor* actor, const Movie* movie);

Role* findRole(RoleListNode* head, const Actor* actor, const Movie* movie);
Role* findNextRoleOfActor(RoleListNode* head, const Actor* actor);
Role* findNextRoleFromMovie(RoleListNode* head, const Movie* movie);

void deleteRolesOfActor(RoleListNode* head, const Actor* actor);
void deleteRolesFromMovie(RoleListNode* head, const Movie* movie);

void scanRolesFromMovie(RoleListNode* head, const ActorListNode* actors, const Movie* movie);
void scanRolesOfActor(RoleListNode* head, const MovieListNode* movies, const Actor* actor);

void printRolesOfActor(RoleListNode* head, const Actor* actor);
void printRolesFromMovie(RoleListNode* head, const Movie* movie);

void freeRoleListMemory(RoleListNode* head);
