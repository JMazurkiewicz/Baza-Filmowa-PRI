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
        "2) Nowy film [bez dodawania rol/studia]\n"
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
    scanActorsIdentifiers(&newActor);

    if(findActor(list, newActor.name, newActor.lastName) != NULL) {

        printString("Taki aktor juz istnieje w bazie!\n");
        shortSleep();

    } else {

        scanActorsData(&newActor);
        addActor(list, &newActor);

    }

}


static void insertNewMovieIntoDatabase(MovieList* list) {

    Movie newMovie;
    scanMoviesIdentifier(&newMovie);

    if(findMovie(list, newMovie.title) != NULL) {

        printString("Taki film juz istnieje w bazie!\n");
        shortSleep();

    } else {

        scanMoviesData(&newMovie);
        addMovie(list, &newMovie);

    }

}

static void insertNewStudioIntoDatabase(StudioList* list) {

    Studio newStudio;
    scanStudiosIdentifier(&newStudio);

    if(findStudio(list, newStudio.name) != NULL) {

        printString("Takie studio juz istnieje w bazie!");
        shortSleep();

    } else {

        scanStudiosData(&newStudio);
        addStudio(list, &newStudio);

    }

}
