#pragma once

#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include "Objects/Role.h"

typedef struct RoleListNode {

    struct RoleListNode* next;
    Role value;

} RoleListNode;

bool addRole(RoleListNode* head, Actor* actor, Movie* movie);
Role* findRole(RoleListNode* head, Actor* actor, Movie* movie);

void deleteRolesOf(RoleListNode* head, Actor* actor);
void deleteRolesIn(RoleListNode* head, Movie* movie);

void freeRoleListMemory(RoleListNode* head);
