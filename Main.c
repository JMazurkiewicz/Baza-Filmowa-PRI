#include "Lists/Database.h"
#include <stdbool.h>
#include "UserInterface/MainMenu.h"
#include "UserInterface/Submenus/DeletionMenu.h"
#include "UserInterface/Submenus/InsertionMenu.h"
#include "UserInterface/Submenus/Instructions.h"
#include "UserInterface/Submenus/QueryMenu.h"
#include "UserInterface/Submenus/SortMenu.h"

int main(void) {

    Database database;
    initDatabase(&database);

    for(bool active = true; active; ) {

        switch(mainMenu()) {

        case MAIN_MENU_INSERT:
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
            instructions();
            break;

        case MAIN_MENU_EXIT:
            active = false;
            break;

        }

    }

    freeDatabase(&database);

}
