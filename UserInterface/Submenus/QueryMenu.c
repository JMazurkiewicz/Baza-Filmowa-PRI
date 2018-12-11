#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/QueryMenu.h"

static void queryAboutActor(Database* database);
static void queryAboutMovie(Database* database);
static void queryAboutStudio(Database* database);

static const MenuData QUERY_MENU_DATA = {

    .content =
        "Wypisz:\n"
        "1) Dane o konkretnym aktorze\n"
        "2) Liste aktorow\n"
        "3) Dane o konkretnym filmie\n"
        "4) Liste filmow\n"
        "5) Dane o konkretnym studiu nagraniowym\n"
        "6) Liste studiow nagraniowych\n"
        "7) Rezygnuje...\n",

    .maxOptionValue = 7

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
        return;

    }

    newLine();
    waitForEnter();

}

void queryAboutActor(Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    const Actor* actor = findActor(&database->actors, name, lastName);

    if(actor != NULL) {

        newLine();
        printActor(actor);
        printRolesOfActor(&database->roles, actor);

    } else {

        printString("Taki aktor nie istnieje!");

    }

}



void queryAboutMovie(Database* database) {

    String title;
    scanMoviesTitle(title);

    const Movie* movie = findMovie(&database->movies, title);

    if(movie != NULL) {

        newLine();
        printMovie(movie);
        printRolesFromMovie(&database->roles, movie);

    } else {

        printString("Taki film nie istnieje!");

    }

}

void queryAboutStudio(Database* database) {

    String name;
    scanStudiosName(name);

    const Studio* studio = findStudio(&database->studios, name);

    if(studio != NULL) {

        newLine();
        printStudio(studio);
        printMoviesFromStudio(&database->movies, studio);
        printActorsWorkingWithStudio(&database->actors, &database->roles, studio);

    } else {

        printString("Takie studio nie istnieje!");

    }

}
