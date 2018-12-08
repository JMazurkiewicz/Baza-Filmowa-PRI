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

typedef struct RoleList {

    RoleListNode* head;

} RoleList;

void initRoleList(RoleList* list);
void freeRoleList(RoleList* list);

bool addRole(RoleList* list, const Actor* actor, const Movie* movie);

const Role* findRole(const RoleList* list, const Actor* actor, const Movie* movie);
const Role* findRoleOfActor(const RoleList* list, const Actor* actor);
const Role* findRoleFromMovie(const RoleList* list, const Movie* movie);

void deleteRolesOfActor(RoleList* list, const Actor* actor);
void deleteRolesFromMovie(RoleList* list, const Movie* movie);

void scanRolesFromMovie(RoleList* list, const ActorList* actors, const Movie* movie);
void scanRolesOfActor(RoleList* list, const MovieList* movies, const Actor* actor);

void printRolesOfActor(const RoleList* list, const Actor* actor);
void printRolesFromMovie(const RoleList* list, const Movie* movie);
