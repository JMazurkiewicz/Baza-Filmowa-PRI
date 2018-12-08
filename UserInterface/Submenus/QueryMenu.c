#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/QueryMenu.h"
#include "Utility/System.h"

static void queryAboutActor(const Database* database);
static void queryAboutMovie(const Database* database);
static void queryAboutStudio(const Database* database);

static const MenuData QUERY_MENU_DATA = {

    .content =
        "Wypisz:\n"
        "1) Dane o aktorze\n"
        "2) Liste aktorow\n"
        "3) Dane o filmie\n"
        "4) Liste filmow\n"
        "5) Dane o studiu nagraniowym [bez wypisania filmow i aktorow]\n"
        "6) Liste studiow nagraniowych\n"
        "7) Rezygnuje...\n",

    .maxOptionValue = 7

};

void queryMenu(const Database* database) {

    const int option = playMenu(&QUERY_MENU_DATA);

    newLine();
    switch(option) {

    case 1:
        queryAboutActor(database);
        break;

    case 2:
        printActorList(&database->actors);
        break;

    case 3:
        queryAboutMovie(database);
        break;

    case 4:
        printMovieList(&database->movies);
        break;

    case 5:
        queryAboutStudio(database);
        break;

    case 6:
        printStudioList(&database->studios);
        break;

    case 7:
        return;

    }

    shortSleep();

}

void queryAboutActor(const Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    const Actor* actor = findActor(&database->actors, name, lastName);

    if(actor != NULL) {
        printActor(actor);
        printRolesOfActor(&database->roles, actor);
    } else {
        printString("Taki aktor nie istnieje!");
    }

}



void queryAboutMovie(const Database* database) {

    String title;
    scanMoviesTitle(title);

    const Movie* movie = findMovie(&database->movies, title);

    if(movie != NULL) {
        printMovie(movie);
        printRolesFromMovie(&database->roles, movie);
    } else {
        printString("Taki film nie istnieje!");
    }

}

void queryAboutStudio(const Database* database) {

    String name;
    scanStudiosName(name);

    const Studio* studio = findStudio(&database->studios, name);

    if(studio != NULL) {

        printStudio(studio);

    } else {
        printString("Takie studio nie istnieje!");
    }

}
