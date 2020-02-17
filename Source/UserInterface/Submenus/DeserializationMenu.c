#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "DeserializationMenu.h"
#include "FileIO/Deserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/FileSystem.h"
#include "SerializationMenus.h"
#include "UserInterface/Logo.h"

#define MAX_DATABASE_FILE_COUNT (16)

static void displayMenu(String* fileNames, size_t databaseFileCount);
static void printMenuOption(int optionIndex, StringView fileName);
static int scanUsersChoice(size_t databaseFileCount);
static bool isInputValidForDeserialization(int input, size_t databaseFileCount);

void deserializationMenu(Database* database) {

    String fileNames[MAX_DATABASE_FILE_COUNT];
    const size_t fileCount = getNamesOfDatabaseFiles(fileNames, MAX_DATABASE_FILE_COUNT);

    displayMenu(fileNames, fileCount);
    const int input = scanUsersChoice(fileCount);

    if(isInputValidForDeserialization(input, fileCount)) {
        saveDatabaseIfModified(database, "Czy chcesz zapisac aktualna baze przed wczytaniem nowej");
        deserializeDatabase(fileNames[input-1], database);
    }

}

void displayMenu(String* fileNames, size_t databaseFileCount) {

    clearConsole();
    displayLogo();

    puts("Wczytaj baze danych (lub zrezygnuj):");

    int i = 0;
    for(; i < databaseFileCount; ++i) {
        printMenuOption(i, fileNames[i]);
    }

    printf("%d) Rezygnuje...\n", i+1);

}

void printMenuOption(int optionIndex, StringView fileName) {
    printf("%d) %s [", optionIndex+1, fileName);
    const Date modificationDate = deserializeDateFromFile(fileName);
    printDate(&modificationDate);
    puts("]");
}

int scanUsersChoice(size_t databaseFileCount) {
    printString("\nPodaj numer pliku, ktory chcesz wczytac: ");
    return scanBoundedInteger(1, (int)databaseFileCount+1);
}

bool isInputValidForDeserialization(int input, size_t databaseFileCount) {
    return 1 <= input && input <= databaseFileCount;
}
