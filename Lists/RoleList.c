#include "Lists/RoleList.h"
#include <stdlib.h>

bool addRole(RoleListNode* head, Actor* actor, Movie* movie) {

    if(findRole(head, actor, movie) != NULL) {
        return false;
    }

    RoleListNode* newHead = malloc(sizeof(RoleListNode));
    newHead->next = head;
    newHead->value.actor = actor;
    newHead->value.movie = movie;

    return true;

}

Role* findRole(RoleListNode* head, Actor* actor, Movie* movie) {

    for(RoleListNode* node = head; node != NULL; node = node->next) {

        if(hasRoleTheseParams(&node->value, actor, movie)) {
            return &node->value;
        }

    }

    return NULL;

}

void deleteRolesOf(RoleListNode* head, const Actor* actor) {

    RoleListNode* node = head;

    while(node != NULL) {

        if(node->value.actor == actor) {
            RoleListNode* const next = node->next;
            free(node);
            node = next;
        } else {
            node = node->next;
        }

    }

}

void deleteRolesIn(RoleListNode* head, const Movie* movie) {

    RoleListNode* node = head;

    while(node != NULL) {

        if(node->value.movie == movie) {
            RoleListNode* const next = node->next;
            free(node);
            node = next;
        } else {
            node = node->next;
        }

    }

}

void freeRoleListMemory(RoleListNode* head) {

    for(RoleListNode* node = head; node != NULL; ) {

        RoleListNode* const next = node->next;
        free(node);
        node = next;

    }

}
