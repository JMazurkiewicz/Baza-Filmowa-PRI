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
        "1) Aktora\n"
        "2) Film\n"
        "3) Role\n"
        "4) Studio\n"
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

    }

}

static void deleteActorFromDatabase(Database* database) {

    if(isActorListEmpty(&database->actors)) {

        puts("\aLista aktorow jest pusta!");
        waitForEnter();

    } else {

        String name, lastName;
        scanActorsFullName(name, lastName);

        Actor* actor = findActor(&database->actors, name, lastName);
        if(actor != NULL) {

            deleteRolesOfActor(&database->roles, actor);
            deleteActor(&database->actors, name, lastName);

        } else {

            puts("\aTaki aktor nie istnieje w bazie!");
            waitForEnter();

        }

    }

}

static void deleteMovieFromDatabase(Database* database) {

    if(isMovieListEmpty(&database->movies)) {

        puts("\aLista filmow jest pusta!");
        waitForEnter();

    } else {

        String title;
        scanMoviesTitle(title);

        Movie* movie = findMovie(&database->movies, title);
        if(movie != NULL) {

            deleteRolesFromMovie(&database->roles, movie);
            deleteMovie(&database->movies, title);

        } else {

            puts("\aTaki film nie istnieje w bazie");
            waitForEnter();

        }

    }

}

static void deleteRoleFromDatabase(Database* database) {

    if(isRoleListEmpty(&database->roles)) {

        puts("\aLista rol jest pusta!");

    } else {

        Role roleToDelete;

        if(scanRoleFromDatabase(&roleToDelete, database)) {

            if(findRole(&database->roles, roleToDelete.actor, roleToDelete.movie) != NULL) {

                deleteRole(&database->roles, roleToDelete.actor, roleToDelete.movie);
                return;

            } else {

                puts("\aTaka rola nie istnieje w bazie!");

            }

        }

    }
    waitForEnter();

}

static void deleteStudioFromDatabase(Database* database) {

    if(isStudioListEmpty(&database->studios)) {

        puts("\aLista studiow nagraniowych jest pusta!");
        waitForEnter();

    } else {

        String name;
        scanStudiosName(name);

        Studio* studio = findStudio(&database->studios, name);
        if(studio != NULL) {

            removeStudioFromMovieList(&database->movies, studio);
            deleteStudio(&database->studios, name);

        } else {

            puts("\aTaki film nie istnieje w bazie");
            waitForEnter();

        }

    }

}
