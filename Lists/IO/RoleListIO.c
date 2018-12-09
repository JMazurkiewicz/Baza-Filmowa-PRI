#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/ActorList.h"
#include "Lists/IO/RoleListIO.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include "Utility/MovieLimits.h"

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
