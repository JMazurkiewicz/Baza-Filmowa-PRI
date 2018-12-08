#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/QueryMenu.h"
#include "Utility/System.h"

static void queryForActor(const Database* database);
static void queryForMovie(const Database* database);
static void queryForStudio(const Database* database);

static const MenuData QUERY_MENU_DATA = {

    .content =
        "O kim chcesz uzyskac wypis:\n"
        "1) O aktorze [bez wypisania rol]\n"
        "2) O filmie [bez wypisania rol]\n"
        "3) O studiu nagraniowym [bez wypisania filmow i aktorow]\n"
        "4) Rezygnuje...\n",

    .maxOptionValue = 4

};

void queryMenu(const Database* database) {

    switch(playMenu(&QUERY_MENU_DATA)) {

    case 1:
        queryForActor(database);
        break;

    case 2:
        queryForMovie(database);
        break;

    case 3:
        queryForStudio(database);

    }

}

static void queryForActor(const Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    const Actor* actor = findActor(&database->actors, name, lastName);

    if(actor != NULL) {
        printActor(actor);
        printRolesOfActor(&database->roles, actor);
    } else {
        printString("Taki aktor nie istnieje!");
    }

    shortSleep();

}

static void queryForMovie(const Database* database) {

    String title;
    scanMoviesTitle(title);

    const Movie* movie = findMovie(&database->movies, title);

    if(movie != NULL) {
        printMovie(movie);
        printRolesFromMovie(&database->roles, movie);
    } else {
        printString("Taki film nie istnieje!");
    }

    shortSleep();

}

static void queryForStudio(const Database* database) {

    String name;
    scanStudiosName(name);

    const Studio* studio = findStudio(&database->studios, name);

    if(studio != NULL) {

        printStudio(studio);
        // + drukowanie filmów i studia

    } else {
        printString("Takie studio nie istnieje!");
    }

    shortSleep();

}
