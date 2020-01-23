#pragma once

#include "Lists/Declarations.h"
#include "Objects/Role.h"
#include <stdbool.h>

struct RoleListNode {

    RoleListNode* next;
    Role value;

};

struct RoleList {

    RoleListNode* head;

};

void initRoleList(RoleList* list);
void freeRoleList(RoleList* list);

bool isRoleListEmpty(const RoleList* list);

void addRole(RoleList* list, const Actor* actor, const Movie* movie);

Role* findRole(RoleList* list, const Actor* actor, const Movie* movie);
Role* findRoleOfActor(RoleList* list, const Actor* actor);
Role* findRoleFromMovie(RoleList* list, const Movie* movie);

void deleteRole(const RoleList* list, const Actor* actor, const Movie* movie);
void deleteRolesOfActor(RoleList* list, const Actor* actor);
void deleteRolesFromMovie(RoleList* list, const Movie* movie);

void scanRolesOfActor(RoleList* list, MovieList* movies, const Actor* actor);
void scanRolesFromMovie(RoleList* list, ActorList* actors, const Movie* movie);

void printRolesOfActor(const RoleList* list, const Actor* actor);
void printRolesFromMovie(const RoleList* list, const Movie* movie);
