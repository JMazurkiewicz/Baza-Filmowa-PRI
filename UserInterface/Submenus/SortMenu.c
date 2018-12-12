#include "CommonIO/BasicIO.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/SortMenu.h"
#include "UserInterface/Submenus/SortMenu/ActorListSortMenu.h"
#include "UserInterface/Submenus/SortMenu/MovieListSortMenu.h"
#include "UserInterface/Submenus/SortMenu/StudioListSortMenu.h"

static void actorListSort(ActorList* actors);
static void movieListSort(MovieList* movies);
static void studioListSort(StudioList* studios);

static const MenuData SORT_MENU_DATA = {

    .content =
        "Ktora tabele chcesz posortowac:\n"
        "1) Aktorow\n"
        "2) Filmow\n"
        "3) Studiow nagraniowych\n"
        "4) Rezygnuje...\n",

    .maxOptionValue = 4

};

void sortMenu(Database* database) {

    switch(playMenu(&SORT_MENU_DATA)) {

    case 1:
        actorListSort(&database->actors);
        break;

    case 2:
        movieListSort(&database->movies);
        break;

    case 3:
        studioListSort(&database->studios);
        break;

    }

}

void actorListSort(ActorList* actors) {

    if(isActorListEmpty(actors)) {
        puts("Lista aktorow jest pusta!");
        waitForEnter();
    } else {
        actorListSortMenu(actors);
    }

}

void movieListSort(MovieList* movies) {

    if(isMovieListEmpty(movies)) {
        puts("Lista filmow jest pusta!");
        waitForEnter();
    } else {
        movieListSortMenu(movies);
    }

}

void studioListSort(StudioList* studios) {

    if(isStudioListEmpty(studios)) {
        puts("Lista studiow nagraniowych jest pusta!");
        waitForEnter();
    } else {
        studioListSortMenu(studios);
    }

}
