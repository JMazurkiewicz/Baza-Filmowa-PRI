#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/Deserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/FileSystem.h"
#include "UserInterface/Logo.h"
#include "UserInterface/Submenus/DeserializationMenu.h"

static size_t MAX_DATABASE_FILE_COUNT = 16;

static void displayMenu(String *const databaseFileNames, size_t countOfDatabaseFiles);
static bool isInputValidForDeserialization(int input, size_t countOfDatabaseFiles);

void deserializationMenu(Database* database) {

    String databaseFileNames[MAX_DATABASE_FILE_COUNT];
    const size_t databaseFileCount = getNamesOfDatabaseFiles(databaseFileNames, MAX_DATABASE_FILE_COUNT);

    displayMenu(databaseFileNames, databaseFileCount);

    printString("\nPodaj numer pliku, ktory chcesz wczytac: ");
    const int input = scanIntegerFromRange(1, databaseFileCount+1);

    if(isInputValidForDeserialization(input, databaseFileCount)) {
        deserializeDatabase(databaseFileNames[input-1], database);
    }

}

void displayMenu(String *const databaseFileNames, size_t countOfDatabaseFiles) {

    clearConsole();
    displayLogo();

    puts("Wczytaj baze danych (lub zrezygnuj):");

    int i = 0;
    while(i < countOfDatabaseFiles) {

        printf("%d) %s [", i+1, databaseFileNames[i]);
        const Date modificationDate = deserializeDate(databaseFileNames[i]);
        printDate(&modificationDate);
        puts("]");

        ++i;

    }

    printf("%d) Rezygnuje...\n", i+1);

}

bool isInputValidForDeserialization(int input, size_t countOfDatabaseFiles) {
    return 1 <= input && input <= countOfDatabaseFiles;
}
