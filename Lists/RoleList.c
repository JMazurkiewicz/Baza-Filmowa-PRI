#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/RoleList.h"
#include <stdlib.h>
#include "Utility/MovieLimits.h"

bool addRole(RoleListNode* head, const Actor* actor, const Movie* movie) {

    if(findRole(head, actor, movie) != NULL) {
        return false;
    }

    RoleListNode* newHead = malloc(sizeof(RoleListNode));
    newHead->next = head;
    newHead->value.actor = actor;
    newHead->value.movie = movie;

    return true;

}

Role* findRole(RoleListNode* head, const Actor* actor, const Movie* movie) {

    for(RoleListNode* node = head; node != NULL; node = node->next) {
        if(hasRoleTheseParams(&node->value, actor, movie)) {
            return &node->value;
        }
    }

    return NULL;

}

Role* findNextRoleOfActor(RoleListNode* head, const Actor* actor) {

    for(RoleListNode* node = head; node != NULL; node = node->next) {
        if(node->value.actor == actor) {
            return &node->value;
        }
    }

    return NULL;

}

Role* findNextRoleFromMovie(RoleListNode* head, const Movie* movie) {

    for(RoleListNode* node = head; node != NULL; node = node->next) {
        if(node->value.movie == movie) {
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

void scanRolesFromMovie(RoleListNode* head, const ActorListNode* actors, const Movie* movie) {

    printString("Ile rol chcesz dodac w tym filmie: ");
    int roleCount = scanIntegerFromRange(0, MAX_ROLE_COUNT);

    while(roleCount != 0) {

        String name, lastName;
        scanActorsFullName(name, lastName);

        const Actor* const actor = findActor(actors, name, lastName);

        if(actor != NULL) {
            addRole(head, actor, movie);
            printString("Pomyslnie dodano aktora");
            --roleCount;
        } else {
            printString("Taki aktor nie istnieje, sprobuj ponownie");
        }

    }

}

void scanRolesOfActor(RoleListNode* head, const MovieListNode* movies, const Actor* actor) {

    printString("Ile rol chcesz dodac dla tego aktora: ");
    int roleCount = scanIntegerFromRange(0, MAX_ROLE_COUNT);

    while(roleCount != 0) {

        String title;
        scanMoviesTitle(title);

        const Movie* const movie = findMovie(movies, title);

        if(movie != NULL) {
            addRole(head, actor, movie);
            printString("Pomyslnie dodano film");
            --roleCount;
        } else {
            printString("Taki film nie istnieje, sprobuj ponownie");
        }

    }

}

void printRolesOfActor(RoleListNode* head, const Actor* actor) {

    const Role* role = findNextRoleOfActor(head, actor);

    if(role != NULL) {

        do {
            printf(" \"%s\"\n", role->movie->title);
            role = findNextRoleOfActor(head->next, actor);
        } while(role != NULL);

    } else {
        puts("Aktor nie posiada zapisanych rol.");
    }

}

void printRolesFromMovie(RoleListNode* head, const Movie* movie) {

    const Role* role = findNextRoleFromMovie(head, movie);

    if(role != NULL) {

        do {
            printf(" \"%s %s\"\n", role->actor->name, role->actor->lastName);
            role = findNextRoleFromMovie(head->next, movie);
        } while(role != NULL);

    } else {
        puts("Film nie posiada zapisanych aktorow.");
    }

}

void freeRoleListMemory(RoleListNode* head) {

    for(RoleListNode* node = head; node != NULL; ) {
        RoleListNode* const next = node->next;
        free(node);
        node = next;
    }

}
