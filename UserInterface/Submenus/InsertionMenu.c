#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/InsertionMenu.h"
#include "Utility/System.h"

static void insertNewActorIntoDatabase(ActorList* list);
static void insertNewMovieIntoDatabase(MovieList* list);
static void insertNewStudioIntoDatabase(StudioList* list);

static const MenuData INSERTION_MENU_DATA = {

    .content =
        "Wstaw:\n"
        "1) Nowego aktora [bez dodawania rol]\n"
        "2) Nowy film [bez dodawania rol]\n"
        "3) Nowe studio [bez dodawania filmow]\n"
        "4) Nowa rola [niedostepne]\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void insertionMenu(Database* database) {

    switch(playMenu(&INSERTION_MENU_DATA)) {

    case 1:
        insertNewActorIntoDatabase(&database->actors);
        break;

    case 2:
        insertNewMovieIntoDatabase(&database->movies);
        break;

    case 3:
        insertNewStudioIntoDatabase(&database->studios);
        break;

    case 4:
        // [niedostepne]
        break;

    }

}

void insertNewActorIntoDatabase(ActorList* list) {

    Actor newActor;
    scanActor(&newActor);

    if(!addActor(list, &newActor)) {
        printString("Taki aktor juz istnieje w bazie!\n");
        shortSleep();
    }

}


static void insertNewMovieIntoDatabase(MovieList* list) {

    Movie newMovie;
    scanMovie(&newMovie);

    if(!addMovie(list, &newMovie)) {
        printString("Taki film juz istnieje w bazie!\n");
        shortSleep();
    }

}

static void insertNewStudioIntoDatabase(StudioList* list) {

    Studio newStudio;
    scanStudio(&newStudio);

    if(!addStudio(list, &newStudio)) {
        printString("Takie studio juz istnieje w bazie!");
        shortSleep();
    }

}
