#include "Lists/Database.h"
#include <stdlib.h>
#include <time.h>
#include "UserInterface/MainMenu.h"
#include "UserInterface/Submenus/SerializationMenus.h"

int main(void) {

    srand((unsigned)time(0));

    Database database;
    initDatabase(&database);

    mainMenu(&database);

    saveDatabaseIfModified(&database, "Czy chcesz zapisac baze przed opuszczeniem aplikacji");
    freeDatabase(&database);

}
