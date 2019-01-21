#include "Lists/Database.h"
#include <stdlib.h>
#include <time.h>
#include "UserInterface/MainMenu.h"
#include "UserInterface/Submenus/Backup.h"
#include "UserInterface/Submenus/SerializationMenus.h"

int main(void) {

    srand((unsigned)time(0));

    Database database;
    initDatabase(&database);
    backup(&database);

    mainMenu(&database);

    saveAtExit(&database);
    freeDatabase(&database);

}
