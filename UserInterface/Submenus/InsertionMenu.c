#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/InsertionMenu.h"

static void insertNewActorIntoDatabase(Database* database);
static void insertNewMovieIntoDatabase(Database* database);
static void insertNewRoleIntoDatabase(Database* database);
static void insertNewStudioIntoDatabase(Database* database);

static const MenuData INSERTION_MENU_DATA = {

    .content =
        "Wstaw:\n"
        "1) Nowego aktora [bez dodawania rol]\n"
        "2) Nowy film [bez dodawania rol/studia]\n"
        "3) Nowa rola\n"
        "4) Nowe studio [bez dodawania filmow]\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void insertionMenu(Database* database) {

    switch(playMenu(&INSERTION_MENU_DATA)) {

    case 1:
        insertNewActorIntoDatabase(database);
        break;

    case 2:
        insertNewMovieIntoDatabase(database);
        break;

    case 3:
        insertNewRoleIntoDatabase(database);
        break;

    case 4:
        insertNewStudioIntoDatabase(database);
        break;

    }

}

void insertNewActorIntoDatabase(Database* database) {

    Actor newActor;
    scanActorsIdentifiers(&newActor);

    if(findActor(&database->actors, newActor.name, newActor.lastName) != NULL) {

        printString("Taki aktor juz istnieje w bazie!\n");
        waitForEnter();

    } else {

        scanActorsData(&newActor);
        // @todo Skanowanie ról dla aktora

        addActor(&database->actors, &newActor);

    }

}


static void insertNewMovieIntoDatabase(Database* database) {

    Movie newMovie;
    scanMoviesIdentifier(&newMovie);

    if(findMovie(&database->movies, newMovie.title) != NULL) {

        printString("Taki film juz istnieje w bazie!\n");
        waitForEnter();

    } else {

        scanMoviesData(&newMovie);
        // @todo Skanowanie studia
        // @todo Skanowanie ról
        addMovie(&database->movies, &newMovie);

    }

}

static void insertNewRoleIntoDatabase(Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    const Actor* actor = findActor(&database->actors, name, lastName);

    if(actor == NULL) {
        puts("Taki aktor nie istnieje w bazie!");
    } else {

        String title;
        scanMoviesTitle(title);

        const Movie* movie = findMovie(&database->movies, title);

        if(movie == NULL) {
            puts("Taki film nie istnieje w bazie!");
        } else {

            if(findRole(&database->roles, actor, movie) != NULL) {
                puts("Taka rola istnieje juz w bazie!");
            } else {
                addRole(&database->roles, actor, movie);
                return;
            }

        }

    }

    waitForEnter();

}

static void insertNewStudioIntoDatabase(Database* database) {

    Studio newStudio;
    scanStudiosIdentifier(&newStudio);

    if(findStudio(&database->studios, newStudio.name) != NULL) {

        printString("Takie studio juz istnieje w bazie!");
        waitForEnter();

    } else {

        scanStudiosData(&newStudio);
        // @todo Skanowanie tytułów filmów
        addStudio(&database->studios, &newStudio);

    }

}
