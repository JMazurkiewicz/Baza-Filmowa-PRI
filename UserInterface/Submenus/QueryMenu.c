#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/QueryMenu.h"

static bool isInputValid(int input);

static const MenuData QUERY_MENU_DATA = {

    .content =
        "O kim chcesz uzyskac wypis:\n"
        "1) O aktorze [niedostepne]\n"
        "2) O filmie [niedostepne]\n"
        "3) O studiu nagraniowym [niedostepne]\n",

    .inputValidator = isInputValid

};

void queryMenu(Database* database) {

    switch(playMenu(&QUERY_MENU_DATA)) {

    case 1:
        // [niedostepne]
        break;

    case 2:
        // [niedostepne]
        break;

    case 3:
        // [niedostepne]
        break;

    }

}

bool isInputValid(int input) {
    return input >= 1 && input <= 3;
}
