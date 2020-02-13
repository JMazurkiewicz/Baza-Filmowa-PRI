#include "CommonIO/BasicIO.h"
#include "DeletionMenu.h"
#include "Lists/Database.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Messages.h"

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
        break;

    }

}

void deleteActorFromDatabase(Database* database) {

    if(isActorListEmpty(&database->actors)) {

        puts(ACTOR_LIST_IS_EMPTY);
        waitForEnter();

    } else {

        String name, lastName;
        scanActorsFullName(name, lastName);

        Actor* actor = findActor(&database->actors, name, lastName);

        if(actor != NULL) {
            deleteRolesOfActor(&database->roles, actor);
            deleteActor(&database->actors, name, lastName);
            database->isDatabaseModified = true;
        } else {
            puts(ACTOR_DOES_NOT_EXIST);
            waitForEnter();
        }

    }

}

void deleteMovieFromDatabase(Database* database) {

    if(isMovieListEmpty(&database->movies)) {

        puts(MOVIE_LIST_IS_EMPTY);
        waitForEnter();

    } else {

        String title;
        scanMoviesTitle(title);

        Movie* movie = findMovie(&database->movies, title);

        if(movie != NULL) {
            deleteRolesFromMovie(&database->roles, movie);
            deleteMovie(&database->movies, title);
            database->isDatabaseModified = true;
        } else {
            puts(MOVIE_DOES_NOT_EXIST);
            waitForEnter();
        }

    }

}

void deleteRoleFromDatabase(Database* database) {

    if(isRoleListEmpty(&database->roles)) {

        puts(ROLE_LIST_IS_EMPTY);
        waitForEnter();

    } else {

        Role roleToDelete;
        if(scanRole(&roleToDelete, database)) {

            if(findRole(&database->roles, roleToDelete.actor, roleToDelete.movie) != NULL) {
                deleteRole(&database->roles, roleToDelete.actor, roleToDelete.movie);
                database->isDatabaseModified = true;
            } else {
                puts(ROLE_DOES_NOT_EXIST);
                waitForEnter();
            }

        }

    }

}

void deleteStudioFromDatabase(Database* database) {

    if(isStudioListEmpty(&database->studios)) {

        puts(STUDIO_LIST_IS_EMPTY);
        waitForEnter();

    } else {

        String name;
        scanStudiosName(name);

        Studio* studio = findStudio(&database->studios, name);

        if(studio != NULL) {
            removeStudioFromMovieList(&database->movies, studio);
            deleteStudio(&database->studios, name);
            database->isDatabaseModified = true;
        } else {
            puts(STUDIO_DOES_NOT_EXIST);
            waitForEnter();
        }

    }

}
