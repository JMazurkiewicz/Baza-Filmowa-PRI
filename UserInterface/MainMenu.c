#include <stdbool.h>
#include "UserInterface/MainMenu.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/DeletionMenu.h"
#include "UserInterface/Submenus/InsertionMenu.h"
#include "UserInterface/Submenus/Instructions.h"
#include "UserInterface/Submenus/QueryMenu.h"
#include "UserInterface/Submenus/SerializationMenus.h"
#include "UserInterface/Submenus/SortMenu.h"

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
        "6) Nowa baza\n"
        "7) Zapisz baze\n"
        "8) Zapisz baze jako...\n"
        "9) Wczytaj baze...\n"
        "------------------------------------\n"
        "10) Wyjscie\n",

    .maxOptionValue = 10

};
#include "Lists/Database.h"//@to remove
#include "CommonIO/BasicIO.h"//@to remove
void mainMenu(Database* database) {

    for(bool active = true; active; ) {

        int x = playMenu(&MAIN_MENU_DATA);
        printf("%s\n", (database->isModified?"TAK":"NIE"));
        waitForEnter();

        switch(x) {

        case 1:
            insertionMenu(database);
            break;

        case 2:
            deletionMenu(database);
            break;

        case 3:
            queryMenu(database);
            break;

        case 4:
            sortMenu(database);
            break;

        case 5:
            instructions();
            break;

        case 6:
            newDatabase(database);
            break;

        case 7:
            saveDatabaseToFile(database);
            break;

        case 8:
            saveDatabaseAs(database);
            break;

        case 9:
            loadDatabaseFromFile(database);
            break;

        case 10:
            active = false;
            break;

        }

    }

}
