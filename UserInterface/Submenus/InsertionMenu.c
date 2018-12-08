#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/InsertionMenu.h"

static void insertNewActorIntoDatabase(ActorList* list);
static void insertNewMovieIntoDatabase(MovieList* list);
static void insertNewStudioIntoDatabase(StudioList* list);

static const MenuData INSERTION_MENU_DATA = {

    .content =
        "Wstaw:\n"
        "1) Nowego aktora [bez dodawania rol]\n"
        "2) Nowy film [bez dodawania rol]\n"
        "3) Nowe studio [bez dodawania filmow]\n"
        "4) Nowa role [niedostepne]\n"
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
    addActor(list, &newActor);
}


static void insertNewMovieIntoDatabase(MovieList* list) {
    Movie newMovie;
    scanMovie(&newMovie);
    addMovie(list, &newMovie);
}

static void insertNewStudioIntoDatabase(StudioList* list) {
    Studio newStudio;
    scanStudio(&newStudio);
    addStudio(list, &newStudio);
}
