#include "CommonIO/BasicIO.h"
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

void deleteRolesOfActor(RoleListNode* head, const Actor* actor) {

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

void deleteRolesFromMovie(RoleListNode* head, const Movie* movie) {

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

void scanActorsForMovie(RoleListNode* head, const ActorListNode* actors, Movie* movie) {
    // @todo
}

void scanMoviesForActor(RoleListNode* head, const MovieListNode* movies, Actor* actor) {
    // @todo
}

void printRolesOfActor(RoleListNode* head, const Actor* actor) {
    // @todo
}

void printRolesFromMovie(RoleListNode* head, const Movie* movie) {
    // @todo
}

void freeRoleListMemory(RoleListNode* head) {

    for(RoleListNode* node = head; node != NULL; ) {
        RoleListNode* const next = node->next;
        free(node);
        node = next;
    }

}
