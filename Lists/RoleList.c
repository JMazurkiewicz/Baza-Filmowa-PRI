#include "Lists/RoleList.h"
#include <stdlib.h>

void initRoleList(RoleList* list) {
    list->head = NULL;
}

void freeRoleList(RoleList* list) {

    for(RoleListNode* node = list->head; node != NULL; ) {
        RoleListNode* const next = node->next;
        free(node);
        node = next;
    }

    initRoleList(list);

}

bool isRoleListEmpty(const RoleList* list) {
    return list->head == NULL;
}

void addRole(RoleList* list, const Actor* actor, const Movie* movie) {

    RoleListNode* newHead = malloc(sizeof(RoleListNode));
    newHead->next = list->head;
    newHead->value.actor = actor;
    newHead->value.movie = movie;

    list->head = newHead;

}

const Role* findRole(const RoleList* list, const Actor* actor, const Movie* movie) {

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(hasRoleTheseMembers(&node->value, actor, movie)) {
            return &node->value;
        }

    }

    return NULL;

}

const Role* findRoleOfActor(const RoleList* list, const Actor* actor) {

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(node->value.actor == actor) {
            return &node->value;
        }

    }

    return NULL;

}

const Role* findRoleFromMovie(const RoleList* list, const Movie* movie) {

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(node->value.movie == movie) {
            return &node->value;
        }

    }

    return NULL;

}

void deleteRolesOfActor(RoleList* list, const Actor* actor) {

    RoleListNode* node = list->head;

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

void deleteRolesFromMovie(RoleList* list, const Movie* movie) {

    RoleListNode* node = list->head;

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
