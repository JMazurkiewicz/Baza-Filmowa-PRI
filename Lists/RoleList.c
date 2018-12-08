#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/RoleList.h"
#include <stdlib.h>
#include "Utility/MovieLimits.h"

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

bool addRole(RoleList* list, const Actor* actor, const Movie* movie) {

    if(findRole(list, actor, movie) != NULL) {
        return false;
    }

    RoleListNode* newHead = malloc(sizeof(RoleListNode));
    newHead->next = list->head;
    newHead->value.actor = actor;
    newHead->value.movie = movie;

    list->head = newHead;
    return true;

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

void scanRolesFromMovie(RoleList* list, const ActorList* actors, const Movie* movie) {

    printString("Ile rol chcesz dodac w tym filmie: ");
    int roleCount = scanIntegerFromRange(0, MAX_ROLE_COUNT);

    while(roleCount != 0) {

        String name, lastName;
        scanActorsFullName(name, lastName);

        const Actor* const actor = findActor(actors, name, lastName);

        if(actor != NULL) {
            addRole(list, actor, movie);
            printString("Pomyslnie dodano aktora");
            --roleCount;
        } else {
            printString("Taki aktor nie istnieje, sprobuj ponownie");
        }

    }

}

void scanRolesOfActor(RoleList* list, const MovieList* movies, const Actor* actor) {

    printString("Ile rol chcesz dodac dla tego aktora: ");
    int roleCount = scanIntegerFromRange(0, MAX_ROLE_COUNT);

    while(roleCount != 0) {

        String title;
        scanMoviesTitle(title);

        const Movie* const movie = findMovie(movies, title);

        if(movie != NULL) {
            addRole(list, actor, movie);
            printString("Pomyslnie dodano film");
            --roleCount;
        } else {
            printString("Taki film nie istnieje, sprobuj ponownie");
        }

    }

}

void printRolesOfActor(const RoleList* list, const Actor* actor) {

    const Role* role = findRoleOfActor(list, actor);

    if(role != NULL) {

        do {
            printf(" \"%s\"\n", role->movie->title);
            role = findRoleOfActor(list, actor);
        } while(role != NULL);

    } else {
        puts("Aktor nie posiada zapisanych rol.");
    }

}

void printRolesFromMovie(const RoleList* list, const Movie* movie) {

    const Role* role = findRoleFromMovie(list, movie);

    if(role != NULL) {

        do {
            printf(" \"%s %s\"\n", role->actor->name, role->actor->lastName);
            role = findRoleFromMovie(list, movie);
        } while(role != NULL);

    } else {
        puts("Film nie posiada zapisanych aktorow.");
    }

}
