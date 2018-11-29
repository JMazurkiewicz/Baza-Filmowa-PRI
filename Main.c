#include <stdbool.h>

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

        const MainMenuResult operation = MainMenu();

        switch(operation) {

        case OPTION_ADD:
            InsertionMenu(&database);
            break;

        case OPTION_DELETE:
            DeletionMenu(&database);
            break;

        case OPTION_QUERY:
            QueryMenu(&database);
            break;
  
        case OPTION_SORT:
            SortMenu(&database);
            break;

        case OPTION_SAVE_TO_FILE:
            // [not available]
            break;

        case OPTION_LOAD_FROM_FILE:
            // [not available]
            break;

        case OPTION_EXIT:
            return 0;
            break;

        }

    }

    freeDatabaseMemory(&database);

}
