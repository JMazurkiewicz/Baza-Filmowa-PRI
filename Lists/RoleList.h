#pragma once

#include "Lists/Declarations.h"
#include "Lists/IO/RoleListIO.h"
#include "Objects/Role.h"

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

const Role* findRole(const RoleList* list, const Actor* actor, const Movie* movie);
const Role* findRoleOfActor(const RoleList* list, const Actor* actor);
const Role* findRoleFromMovie(const RoleList* list, const Movie* movie);

void deleteRolesOfActor(RoleList* list, const Actor* actor);
void deleteRolesFromMovie(RoleList* list, const Movie* movie);
