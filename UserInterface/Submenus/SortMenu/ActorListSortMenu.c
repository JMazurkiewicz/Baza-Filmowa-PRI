#include "Lists/ActorList.h"
#include "Lists/Algo/Sort.h"
#include <stddef.h>
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/SortMenu/ActorListSortMenu.h"
#include "Utility/String.h"

bool alphabeticalLastNameCompare(const void* left, const void* right);
bool reversedAlphabeticalLastNameCompare(const void* left, const void* right);
bool alphabeticalNameCompare(const void* left, const void* right);
bool reversedAlphabeticalNameCompare(const void* left, const void* right);

static const MenuData ACTOR_LIST_SORT_MENU_DATA = {

    .content =
        "Wedlug jakiego kryterium chcesz posortowac tabele aktorow?\n"
        "1) Wedlug nazwisk (w kolejnosci alfabetycznej)\n"
        "2) Wedlug nazwisk (w odwrotnej kolejnosci alfabetycznej)\n"
        "3) Wedlug imion (w kolejnosci alfabetycznej)\n"
        "4) Wedlug imion (w odwrotnej kolejnosci alfabetycznej)\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

void actorListSortMenu(ActorList* actors) {

    const size_t VALUE_OFFSET = offsetof(ActorListNode, value);

    switch(playMenu(&ACTOR_LIST_SORT_MENU_DATA)) {

    case 1:
        listSort(actors, VALUE_OFFSET, alphabeticalLastNameCompare);
        break;

    case 2:
        listSort(actors, VALUE_OFFSET, reversedAlphabeticalLastNameCompare);
        break;

    case 3:
        listSort(actors, VALUE_OFFSET, alphabeticalNameCompare);
        break;

    case 4:
        listSort(actors, VALUE_OFFSET, reversedAlphabeticalNameCompare);
        break;

    }

}

bool alphabeticalLastNameCompare(const void* left, const void* right) {

    const Actor* const leftActor = left;
    const Actor* const rightActor = right;

    const int lastNameCmp = strcmp(leftActor->lastName, rightActor->lastName);

    if(lastNameCmp != 0) {
        return lastNameCmp < 0;
    }

    return strcmp(leftActor->name, rightActor->name) < 0;

}

bool reversedAlphabeticalLastNameCompare(const void* left, const void* right) {
    return alphabeticalNameCompare(right, left);
}

bool alphabeticalNameCompare(const void* left, const void* right) {

    const Actor* const leftActor = left;
    const Actor* const rightActor = right;

    const int nameCmp = strcmp(leftActor->name, rightActor->name);

    if(nameCmp != 0) {
        return nameCmp < 0;
    }

    return strcmp(leftActor->lastName, rightActor->lastName) < 0;

}

bool reversedAlphabeticalNameCompare(const void* left, const void* right) {
    return alphabeticalNameCompare(right, left);
}
