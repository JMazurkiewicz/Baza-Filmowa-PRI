#include "UserInterface/MainMenu.h"
#include "UserInterface/MenuPlayer.h"

static const MenuData MAIN_MENU_DATA = {

    .content =
        "Menu glowne:\n"
        "------------------------------------\n"
        "1) Dodaj...\n"
        "2) Usun...\n"
        "3) Wypisz...\n"
        "4) Sortuj...\n"
        "5) Instrukcje\n"
        "------------------------------------\n"
        "6) Zapisz baze\n"
        "7) Zapisz baze jako...\n"
        "8) Wczytaj baze...\n"
        "------------------------------------\n"
        "9) Wyjscie\n",

    .maxOptionValue = 9

};

MainMenuResult mainMenu(void) {
    return playMenu(&MAIN_MENU_DATA);
}
