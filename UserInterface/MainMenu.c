#include "UserInterface/MainMenu.h"
#include "UserInterface/MenuPlayer.h"

static const MenuData MAIN_MENU_DATA = {

    .content =
        "Menu glowne:\n"
        "1) Dodaj...\n"
        "2) Usun...\n"
        "3) Wypisz...\n"
        "4) Sortuj...\n"
        "5) Instrukcje\n"
        "6) Wyjscie\n",

    .maxOptionValue = 6

};

MainMenuResult mainMenu(void) {
    return playMenu(&MAIN_MENU_DATA);
}
