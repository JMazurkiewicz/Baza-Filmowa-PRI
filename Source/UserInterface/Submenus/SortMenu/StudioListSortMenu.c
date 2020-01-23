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

static const size_t VALUE_OFFSET = offsetof(StudioListNode, value);

bool studioListSortMenu(StudioList* studios) {

    CompareFunction compareFunction;

    switch(playMenu(&STUDIO_LIST_SORT_MENU_DATA)) {

    case 1:
        compareFunction = alphabeticalStudioNameCompare;
        break;

    case 2:
        compareFunction = reversedAlphabeticalStudioNameCompare;
        break;

    case 3:
        compareFunction = lessYearOfFoundingCompare;
        break;

    case 4:
        compareFunction = greaterYearOfFoundingCompare;
        break;

    case 5:
        return false;

    }

    return listSort(studios, VALUE_OFFSET, compareFunction);

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
