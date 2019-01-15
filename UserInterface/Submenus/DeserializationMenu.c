#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/FileSystem.h"
#include "UserInterface/Logo.h"
#include "UserInterface/Submenus/DeserializationMenu.h"

static size_t MAX_DATABASE_FILE_COUNT = 16;

static void displayMenu(String *const dbNames, size_t countOfDbNames);

void deserializationMenu(Database* database) {

    String dbFileNames[MAX_DATABASE_FILE_COUNT];
    const size_t dbFileCount = getNamesOfDatabaseFiles(dbFileNames, MAX_DATABASE_FILE_COUNT);

    displayMenu(dbFileNames, dbFileCount);

    // const int input = scanIntegerFromRange(1, dbFileCount+1);
    // deserializeDatabase(dbFileCount[input], database);
    waitForEnter();

}

void displayMenu(String *const dbFileNames, size_t countOfDbNames) {

    clearConsole();
    displayLogo();

    puts("Wczytaj baze danych (lub zrezygnuj):");

    int i = 0;
    while(i < countOfDbNames) {

        printf("%d) %s\n", i+1, dbFileNames[i]);
        ++i;

    }

    printf("%d) Rezygnuje...\n", i+1);

}
