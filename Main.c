#include "Lists/Database.h"
#include "UserInterface/DeletionMenu.h"
#include "UserInterface/InsertionMenu.h"
#include "UserInterface/MainMenu.h"
#include "UserInterface/QueryMenu.h"
#include "UserInterface/SortMenu.h"

int main(void) {

    Database database;
    initDatabase(&database);

    while(true) {

        const MainMenuResult operation = mainMenu();

        switch(operation) {

        case MAIN_MENU_ADD:
            insertionMenu(&database);
            break;

        case MAIN_MENU_DELETE:
            deletionMenu(&database);
            break;

        case MAIN_MENU_QUERY:
            queryMenu(&database);
            break;

        case MAIN_MENU_SORT:
            sortMenu(&database);
            break;

        case MAIN_MENU_RULES:
            sortMenu(&database);
            break;

        case MAIN_MENU_EXIT:
            return 0;
            break;

        }

    }

    freeDatabaseMemory(&database);

}
