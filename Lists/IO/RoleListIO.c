#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Objects/Movie.h"
#include "Utility/String.h"

static const StringView TRY_AGAIN = "Czy chcesz sprobowac ponownie (T/N): ";

void scanRolesOfActor(RoleList* roles, const MovieList* movies, const Actor* actor) {

    printString("Czy chcesz dodac role aktorowi (T/N): ");

    while(scanBoolean()) {

        String title;
        scanMoviesTitle(title);

        const Movie* const movie = findMovie(movies, title);

        if(movie == NULL) {
            puts("Taki film nie istnieje w bazie!");
            printString(TRY_AGAIN);
        } else {

            if(findRole(roles, actor, movie) != NULL) {
                puts("Aktor posiada juz taka role!");
                printString(TRY_AGAIN);
            } else {
                addRole(roles, actor, movie);
                printString("Czy chcesz dodac kolejna role aktorowi (T/N): ");
            }

        }

    }

}

void scanRolesFromMovie(RoleList* roles, const ActorList* actors, const Movie* movie) {

    printString("Czy chcesz dodac aktora do filmu (T/N): ");

    while(scanBoolean()) {

        String name, lastName;
        scanActorsFullName(name, lastName);

        const Actor* const actor = findActor(actors, name, lastName);

        if(actor == NULL) {
            puts("Taki aktor nie istnieje w bazie!");
            printString(TRY_AGAIN);
        } else {

            if(findRole(roles, actor, movie) != NULL) {
                puts("Film posiada juz takiego aktora!");
                printString(TRY_AGAIN);
            } else {
                addRole(roles, actor, movie);
                printString("Czy chcesz dodac kolejnego aktora do filmu (T/N): ");
            }

        }

    }

}

void printRolesOfActor(const RoleList* list, const Actor* actor) {

    bool noResults = true;

    for(const RoleListNode* node = list->head; node != NULL; node = node->next) {

        if(isThisRoleOfActor(&node->value, actor)) {

            if(noResults) {
                noResults = false;
                puts("Lista filmow tego aktora:");
            }

            printString("- ");
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

            printString("- ");
            printActorsFullName(node->value.actor);
            newLine();

        }

    }

    if(noResults) {
        puts("Film nie posiada zapisanych aktorow.");
    }

}
