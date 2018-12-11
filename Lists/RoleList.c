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

        if(isThisRoleOfActor(&node->value, actor)) {
            return &node->value;
        }

    }

    return NULL;

}

const Role* findRoleFromMovie(const RoleList* list, const Movie* movie) {

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleFromMovie(&node->value, movie)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteRole(const RoleList* list, const Actor* actor, const Movie* movie) {

    // @todo

    return false;

}

void deleteRolesOfActor(RoleList* list, const Actor* actor) {

    // @todo

}

void deleteRolesFromMovie(RoleList* list, const Movie* movie) {

    // @todo

}
