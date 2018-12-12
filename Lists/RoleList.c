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

Role* findRole(RoleList* list, const Actor* actor, const Movie* movie) {

    for(RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(hasRoleTheseMembers(&node->value, actor, movie)) {
            return &node->value;
        }

    }

    return NULL;

}

Role* findRoleOfActor(RoleList* list, const Actor* actor) {

    for(RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleOfActor(&node->value, actor)) {
            return &node->value;
        }

    }

    return NULL;

}

Role* findRoleFromMovie(RoleList* list, const Movie* movie) {

    for(RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleFromMovie(&node->value, movie)) {
            return &node->value;
        }

    }

    return NULL;

}

void deleteRole(const RoleList* list, const Actor* actor, const Movie* movie) {

    RoleListNode* previousElement = (RoleListNode*)list;
    RoleListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(hasRoleTheseMembers(&currentElement->value, actor, movie)) {

            previousElement->next = currentElement->next;
            free(currentElement);
            break;

        } else {

            previousElement = previousElement->next;
            currentElement = currentElement->next;

        }

    }

}

void deleteRolesOfActor(RoleList* list, const Actor* actor) {

    RoleListNode* previousElement = (RoleListNode*)list;
    RoleListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(isThisRoleOfActor(&currentElement->value, actor)) {

            previousElement->next = currentElement->next;
            free(currentElement);
            currentElement = previousElement->next;

        } else {

            previousElement = previousElement->next;
            currentElement = currentElement->next;

        }

    }

}

void deleteRolesFromMovie(RoleList* list, const Movie* movie) {

    RoleListNode* previousElement = (RoleListNode*)list;
    RoleListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(isThisRoleFromMovie(&currentElement->value, movie)) {

            previousElement->next = currentElement->next;
            free(currentElement);
            currentElement = previousElement->next;

        } else {

            previousElement = previousElement->next;
            currentElement = currentElement->next;

        }

    }

}
