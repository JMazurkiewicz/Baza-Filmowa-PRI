#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/ActorList.h"
#include "Lists/IO/RoleListIO.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"

void scanRolesFromMovie(RoleList* list, const ActorList* actors, const Movie* movie) {



}

void scanRolesOfActor(RoleList* list, const MovieList* movies, const Actor* actor) {



}

void printRolesOfActor(const RoleList* list, const Actor* actor) {

    bool noResults = true;

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleOfActor(&node->value, actor)) {

            if(noResults) {
                noResults = false;
                puts("Lista filmow tego aktora:");
            }

            putchar(' ');
            printMoviesTitle(node->value.movie);
            newLine();

        }

    }

    if(noResults) {
        puts("Aktor nie posiada rol w filmach.");
    }

}

void printRolesFromMovie(const RoleList* list, const Movie* movie) {

    bool noResults = true;

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleFromMovie(&node->value, movie)) {

            if(noResults) {
                noResults = false;
                puts("Aktorzy bioracy udzial w filmie:");
            }

            putchar(' ');
            printActorsFullName(node->value.actor);
            newLine();

        }

    }

    if(noResults) {
        puts("Film nie posiada zapisanych aktorow.");
    }

}
