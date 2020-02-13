#include "CommonIO/BasicIO.h"
#include "Lists/Database.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Messages.h"

static void queryAboutActor(Database* database);
static void queryAboutMovie(Database* database);
static void queryAboutStudio(Database* database);
static void printEverything(Database* database);

static const MenuData QUERY_MENU_DATA = {

    .content =
        "Wypisz:\n"
        "1) Dane o konkretnym aktorze\n"
        "2) Liste aktorow\n"
        "3) Dane o konkretnym filmie\n"
        "4) Liste filmow\n"
        "5) Dane o konkretnym studiu nagraniowym\n"
        "6) Liste studiow nagraniowych\n"
        "7) Wszystkie listy\n"
        "8) Rezygnuje...\n",

    .maxOptionValue = 8

};

void queryMenu(Database* database) {

    switch(playMenu(&QUERY_MENU_DATA)) {

    case 1:
        queryAboutActor(database);
        break;

    case 2:
        newLine();
        printActorList(&database->actors);
        break;

    case 3:
        queryAboutMovie(database);
        break;

    case 4:
        newLine();
        printMovieList(&database->movies);
        break;

    case 5:
        queryAboutStudio(database);
        break;

    case 6:
        newLine();
        printStudioList(&database->studios);
        break;

    case 7:
        printEverything(database);
        break;

    case 8:
        return;

    }

    newLine();
    waitForEnter();

}

void queryAboutActor(Database* database) {

    if(!isActorListEmpty(&database->actors)) {

        String name, lastName;
        scanActorsFullName(name, lastName);

        const Actor* actor = findActor(&database->actors, name, lastName);

        if(actor != NULL) {
            newLine();
            printActor(actor);
            printRolesOfActor(&database->roles, actor);
        } else {
            printString(ACTOR_DOES_NOT_EXIST);
        }

    } else {

        printString(ACTOR_LIST_IS_EMPTY);
    
    }

}



void queryAboutMovie(Database* database) {

    if(!isMovieListEmpty(&database->movies)) {

        String title;
        scanMoviesTitle(title);

        const Movie* movie = findMovie(&database->movies, title);

        if(movie != NULL) {
            newLine();
            printMovie(movie);
            printRolesFromMovie(&database->roles, movie);
        } else {
            printString(MOVIE_DOES_NOT_EXIST);
        }

    } else {

        printString(MOVIE_LIST_IS_EMPTY);
    
    }

}

void queryAboutStudio(Database* database) {

    if(!isStudioListEmpty(&database->studios)) {

        String name;
        scanStudiosName(name);

        const Studio* studio = findStudio(&database->studios, name);

        if(studio != NULL) {
            newLine();
            printStudio(studio);
            printMoviesFromStudio(&database->movies, studio);
            printActorsWorkingWithStudio(&database->actors, &database->roles, studio);
        } else {
            printString(STUDIO_DOES_NOT_EXIST);
        }

    } else {

        printString(STUDIO_LIST_IS_EMPTY);
    
    }

}

static void printEverything(Database* database) {

    newLine();
    printActorList(&database->actors);

    newLine();
    printMovieList(&database->movies);

    newLine();
    printStudioList(&database->studios);

}
