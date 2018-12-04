#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/DeletionMenu.h"

static bool isInputValid(int input);

static const MenuData DELETION_MENU_DATA = {

    .content =
        "Usun: \n"
        "1) Aktora [niedostepne]\n"
        "2) Film [niedostepne]\n"
        "3) Studio [niedostepne]\n"
        "4) Role [niedostepne]\n",

    .inputValidator = isInputValid

};

void deletionMenu(Database* database) {

    switch(playMenu(&DELETION_MENU_DATA)) {

    case 1:
        // [niedostepne]
        break;

    case 2:
        // [niedostepne]
        break;

    case 3:
        // [niedostepne]
        break;

    case 4:
        // [niedostepne]
        break;

    }

}

bool isInputValid(int input) {
    return input >= 1 && input <= 4;
}
