#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/SortMenu.h"

static const MenuData SORT_MENU_DATA = {

    .content =
        "Ktora tabele chcesz posortowac:\n"
        "1) Aktorow [niedostepne]\n"
        "2) Filmow [niedostepne]\n"
        "3) Studiow nagraniowych [niedostepne]\n"
        "4) Rezygnuje...\n",

    .maxOptionValue = 4

};

void sortMenu(Database* database) {

    switch(playMenu(&SORT_MENU_DATA)) {

    case 1:
        // [not available]
        break;

    case 2:
        // [not available]
        break;

    case 3:
        // [not available]
        break;

    }

}
