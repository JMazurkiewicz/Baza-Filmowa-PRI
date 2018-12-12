#include "Lists/Algo/Sort.h"
#include "Lists/StudioList.h"
#include <stddef.h>
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/SortMenu/StudioListSortMenu.h"
#include "Utility/String.h"

bool alphabeticalStudioNameCompare(const void* left, const void* right);
bool reversedAlphabeticalStudioNameCompare(const void* left, const void* right);
bool lessYearOfFoundingCompare(const void* left, const void* right);
bool greaterYearOfFoundingCompare(const void* left, const void* right);

static const MenuData STUDIO_LIST_SORT_MENU_DATA = {

    .content =
        "Wedlug jakiego kryterium chcesz posortowac tabele studiow nagraniowych?\n"
        "1) Wedlug nazw (w kolejnosci alfabetycznej)\n"
        "2) Wedlug nazw (w odwrotnej kolejnosci alfabetycznej)\n"
        "3) Wedlug roku powstania (rosnaco)\n"
        "4) Wedlug roku powstania (malejaco)\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void studioListSortMenu(StudioList* studios) {

    const size_t VALUE_OFFSET = offsetof(StudioListNode, value);

    switch(playMenu(&STUDIO_LIST_SORT_MENU_DATA)) {

    case 1:
        listSort(studios, VALUE_OFFSET, alphabeticalStudioNameCompare);
        break;

    case 2:
        listSort(studios, VALUE_OFFSET, reversedAlphabeticalStudioNameCompare);
        break;

    case 3:
        listSort(studios, VALUE_OFFSET, lessYearOfFoundingCompare);
        break;

    case 4:
        listSort(studios, VALUE_OFFSET, greaterYearOfFoundingCompare);
        break;

    }

}

bool alphabeticalStudioNameCompare(const void* left, const void* right) {

    const Studio* const leftStudio = left;
    const Studio* const rightStudio = right;

    return strCaseInsensitiveCompare(leftStudio->name, rightStudio->name) < 0;

}

bool reversedAlphabeticalStudioNameCompare(const void* left, const void* right) {
    return alphabeticalStudioNameCompare(right, left);
}

bool lessYearOfFoundingCompare(const void* left, const void* right) {

    const Studio* const leftStudio = left;
    const Studio* const rightStudio = right;

    return leftStudio->yearOfFounding < rightStudio->yearOfFounding;

}

bool greaterYearOfFoundingCompare(const void* left, const void* right) {
    return lessYearOfFoundingCompare(right, left);
}
