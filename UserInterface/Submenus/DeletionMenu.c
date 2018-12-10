#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/DeletionMenu.h"

static void deleteActorFromDatabase(Database* database);
static void deleteMovieFromDatabase(Database* database);
static void deleteRoleFromDatabase(Database* database);
static void deleteStudioFromDatabase(Database* database);

static const MenuData DELETION_MENU_DATA = {

    .content =
        "Usun: \n"
        "1) Aktora [bez usuwania rol]\n"
        "2) Film [bez usuwania rol]\n"
        "3) Role [niedostepne]\n"
        "4) Studio [bez zerowania filmow]\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void deletionMenu(Database* database) {

    switch(playMenu(&DELETION_MENU_DATA)) {

    case 1:
        deleteActorFromDatabase(database);
        break;

    case 2:
        deleteMovieFromDatabase(database);
        break;

    case 3:
        deleteRoleFromDatabase(database);
        break;

    case 4:
        deleteStudioFromDatabase(database);
        break;

    }

}

static void deleteActorFromDatabase(Database* database) {

    if(isActorListEmpty(&database->actors)) {

        puts("Lista aktorow jest pusta!");
        waitForEnter();

    } else {

        String name, lastName;
        scanActorsFullName(name, lastName);

        if(deleteActor(&database->actors, name, lastName)) {

            // @todo Usuwanie ról tego aktora

        } else {

            puts("Taki aktor nie istnieje w bazie");
            waitForEnter();

        }

    }

}

static void deleteMovieFromDatabase(Database* database) {

    if(isMovieListEmpty(&database->movies)) {

        puts("Lista filmow jest pusta!");
        waitForEnter();

    } else {

        String title;
        scanMoviesTitle(title);

        if(deleteMovie(&database->movies, title)) {

            // @todo Usuwanie ról z tego filmu

        } else {

            puts("Taki film nie istnieje w bazie");
            waitForEnter();

        }

    }

}

static void deleteRoleFromDatabase(Database* database) {

    if(isRoleListEmpty(&database->roles)) {

        puts("Lista rol jest pusta!");
        waitForEnter();

    } else {

        // @todo Usuwanie jednej roli

    }

}

static void deleteStudioFromDatabase(Database* database) {

    if(isStudioListEmpty(&database->studios)) {

        puts("Lista studiow nagraniowych jest pusta!");
        waitForEnter();

    } else {

        String name;
        scanStudiosName(name);

        if(deleteStudio(&database->studios, name)) {

            // @todo Zerownie wskaźnika na studio w odpowiednich filmach.

        } else {

            puts("Taki film nie istnieje w bazie");
            waitForEnter();

        }

    }

}
