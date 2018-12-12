#include "Lists/MovieList.h"
#include "Lists/Algo/Sort.h"
#include <stddef.h>
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/SortMenu/MovieListSortMenu.h"
#include "Utility/String.h"

bool alphabeticalTitleCompare(const void* left, const void* right);
bool reversedAlphabeticalTitleCompare(const void* left, const void* right);
bool lessRunningTimeCompare(const void* left, const void* right);
bool greaterRunningTimeCompare(const void* left, const void* right);

static const MenuData MOVIE_LIST_SORT_MENU_DATA = {

    .content =
        "Wedlug jakiego kryterium chcesz posortowac tabele filmy?\n"
        "1) Wedlug tytulow (w kolejnosci alfabetycznej)\n"
        "2) Wedlug tytulow (w odwrotnej kolejnosci alfabetycznej)\n"
        "3) Wedlug czasu trwania (rosnaco)\n"
        "4) Wedlug czasu trwania (malejaco)\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void movieListSortMenu(MovieList* movies) {

    const size_t VALUE_OFFSET = offsetof(MovieListNode, value);

    switch(playMenu(&MOVIE_LIST_SORT_MENU_DATA)) {

    case 1:
        listSort(movies, VALUE_OFFSET, alphabeticalTitleCompare);
        break;

    case 2:
        listSort(movies, VALUE_OFFSET, reversedAlphabeticalTitleCompare);
        break;

    case 3:
        listSort(movies, VALUE_OFFSET, lessRunningTimeCompare);
        break;

    case 4:
        listSort(movies, VALUE_OFFSET, greaterRunningTimeCompare);
        break;

    }

}

bool alphabeticalTitleCompare(const void* left, const void* right) {

    const Movie* const leftMovie = left;
    const Movie* const rightMovie = right;

    return strcmp(leftMovie->title, rightMovie->title) < 0;

}

bool reversedAlphabeticalTitleCompare(const void* left, const void* right) {
    return alphabeticalTitleCompare(right, left);
}

bool lessRunningTimeCompare(const void* left, const void* right) {

    const Movie* const leftMovie = left;
    const Movie* const rightMovie = right;

    return leftMovie->runningTime < rightMovie->runningTime;

}

bool greaterRunningTimeCompare(const void* left, const void* right) {
    return lessRunningTimeCompare(right, left);
}
