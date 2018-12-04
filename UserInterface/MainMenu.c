#include "UserInterface/MainMenu.h"
#include "UserInterface/MenuPlayer.h"

static bool isInputValid(int input);

static const MenuData MAIN_MENU_DATA = {

    .content =
        "Menu glowne:\n"
        "1) Dodaj...\n"
        "2) Usun...\n"
        "3) Wypisz dane o...\n"
        "4) Sortuj...\n"
        "5) Instrukcje [niedostepne]\n"
        "6) Wyjscie\n",

    .inputValidator = isInputValid

};

MainMenuResult mainMenu(void) {
    return playMenu(&MAIN_MENU_DATA);
}

bool isInputValid(int input) {
    return input >= 1 && input <= 7;
}
